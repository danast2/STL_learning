//Эффективно изменяем ключи
//элементов std::map


#include <iostream>
#include <map>

using namespace std;

//Мы выведем на экран места всех водителей до и после изменения контейне-
//ра map, поэтому реализуем вспомогательную функцию, посвященную именно
//этому

template<class T> void print(const T& t){
    cout << "Race placment: \n";
    for(const auto &[placement, driver]: t){
        cout << placement << ": " << driver << '\n';
    }
}

int main(){
    map<int, string> race_placement {
            {1, "Mario"}, {2, "Luigi"}, {3, "Bowser"},
            {4, "Peach"}, {5, "Yoshi"}, {6, "Koopa"},
            {7, "Toad"}, {8, "Donkey Kong Jr"}
            };
    print(race_placement);

    {
        auto a (race_placement.extract(3));
        auto b (race_placement.extract(5));

        swap(a.key(), b.key());

        race_placement.insert(std::move(a));
        race_placement.insert(std::move(b));
    }

    print(race_placement);
    return 0;
}