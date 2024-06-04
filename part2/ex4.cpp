#include <iostream>
#include <map>
#include <string>

int main(){
    std::map<std::string, int> fmap;
    fmap["aaaa"] = 21;
    fmap["bbbb"] = 33;
    fmap["cccc"] = 44;

    std::cout << fmap["aaaa"] << std::endl;
    std::cout << fmap["bbbb"] << std::endl;
    std::cout << fmap["cccc"] << std::endl;
    std::cout << fmap["dddd"] << std::endl;

    std::cout << "イテレータによる走査" << std::endl;
    std::map<std::string, int>::iterator p;
    for(p=fmap.begin(); p!=fmap.end(); p++){
        std::cout << p->first << ": " << p->second << std::endl;
    }

    std::cout << "データの検索 > ";
    std::string str;
    std::cin >> str;
    if((p=fmap.find(str))==fmap.end()) std::cout << "not found" << std::endl;
    else{
        std::cout << p->first << ": " << p->second << std::endl;
        fmap.erase(p);
    }

    return 0;
}