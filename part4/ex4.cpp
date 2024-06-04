#include <iostream>
#include <assert.h>

class stack{
    private:
        int sp;
        int max;
        int* data;
    public:
        stack(int sz) : max(sz),sp(0){data=new int[max];}
        stack(const stack& s);
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

//派生クラスstack_acの定義
class stack_ac : public stack{
    private:
        int push_count;
    public:
        stack_ac(int sz):stack(sz),push_count(0){}
        ~stack_ac(){}

        void push(int d) {
            stack::push(d);
            push_count++;
        }
        int n_push(){return push_count;}
        int n_pop(){return push_count-stack::size();}
};

int main(){
    stack_ac s(10);
    
    s.push(1); s.push(3); s.push(5);
    s.push(2); s.push(4); s.push(6);
    s.dump(std::cout);
    std::cout << "push_count=" << s.n_push() << std::endl;
    std::cout << "pop_count=" << s.n_pop() << std::endl;

    s.pop(); s.pop(); s.push(10);
    s.dump(std::cout);
    std::cout << "push_count=" << s.n_push() << std::endl;
    std::cout << "pop_count=" << s.n_pop() << std::endl;
    
    return 0;
}