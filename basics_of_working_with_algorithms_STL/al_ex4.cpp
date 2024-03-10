//удаляем конкретные элементы из контейнеров

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void print(const std::vector<int> &v){
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>{std::cout, " "});
    std::cout << '\n';
}

int main(){
    std::vector<int> v {1, 2, 3, 4, 5, 6};
    print(v);
    {
        const auto new_end (remove(begin(v), end(v), 2));
        v.erase(new_end, end(v));
    }
    print(v);
    {
        auto odd_number ([](int i) { return i % 2 != 0; });
        const auto new_end (
        remove_if(begin(v), end(v), odd_number));
        v.erase(new_end, end(v));
    }
    print(v);
    replace(begin(v), end(v), 4, 123);
    print(v);
    v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> v2;
    std::vector<int> v3;
    auto odd_number ([](int i) { return i % 2 != 0; });
    auto even_number ([](int i) { return i % 2 == 0; });
    remove_copy_if(begin(v), end(v),
                   back_inserter(v2), odd_number);
    copy_if(begin(v), end(v),
            back_inserter(v3), even_number);
    print(v2);
    print(v3);
    return 0;
}