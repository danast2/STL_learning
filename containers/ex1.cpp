//идиома erase-move для контейнера std::vector
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    std::vector<int> v{1, 2, 3, 4, 5}; // Создаем вектор с элементами 1, 2, 3, 4, 5
    //Удалим некоторые элементы. Что именно? В нашем примере много значений 2,
    //удалим их:
    const auto new_end (remove(begin(v), end(v), 2));

    //укоротим размер вектора:
    v.erase(new_end, end(v));

    for (auto i :v) {
        cout << i;
        if (i != *(v.end())){
            cout << ", ";
        }

    }

    return 0; // Возвращаем 0, чтобы указать успешное завершение программы
}