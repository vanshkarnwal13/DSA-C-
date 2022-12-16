#include<iostream>
using namespace std;
template<typename T>
class Pair{
    T x;
    T y;
    public:
    void setX(T x){
        this->x = x;
    }
    void setY(T y){
        this->y = y;
    }
    T getX(){
        return x;
    }
    T getY(){
        return y;
    }

};
int main(){
    Pair<int> p1;
    Pair<double> p2;
    p1.setX(10);
    p1.setY(20);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;
    p2.setX(10.5);
    p2.setY(20.5);
    cout<<p2.getX()<<" "<<p2.getY()<<endl;
    
    return 0;
}