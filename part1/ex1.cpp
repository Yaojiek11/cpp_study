#include <iostream>

int main(){
    std::cout << "BMIを計算" << std::endl;
    double height;
    std::cout << "身長(m)=";
    std::cin >> height;
    double weight;
    std::cout << "体重(kg)=";
    std::cin >> weight;
    std::cout << "BMI=" << weight/(height*height) << std::endl;
    return 0;
}