//Получаем доступ к экземплярам класса
//std::vector быстрым или безопасным способом

#include <iostream>
#include <vector>

using namespace std;

int main(){
    const size_t container_size {1000};
    vector<int> v (container_size, 123);
    try{
        cout << "out if range element val:" << v[container_size + 100] << '\n';
        //Далее обратимся к элементу, лежащему за пределами вектора, с помощью функ-
        //ции at:
        //at генерирует исключение
        cout << "out of range el val :" << v.at(container_size + 100) << '\n';
        /*Оператор [] полезен при выполнении вычислений, для которых нужно очень
    быстро обращаться к проиндексированным элементам вектора. В любой другой
    ситуации функция at помогает определять ошибки, при этом вы почти не теряете
    в производительности.*/
    }catch (const std::out_of_range & e){
        cout << "smth went wrong(((" << e.what() << '\n';
    }

    return 0;
}