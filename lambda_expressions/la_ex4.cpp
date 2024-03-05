//создаем сложные предикаты с помощью логической конъюнкции

#include <iostream>
#include <iterator>
#include <string>
#include <functional>
#include <algorithm>

static bool begin_with_a(const std::string &s)
{
    return s.find('a') == 0;
}

static bool ends_with_b (const std::string &s){
    return s.rfind('b') == s.length() - 1;
}

template <class A, class B, class F> auto combine(F binary_func, A a, B b){
    return [=](auto param){
        return binary_func(a(param), b(param));
    };
}

