#include <iostream>
#include<string>

template<typename T1>
class TemplateClass{
public:
  template<typename T2>
  void func(){}
};

template<typename T3>
void TemplateFunc(){
  TemplateClass<T3> t;
  t.template func<int>();
  // t.func<int>();だとエラー
};

int main() {
  TemplateFunc<int>();
}
