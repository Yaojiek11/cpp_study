#include <iostream>
#include <assert.h>

class stack{
    private:
        int sp;
        int max;
        int* data;
    public:
        stack(int sz){sp=0; max=sz; data=new int[max];}
        ~stack() {delete [] data;}
        bool empty() {return sp==0;}
        void push(int d) {assert(sp<=max); data[sp++]=d;}
        void pop() {assert(0<sp); --sp;}
        int top() {return data[sp-1];}
        int size() {return sp;}
        void dump(std::ostream&);
        stack& operator=(const stack&);
};

void stack::dump(std::ostream& os){
    std::cout << "max=" << max << ", ";
    std::cout << "sp=" << sp << ", ";
    std::cout << "data=(";
    for(int i=0; i<sp; i++) os << data[i] << " ";
    os << ")" << std::endl;
}

stack& stack::operator=(const stack& s){
    if(&s!=this){
        if(max<s.sp){
            delete [] data;
            data = new int[max=s.max];
        }
        sp = s.sp;
        for(int i=0; i<sp; i++) {data[i] = s.data[i];}
    }
    return *this;
}

int main(){
    stack s1(5), s2(7);
    s1.push(1); s1.push(3); s1.push(5);

    s2 = s1;
    s1.pop(); s1.pop(); s1.push(300); s1.push(500);
    
    s1.dump(std::cout);
    s2.dump(std::cout);
    return 0;
}