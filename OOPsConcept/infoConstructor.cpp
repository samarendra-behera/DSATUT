
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

    // Define copy constructor
    Hero(Hero &temp){
        this->health = temp.health + 10;
        this->level = temp.level;
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
    void print(){
        cout<<"Health is: "<< this->health << " and level is: " << this->level << endl;
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

    // Parameterized constructor
    // static parameterized constructor call
    // Hero papu(70);
    // dynamic parameterized constructor call
    // Hero *h = new Hero(80, 'A');
    // cout << papu.getHealth() << endl;
    // cout << papu.getLevel() << endl;
    // cout << h->getHealth() << endl;
    // cout << h->getLevel() << endl;

    // Copy constructor
    Hero h1(70, 'A');
    h1.print();

    // copy constructor call
    Hero h2(h1);
    h2.print();
    return 0;
}
