
#include<iostream>
using namespace std;

class Hero {
    //properties
    int health ;
    char level;

    public:
    Hero(){
        cout<< "Constructor is called"<<endl;
    }

    // Parameterize constructor

    Hero(int health){
        this->health = health;
    }
    Hero(int health, char level){
        this->health = health;
        this->level = level;
    }

    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char l){
        level = l;
    }
};

int main (){
    // static constructor call
    // cout<< "Static constructor call start" << endl;
    // Hero papu;
    // cout<< "Static constructor call end" << endl;

    // dynamic constructor call
    // cout<< "Dynamic constructor call start" << endl;
    // Hero *h = new Hero();
    // cout<< "Dynamic constructor call end" << endl;

    // 
    return 0;
}
