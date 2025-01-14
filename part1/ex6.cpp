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

int main(){
    Complex a;
    a.set_re(1.11);
    a.set_im(2.22);
    Complex b(3.33, 4.44);
    Complex c;
    Complex d(5.55);
    c = Complex(9.99, 88.88);
    a.print(std::cout); std::cout << std::endl;
    b.print(std::cout); std::cout << std::endl;
    c.print(std::cout); std::cout << std::endl;
    c = a;
    c.print(std::cout); std::cout << std::endl;
    d.print(std::cout); std::cout << std::endl;
    return 0;
}
