//Реализуем алгоритмы с помощью итераторов

#include <iostream>

class fibit{
    size_t i{0};
    size_t a{0};
    size_t b{1};
public:
    fibit() = default;
    explicit fibit(size_t i_):i{i_} {}
    size_t operator*() const;
    fibit& operator++();
    bool operator!=(const fibit &o) const;
};

bool fibit::operator!=(const fibit &o) const {
    return i != o.i;
}

size_t fibit::operator*() const {
    return b;
}

fibit& fibit::operator++(){
    const size_t old_b{b};
    b+=a;
    a = old_b;
    ++i;
    return *this;
}

class fib_range{
    size_t end_n;
public:
    fib_range(size_t end_n_):end_n{end_n_} {}
    fibit begin() const {return fibit{};}
    fibit end() const {return fibit{end_n};}
};

int main(){
    for (size_t i: fib_range(10)){
        std::cout << i << " ";
    }
    std::cout << '\n';
}