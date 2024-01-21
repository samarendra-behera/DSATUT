#include<iostream>
using namespace std;

// class Hero {
//     //properties
// };

class Hero2 {
    //properties
    int health ;
    char level;

    public:
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

class Example {
    char a;  // 1 byte
    // 3 bytes padding to align the next member
    int b;   // 4 bytes
    char c;  // 1 byte
    // 3 bytes padding at the end to align the size of the structure
};

int main(){
    // Hero obj;
    // cout<< "Size of Hero Object "<< sizeof(obj) << endl; //output is 1  

    // Hero2 obj2;
    // cout<< "Size of Hero2 Object " << sizeof(obj2) <<endl;
    // cout << "Size of Example: " << sizeof(Example) << " bytes\n";

    // static allocation
    Hero2 papun;
    papun.setHealth(60);
    papun.setLevel('R');
    cout<< "Static Health " << papun.getHealth() << endl;
    cout<< "Static Level " << papun.getLevel() << endl;

    // dynamic allocation
    Hero2 *h = new Hero2;
    // h->setHealth(50);
    // h->setLevel('L');
    // cout << "Dynamic Health "<< h->getHealth() <<endl;
    // cout << "Dynamic Level "<< h->getLevel() <<endl;

    // or we also write like this
    (*h).setHealth(50);
    (*h).setLevel('L');
    cout << "Dynamic Health "<< (*h).getHealth() <<endl;
    cout << "Dynamic Level "<< (*h).getLevel() <<endl;

    return 0;
}