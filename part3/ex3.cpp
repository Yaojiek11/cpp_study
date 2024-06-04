#include <iostream>

class Complex{
    private:
        double real;
        double imag;
    public:
        Complex(){real=0.0; imag=0.0;}
        Complex(double r, double i){real=r; imag=i;}
        Complex(double r){real=r; imag=0.0;}
        ~Complex(){}
        double re(){return real;}
        double im(){return imag;}
        void set_re(double r){real = r;}
        void set_im(double i){imag = i;}
        void print(std::ostream& os){os << real << "+" << imag << "i";}
        Complex& operator=(const Complex&);     //代入演算
        Complex& operator+=(const Complex&);  //加算代入演算
};

Complex& Complex::operator=(const Complex& c){
    real = c.real;
    imag = c.imag;
    return *this;
}

Complex& Complex::operator+=(const Complex& c){
    real += c.real;
    imag += c.imag;
    return *this;
}

int main(){
    Complex a(1.00, 2.00);
    Complex b;
    Complex c;
    Complex d(3.00, 5.00);
    c = (b=a);
    d += a;
    c.print(std::cout); std::cout << std::endl;
    d.print(std::cout); std::cout << std::endl;
    return 0;
}