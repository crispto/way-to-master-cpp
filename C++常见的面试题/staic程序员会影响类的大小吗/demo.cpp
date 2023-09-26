#include<iostream>
#include<string>
using namespace std;


#define PRINT_SIZE(class_name) cout << "size of "  #class_name " is " << sizeof(class_name) << endl;

class Foo {
public:
private:
    int age_{10};
    // int age2_{10};
    string name_{"mark"};
};
class FooStatic {
public:
    static string Foo_Count;
private:
    int age_{10};
    string name_{"mark"};

};

string FooStatic::Foo_Count = "hello";


class FooWithFunc {
public:
    void show(){
        cout <<"name: " << name_ <<", age : "<< age_ <<endl;
    };
    void show2(){
        cout <<"name: " << name_ <<", age : "<< age_ <<endl;
    }
private:
    int age_{10};
    string name_{"mark"};

};

class FooWithVirtual {
public:
    virtual void FooEat(){
        cout <<"Foo base eat sandwitch" <<endl;
    };
private:
    int age_{10};
    string name_{"mark"};

};

class FooWithTwoVirtual {
public:
    virtual void FooEat(){
        cout <<"Foo base eat sandwitch" <<endl;
    };
     virtual void FooSpeak(){
        cout <<"Foo base speak English" <<endl;
    };
private:
    int age_{10};
    string name_{"mark"};
    
};

class Base {
public:
private:

};

class FooFromBase: virtual public Base {
public:
private:
    int age_{10};
    string name_{"mark"};
};


int main(){
    PRINT_SIZE(int);
    PRINT_SIZE(string);

    PRINT_SIZE(Foo); // 4 + 24  并以 8 对齐
    PRINT_SIZE(FooStatic); // 增加一个 static 类型并不影响类的大小
    PRINT_SIZE(FooWithFunc) // 增加一个函数也不影响类的大小
    PRINT_SIZE(FooWithVirtual); // 增加一个虚函数，类的大小增大了。
    PRINT_SIZE(FooWithTwoVirtual); // 再增加一个虚函数，和一个虚函数的时候一样


    PRINT_SIZE(Base); // 空的类会有一个占位符，所以类的大小为1 
    PRINT_SIZE(FooFromBase); // 这里有一个
}
