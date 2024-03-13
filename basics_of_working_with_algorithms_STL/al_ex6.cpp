//выполняем поиск элементов в упорядоченных и неупорядоченных векторах

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

struct city{
    std::string name;
    unsigned population;
};

bool operator==(const city &a, const city &b) {
    return a.name == b.name && a.population == b.population;
}

std::ostream& operator<<(std::ostream &os, const city &city) {
    return os << "{" << city.name << ", "
              << city.population << "}";
}

template <typename C>
static auto opt_print (const C &container)
{
    return [end_it (end(container))] (const auto &item) {
        if (item != end_it) {
            std::cout << *item << '\n';
        } else {
            std::cout << "<end>\n";
        }
    };
}

int main() {
    const std::vector<city> c{
            {"Aachen",       246000},
            {"Berlin",       3502000},
            {"Braunschweig", 251000},
            {"Cologne",      1060000}
    };

    auto print_city(opt_print(c));

    {
        auto found_cologne (find(begin(c), end(c),
        city{"Cologne", 1060000}));
        print_city(found_cologne);
    }

    {
        auto found_cologne (find_if(begin(c), end(c),
        [] (const auto &item) {
            return item.name == "Cologne";
        }));
        print_city(found_cologne);
    }
}