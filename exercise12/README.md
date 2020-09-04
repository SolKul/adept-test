# Make your own odeint

boost::odeintはテンプレートを使い、様々な型(クラス)で常微分方程式の初期値問題を解けるが、残念ながら、陰解法を使う場合はboost::ublasを使わなくてはならない。  
自動微分するためにadeptのArrayで数値積分するにはodeintを自作しなければならない。  
ここではその一歩として、まずは単純なオイラー法を自作する  

可能な限りboost::odeintの使用に合わせる

## Make your own Stepper class

StepperクラスCRTPという設計思想で実装されている。  
https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern


Stepperは`do_step`を持つ

`do_step`
```c++
void do_step(system , 状態 , 時刻 , 刻み幅 )
```

そしてその具体的な実装は`do_step_impl`で行われれる。

`do_step_impl`
```c++
void do_step_impl( System /* system */ , const 現在状態 , const dxdt , time_type /* t */ , 次回状態 , 刻み幅 )
```

## Make your own integrate_const class