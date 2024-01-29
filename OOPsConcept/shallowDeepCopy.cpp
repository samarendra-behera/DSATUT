#include<iostream>
#include<cstring>
using namespace std;

class Hero {
    //properties
    int health ;
    char level;

    public:
    char *name;

    public:
    Hero(){
        cout<< "Constructor is called"<<endl;
        this->name = new char[100];
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
    // Hero(Hero &temp){
    //     this->health = temp.health + 10;
    //     this->level = temp.level;
    // }

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
    void setName(char name[]){
        strcpy(this->name, name);
    }
    void print(){
        cout<<"Health is: "<< this->health << " and level is: " << this->level << endl << "Name is: " << this->name << endl;
    }
};

int main(){
    Hero h1(70, 'A');

    // Hero h2(h1);
    // h1.print();
    // h2.print();

    // shallow copy
    Hero myhero;
    myhero.setHealth(45);
    myhero.setLevel('Z');
    char name[7] = "Gobber";
    myhero.setName(name);
    cout<<"My Hero Details : "<<endl;
    myhero.print();


    cout<<endl<<"My Hero 2 Details : "<<endl;
    Hero myhero2(myhero);
    myhero2.print();

    // changing in myhero will change in myhero2
    myhero.name[0] = 'B';
    cout<<endl<<"My Hero Details : "<<endl;
    myhero.print();
    cout<<endl<<"My Hero 2 Details : "<<endl;
    myhero2.print();


    return 0;
}