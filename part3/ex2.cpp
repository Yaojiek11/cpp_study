#include <iostream>
#include <string>

class trace{
    private:
        std::string name;
    public:
        trace(const std::string& nm){
            name = nm;
            std::cerr << name << " begin" << std::endl;
        }
        ~trace(){
            std::cerr << name << " end" << std::endl;
        }
};

int add(int a, int b){
    trace t("add");
    return a+b;
}

int main(){
    trace t1("main");
    for(int i=0; i<3; i++){
        trace t2("for-loop");
        int c = add(i, i*i);
    }
    return 0;
}