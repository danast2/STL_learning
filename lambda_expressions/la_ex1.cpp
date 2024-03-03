//динамическое определение функций с помощью лямбда-выражений

#include <iostream>
#include <string>

int main(){
    auto just_one ([](){return 1;});
    auto just_two ([](){return 2;});

    std::cout << just_one() << " " << just_two << '\n';
    auto plus ([](auto l, auto r){return l + r;});
    auto counter ([count  = 0]()mutable {return ++count;});
    for (size_t i {0}; i < 5; ++i){
        std::cout << counter() << " ";
    }
    std::cout << '\n';

    int i {0};
    auto incrementer ([&i] {++i;});
    incrementer();
    incrementer();
    incrementer();

    std::cout << "value of 'a' after 3 incrementer() calls: "<< i << '\n';

    auto plus_ten ([=](int x) {return plus(10, x);});
    std::cout << plus_ten(5) << '\n';
    return 0;
}