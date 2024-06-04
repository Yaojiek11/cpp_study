#include <iostream>
#include <string>
#include <list>
#include <vector>

class Record {
  public:
    int id;
    std::string name;
    int score;
    Record() {}
    Record(int i, const std::string& nm, int s) {
      id = i;
      name = nm;
      score = s;
    }
};

std::ostream& operator<<(std::ostream& os, const Record& r) {
  os << "[" << r.id << "] " << r.name << " : " << r.score;
  return os;
}

class Seiseki {
  public:
    std::list<Record> data;
    void insert(int, const std::string&, int);
    void lookup(int);
    void erase_worst();
};

std::ostream& operator<<(std::ostream& os, const Seiseki& s) {
  os << "*** Seiseki ***\n";
  for (std::list<Record>::const_iterator p = s.data.begin(); p != s.data.end(); p++) {
    os << *p << "\n";
  }
  return os;
}

void Seiseki::insert(int id, const std::string& nm, int s) {
    // idの昇順に格納
    for(std::list<Record>::const_iterator p = data.begin(); p != data.end(); p++){
        if(p->id > id){
            data.insert(p, Record(id, nm, s));
            return;
        }
    }
    data.push_back(Record(id, nm, s));
}

void Seiseki::lookup(int id) {
    for(std::list<Record>::const_iterator p = data.begin(); p != data.end(); p++){
        if(p->id == id){
            std::cout << *p << std::endl;
            return;
        }
    }
    std::cout << "not found." << std::endl;
}

void Seiseki::erase_worst() {
    //最低点を求める
    int min_score = 100;
    for(std::list<Record>::const_iterator p = data.begin(); p != data.end(); p++)
        if(p->score < min_score) min_score = p->score;
    
    // 削除するデータのイテレータを格納する配列
    std::vector<std::list<Record>::iterator> erase_list;
    // 該当データのイテレータをerase_listに格納
    for(std::list<Record>::iterator p = data.begin(); p != data.end(); p++){
        if(p->score == min_score) erase_list.push_back(p);
    }
    // 削除
    for(int i=0; i<erase_list.size(); i++){
        data.erase(erase_list[i]);
    }
    erase_list.clear();
}


int main(int ac, char** av)
{
  Seiseki s;
  s.insert(7001,"aaaa",89);
  s.insert(7123,"bbbb",70);
  s.insert(7013,"cccc",55);
  s.insert(7200,"dddd",99);
  s.insert(7087,"eeee",83);
  s.insert(7035,"ffff",55);
  s.insert(7099,"gggg",55);

  std::cout << s;

  int id;
  std::cout << "> ";
  std::cin >> id;
  while (id!=0) {
    s.lookup(id);
    std::cout << "> ";
    std::cin >> id;
  }

  s.erase_worst();
  std::cout << s;

  return 0;
}