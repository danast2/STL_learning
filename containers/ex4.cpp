//Сохраняем сортировку экземпляров
//класса std::vector

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

template <class T> void insert_sorted(vector<T>& v, string& s){
    //lower bound ищет позицию в отсортированном диапазоне, где можно вставить заданное значение s без нарушения порядка сортировки. Она использует бинарный поиск для выполнения этой операции.
    //insert_pos будет содержать итератор, указывающий на позицию в контейнере v, куда можно вставить значение s так, чтобы порядок сортировки оставался правильным.
    //const std::vector<string>::iterator insert_pos = lower_bound(begin(v), end(v), s);
    const auto insert_pos = lower_bound(begin(v), end(v), s);
    v.insert(insert_pos, s);
}

int main(){
    vector<string> v {"some", "random", "words", "without", "order", "aaa","yyy"};
    assert(false == is_sorted(begin(v), end(v)));
    sort(begin(v), end(v));
    assert(true == is_sorted(begin(v), end(v)));
    insert_sorted(v, (string &) "foobar");
    insert_sorted(v, (string &) "sdff");
    for(const auto &w: v){
        cout << w << " ";
    }
    cout << "\n";
}

