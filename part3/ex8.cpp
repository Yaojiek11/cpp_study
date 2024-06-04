#include <iostream>
#include <assert.h>

class stack{
    private:
        int sp;
        int max;
        int* data;
    public:
        stack(int sz){sp=0; max=sz; data=new int[max];}
        stack(const stack& s);    //コピーコンストラクタ
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

stack::stack(const stack& s){
    max = s.max;
    data = new int[max];
    sp = s.sp;
    for(int i=0; i<sp; i++) {data[i] = s.data[i];}
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

stack plus(stack s1, stack s2){
    int sz = s1.size() + s2.size();
    stack tmp(sz), s(sz);
    while(!s2.empty()) {tmp.push(s2.top()); s2.pop();}
    while(!s1.empty()) {tmp.push(s1.top()); s1.pop();}
    while(!tmp.empty()) {s.push(tmp.top()); tmp.pop();}
    return s;
}

int main(){
    stack s1(5);
    stack s2(5);
    stack s(10);
    
    s1.push(1); s1.push(3); s1.push(5);
    s2.push(2); s2.push(4); s2.push(6);

    s = plus(s1, s2);

    s1.dump(std::cout);
    s2.dump(std::cout);
    s.dump(std::cout);
    
    return 0;
}