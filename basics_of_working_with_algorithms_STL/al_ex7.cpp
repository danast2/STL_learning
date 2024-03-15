//Ограничиваем допустимые значения
//вектора конкретным численным диапазоном
//с помощью std::clamp

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

static auto norm(int min, int max, int new_max) {
    const double diff(max - min);
    return [=](int val) {
        return int((val - min) / diff * new_max);
    };
}

static auto clampval(int min, int max) {
    return [=](int val) -> int {
        return std::clamp(val, min, max);
    };
}

int main() {
    std::vector<int> v{0, 1000, 5, 250, 300, 800, 900, 321};
    const auto [min_it, max_it](
            minmax_element(begin(v), end(v)));
    std::vector<int> v_norm;
    v_norm.reserve(v.size());

    transform(begin(v), end(v), back_inserter(v_norm),
              norm(*min_it, *max_it, 255));
    copy(begin(v_norm), end(v_norm),
         std::ostream_iterator<int>{std::cout, ", "});
    std::cout << '\n';

    transform(begin(v), end(v), begin(v_norm),
              clampval(0, 255));

    copy(begin(v_norm), end(v_norm),
         std::ostream_iterator<int>{std::cout, ", "});
    std::cout << '\n';
}
