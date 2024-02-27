#include <iostream>

class num_iterator{
    int i;
public:
    explicit num_iterator(int position = 0): i{position}{}
    int operator*()const {return i;}
    num_iterator& operator++();
    bool operator!=(const num_iterator& other) const;
};

bool num_iterator::operator!=(const num_iterator &other) const {
    return i != other.i;
}

num_iterator& num_iterator::operator++() {
    ++i;
    return *this;
}


class num_range{
    int a;
    int b;
public:
    num_range(int from, int to): a{from}, b{to}{}
    num_iterator begin() const { return num_iterator{a}; }
    num_iterator end() const { return num_iterator{b}; }
};

int main()
{
    for (int i : num_range{100, 110}) {
        std::cout << i << ", ";
        //Создаем собственный итерабельный диапазон данных
    }
    std::cout << '\n';
}