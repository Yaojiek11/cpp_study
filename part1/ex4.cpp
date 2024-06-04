#include <iostream>
#include <assert.h>

class stack{
    private:
        int max;
        int *data;
        int sp;
    public:
        bool empty(){return sp==0;}
        void push(int d){assert(sp < max); data[sp++]=d;}
        int top(){return data[sp-1];};
        void pop(){assert(0 < sp); --sp;}
        int size(){return sp;}
        stack(int sz=100){
            sp = 0;
            max = sz;
            std::cout << "max=" << max << std::endl;
            data = new int[max];
        }
        ~stack(){delete [] data;}
};

int main(){
    int sz;
    std::cout << "size=";
    std::cin >> sz;
    stack s(sz);
    s.push(5);
    s.push(8);
    s.push(9);
    s.push(3);
    s.push(4);
    while(!s.empty()){
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}