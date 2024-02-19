//Удаляем элементы из неотсортированного
//объекта класса std::vector за время O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//Во-первых, просто возьмем значение последнего элемента вектора
//и запишем его на место элемента, который должен быть удален. Во-вторых, от-
//бросим последний элемент
template<typename T> void quick_remove_at(std::vector<T> &v, std::size_t idx){
    if(idx < v.size()){
        v[idx] = std::move(v.back());
        v.pop_back();
    }
}

//Другая реализация метода quick_remove_at работает аналогично. Вместо того
//чтобы принимать численный индекс, она принимает итератор для вектора
//std::vector<T>.
template <typename T> void quick_remove_at(std::vector<T> &v, typename std::vector<T>::iterator it){
    if (it!= std::end(v)){
        *it = std::move(v.back());
        v.pop_back();
    }
}

int main(){
    std::vector<int> v{123, 456, 789, 100, 200};
    quick_remove_at(v, 2);

    auto lastEl = v.back();
    for (auto i: v) {
        cout << i;
        if (i != lastEl) {
            cout << ", ";
        }
    }
    quick_remove_at(v, std::find(std::begin(v), std::end(v), 123));

    lastEl = v.back();
    std::cout << '\n';
    for (auto i: v) {
        cout << i;
        if (i != lastEl) {
            cout << ", ";
        }
    }
}
