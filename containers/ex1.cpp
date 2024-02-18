//идиома erase-move для контейнера std::vector
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    std::vector<int> v{1, 2, 3, 4, 5}; // Создаем вектор с элементами 1, 2, 3, 4, 5

    // Выводим содержимое вектора
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0; // Возвращаем 0, чтобы указать успешное завершение программы
}