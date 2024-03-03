//добавляем полиморфизм путем оборачивания лямбда-выражений в std::function

#include <iostream>
#include <deque>
#include <list>
#include <vector>

static auto consumer = [](auto &container) {
    return [&] (auto value) {
        container.push_back(value);
    };
};

static void print(const auto &c) {
    for (auto i : c) {
        std::cout << i << ", ";
    }
    std::cout << '\n';
}

int main() {
    std::deque<int> d;
    std::list<int> l;
    std::vector<int> v;
    for (size_t i {0}; i < 10; ++i) {
        for (auto &&consume : {consumer(d), consumer(l), consumer(v)}) {
            consume(i);
        }
    }
    print(d);
    print(l);
    print(v);
    return 0;
}
