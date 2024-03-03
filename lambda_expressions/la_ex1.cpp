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
    return 0;
}