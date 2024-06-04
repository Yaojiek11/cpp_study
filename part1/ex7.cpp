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
};

Complex operator+(Complex a, Complex b){
    double r = a.re() + b.re();
    double i = a.im() + b.im();
    return Complex(r, i);
}

Complex operator-(Complex a, Complex b){
    double r = a.re() - b.re();
    double i = a.im() - b.im();
    return Complex(r, i);
}

Complex operator*(Complex a, Complex b){
    double r = a.re()*b.re() - a.im()*b.im();
    double i = a.re()*b.im() + a.im()*b.re();
    return Complex(r, i);
}

int main(){
    Complex a(3.00, 4.00);
    Complex b(1.00, -2.00);
    Complex c, d, e;
    c = a + b;
    d = a - b;
    e = a * b;
    c.print(std::cout); std::cout << std::endl;
    d.print(std::cout); std::cout << std::endl;
    e.print(std::cout); std::cout << std::endl;
    return 0;
}
