//преобразуем содержимое контейнеров

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    std::vector<int> v {1, 2, 3, 4, 5};
    std::transform(std::begin(v), std::end(v), std::ostream_iterator<int>{cout, " "}, [](int i) {return i*i;});
    cout << '\n';
    auto int_to_string ([](int i) {
        stringstream ss;
        ss << i << "^2 = " << i * i;
        return ss.str();
    });
    vector<string> vs;
    transform(begin(v), end(v), back_inserter(vs),
              int_to_string);
    copy(begin(vs), end(vs),
         ostream_iterator<string>{cout, "\n"});
    return 0;
}