//основы работы с алгоритмами STL

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

int main(){
    std::vector <int> v {100, 400, 200 /*....*/};

    int sum{0};
    for (int i: v) {sum += i;}
    std::cout << sum << '\n';
    std::cout << std::accumulate(std::begin(v), end(v), 0) << '\n';

}
