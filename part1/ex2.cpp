#include <iostream>

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int main(){
    int a=5;
    int b=10;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    swap(a, b);
    std::cout << "swapped" << std::endl;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    return 0;
}