#include <iostream>
#include <string>
#include <vector>

class Entry {
  public:
    std::string name;
    std::string phone;
    Entry(const std::string& nm="", const std::string& ph="") {
      name = nm;
      phone = ph;
    }
};

std::ostream& operator<<(std::ostream& os, const Entry& e) {
  os << e.name << ": " << e.phone;
  return os;
}

int main(int ac, char** av)
{
  std::vector<Entry> e;
  e.push_back(Entry("university of tokyo", "03-3812-2111"));
  e.push_back(Entry("osaka university", "06-879-7806"));
  e.push_back(Entry("kinki university", "06-721-2332"));
  e.push_back(Entry("osaka prefectural university", "0722-52-1161"));
  e.push_back(Entry("kyoto university", "075-753-7531"));

  for (int i=0; i<e.size(); i++) {
    // 大阪の局番4桁化
    if(e[i].phone.find("06") == 0){
        // 1番目のハイフンの位置
        int first_hyphen = e[i].phone.find("-");
        // 2番目のハイフンの位置
        int second_hyphen = e[i].phone.rfind("-");
        // 市外局番を抽出
        std::string middle_str = e[i].phone.substr(first_hyphen+1,second_hyphen-first_hyphen-1);
        // 置換
        e[i].phone.replace(first_hyphen+1, second_hyphen-first_hyphen-1, "6"+middle_str);
    }
    //std::cout << e[i] << std::endl;
  }
  
  std::cout << "directory service: ";
  // 文字列を入力し、その電話番号を検索し、出力
  std::string search;
  getline(std::cin,search); //空白込みで入力
  // 部分文字列として含むデータを全て出力
  for(int i=0; i<e.size(); i++){
      if(e[i].name.find(search) != e[i].name.npos){
          std::cout << e[i] << std::endl;
      }
  }
  return 0;
}