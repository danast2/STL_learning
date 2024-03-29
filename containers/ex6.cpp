/*Исследуем новую семантику подсказок
для вставки элементов с помощью
        метода std::map::insert*/

#include <iostream>
#include <string>
#include <map>

using namespace std;




int main(){
    std::map<string, size_t> m {{"b", 1},{"c", 2},{"d", 3}};
    auto insert_it(end(m));
    for (const auto &s: {"z", "y", "x", "w"}) {
        insert_it = m.insert(insert_it, {s, 1});
    }

    //Чтобы продемонстрировать, как не нужно решать задачу, вставим строку,
    // которая окажется с левого края ассоциативного массива, но зададим для нее неправильную подсказку,
    // указывающую на крайнюю правую позицию ассоциативного
    //массива — end:

    m.insert(std::end(m), {"a", 1});
    //6. Наконец, просто выведем на экран полученный результат.

    for (const auto & [key, value] : m) {
        std::cout << "\"" << key << "\": " << value << ", ";
    }
    std::cout << '\n';

    /*Скомпилировав и запустив программу, мы получим следующий результат.
Очевидно, ошибочная подсказка при вставке ничего не испортила, поскольку
порядок ассоциативного массива все еще правильный*/
}