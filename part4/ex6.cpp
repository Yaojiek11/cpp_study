#include <iostream>

inline int abs(int x){return 0<=x ? x : -x;}

//canvasクラス
class canvas{
    public:
        canvas(int sx, int sy);  //サイズsx × syのキャンバスを構築
        ~canvas();  //デストラクタ
        void clear(); //キャンバスを真っ白にする
        void set(int x, int y); //座標(x,y)にドットを打つ
        void print(std::ostream &os);   //現在のキャンバスをosに出力する
    private:
        int size_x; //横サイズ
        int size_y; //縦サイズ
        char **p; //2次元配列は構築時に割り当てる
        canvas(const canvas&);  //コピーコンストラクタ禁止
        canvas& operator=(const canvas&); //代入演算禁止
};

std::ostream& operator<<(std::ostream& os, canvas& c){c.print(os);}

canvas::canvas(int sx, int sy): size_x(sx), size_y(sy){
    p = new char* [size_x];
    for(int x=0; x<size_x; x++) p[x] = new char[size_y];
    this->clear();  // canvas::clear()を呼び出し真っ白に初期化
}

canvas::~canvas(){
    for(int x=0; x<size_x; x++) delete[] p[x];
    delete [] p;
}

void canvas::clear(){
    for(int x=0; x<size_x; x++){
        for(int y=0; y<size_y; y++){
            p[x][y] = ' ';
        }
    }
}

void canvas::set(int x, int y){
    if(0<=x && x<size_x && 0<=y && y<size_y) p[x][y] = 'X';
}

void canvas::print(std::ostream& os){
    os << '+';
    for(int x=0; x<size_x; x++){os << '-';}
    os << '+' << std::endl;
    for(int y=size_y-1; 0<=y; y--){
        os << '|';
        for(int x=0; x<size_x; x++){
            os << p[x][y];
        }
        os << '|' << std::endl;
    }
    os << '+';
    for(int x=0; x<size_x; x++){os << '-';}
    os << '+' << std::endl;
}


//仮想抽象クラスobj
class obj{
    public:
        obj(int x, int y, const std::string& t); //コンストラクタ
        ~obj(); //デストラクタ
        void move(int ix, int iy);
        void draw(canvas &c);
    public:
        int px, py;
        std::string type;   // "point","rectangle","diamond"
};

obj::obj(int x, int y, const std::string& t) : px(x), py(y), type(t){}
obj::~obj(){}
void obj::move(int ix, int iy){px += ix; py += iy;}

//pointクラス(objの派生クラス)
class point : public obj{
    public:
        point(int x, int y);
        ~point();
        void draw(canvas &c);
};

point::point(int x, int y) : obj(x, y, "point") {}
point::~point(){}
void point::draw(canvas &c) {c.set(px, py);} 

//rectangleクラス(objの派生クラス)
class rectangle : public obj{
    private:
        int width, height; //幅と高さ
    public:
        rectangle(int x, int y, int w, int h);
        //座標(x,y),幅w,高さhの長方形を構築
        ~rectangle();
        void draw(canvas &c);
};

rectangle::rectangle(int x, int y, int w, int h) : obj(x, y, "rectangle"),width(w),height(h){};
rectangle::~rectangle(){}
void rectangle::draw(canvas &c){
    for(int h=0; h<height; h++){
        for(int w=0; w<width; w++){
            c.set(px+w, py+h);
        }
    }
}

//diamondクラス(objの派生クラス)
class diamond : public obj{
    private:
        int radius; //半径
    public:
        diamond(int x, int y, int r);
        ~diamond();
        void draw(canvas &c);
};

diamond::diamond(int x, int y, int r) : obj(x, y, "diamond"), radius(r){}
diamond::~diamond(){}
void diamond::draw(canvas &c){
    if(0<=radius){
        for(int r=-radius; r<=radius; r++){
            int h = radius - abs(r);
            for(int s=-h; s<=h; s++){
                c.set(px+r, py+s);
            }
        }
    }
}

int main(){
    // 3つの点,2つの長方形,2つの菱形を生成
    point p1(0,0);
    point p2(17,9);
    point p3(19,2);
    rectangle r1(2,1,3,2);
    rectangle r2(7,7,6,2);
    diamond d1(2,7,2);
    diamond d2(15,3,4);

    // 生成した図形をキャンバスcに描き,出力
    canvas c(20,10);
    p1.draw(c);
    p2.draw(c);
    p3.draw(c);
    r1.draw(c);
    r2.draw(c);
    d1.draw(c);
    d2.draw(c);
    std::cout << c;

    // 点,長方形,菱形を一斉に(4,2)だけ移動させる
    p1.move(4,2);
    p2.move(4,2);
    p3.move(4,2);
    r1.move(4,2);
    r2.move(4,2);
    d1.move(4,2);
    d2.move(4,2);

    // キャンバスcを一旦クリアし,移動した点,長方形,菱形を描き,出力する
    c.clear();
    p1.draw(c);
    p2.draw(c);
    p3.draw(c);
    r1.draw(c);
    r2.draw(c);
    d1.draw(c);
    d2.draw(c);
    std::cout << c;

    return 0;
}
