#include <vector>
#include <array>
#include <fstream>

namespace mylib{

struct LVSystem{
public:
  using state_type = std::array<double, 2>;
public:
  static const int variable_num=2;
  double alpha;
  double beta;
  double gamma;
  double delta;
public:
  LVSystem(double alpha_,double beta_,double gamma_,double delta_);
  void operator()(const state_type& x, state_type& dx, double t);
};

// 用意したベクトルに結果を保存するObserver
template<typename state_type> struct Observer
{
    std::vector< state_type >& m_states;
    std::vector< double >& m_times;

    Observer( std::vector< state_type > &states , std::vector< double > &times )
    : m_states( states ) , m_times( times ) { }

    void operator()( const state_type &x , double t )
    {
        m_states.push_back( x );
        m_times.push_back( t );
    }
};

//csv形式で軌道を記録するobserver
template<typename state_type> struct CSVObserver{
    std::ofstream fout;
    CSVObserver(const std::string& FileName) :fout(FileName){};
    //ここで記録方法を定義する
    void operator()(const state_type& x, double t){
        fout << t << "," << x[0] << "," << x[1] << std::endl;
    }
};

// オイラー法の自作Stepper
template<class state_type>
struct euler{
public:
  // 次の状態を計算する
  template<class System>
  void do_step(
      System system ,
      state_type &x ,
      double t,
      double dt ){
    // dxdtを計算
    system(x,m_dxdt,t);
    do_step_impl<System>(
      system,
      x,
      m_dxdt,
      t,
      x,
      dt
    );
  }
private:
  state_type m_dxdt;
  // 次の状態計算の実装
  template<class System>
  void do_step_impl(
      System /*system*/ ,
      const state_type &in ,
      const state_type dxdt,
      double /*t*/,
      state_type &out ,
      double dt ){
    for(std::size_t i = 0; i < in.end() - in.begin(); ++i){
      out[i]=in[i]+dxdt[i]*dt;
    }
  }
};

// 一定刻み幅で積分する
template<
  class Stepper ,
  class System ,
  class State ,
  class Time ,
  class Observer >
std::size_t integrate_const(
  Stepper stepper ,
  System system ,
  State &start_state ,
  Time start_time ,
  Time end_time ,
  Time dt ,
  Observer observer
)
{
    Time time = start_time;
    int step = 0;
    // cast time+dt explicitely in case of expression templates (e.g. multiprecision)
    while( end_time-time >= 0 )
    {
        observer( start_state , time );
        stepper.template do_step<System>( system , start_state , time , dt );
        ++step;
        time = start_time + step * dt;
    }
    observer( start_state , time );

    return step;
};

}//mylib