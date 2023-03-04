#include <iostream>
#include <list>
#include <algorithm>
#include <iterator> //for std::advance

class Person{
    friend std::ostream& operator<<(std::ostream& os,const Person& p);
    std::string name;
    int age;
public:
    Person():name{"Unknown"},age{0}{}
    Person(std::string name, int age)
        :name{name},age{age} {}
    bool operator<(const Person& rhs) const{
        return this->age<rhs.age;
    }
    bool operator==(const Person& rhs) const{
        return (this->age==rhs.age && this->name == rhs.name);
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p){
    os<<p.name<<":"<<p.age;
    return os;
}

template <typename T>
void display(const std::list<T>& l){
    std::cout<<"[";
    for(const auto& elem: l){
        std::cout<<elem<<" ";
    }
    std::cout<<"]"<<std::endl;
}


void test1(){
    std::cout<<"\nTest1============================="<<std::endl;

    std::list<int> l1 {1,2,3,4,5};
    display(l1);

    std::list<std::string> l2;

    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

    std::list<int> l3;
    l3 = {1,2,3,4,5,6,7,8,9,10};
    display(l3);

    std::list<int> l4 (10,100);
    display(l4);
}

void test2(){
    std::cout<<"\nTest2============================="<<std::endl;

    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    std::cout<<"Size: "<<l.size()<<std::endl;

    std::cout<<"Front: "<<l.front()<<std::endl;
    std::cout<<"Back : "<<l.back()<<std::endl;
    std::cout<<"Clear the list: ";
    l.clear();
    display(l);
    std::cout<<"Size: "<<l.size()<<std::endl;
}

void test3(){
    std::cout<<"\nTest3============================="<<std::endl;

     std::list<int> l {1,2,3,4,5,6,7,8,9,10};
     display(l);

     l.resize(5);
     display(l);

     l.resize(10);
     display(l);

     std::list <Person> persons;

     persons.resize(5); // uses the Person default constructor
     display(persons);
}

void test4(){
    std::cout<<"\nTest4============================="<<std::endl;

    std::list<int> l{1,2,3,4,5,6,7,8,9,10};

    display(l);
    auto it = std::find(l.begin(),l.end(),5);
    if(it!=l.end()){
        l.insert(it,100);
    }
    display(l);

    std::list<int> l2{1000,2000,3000};
    l.insert(it,l2.begin(),l2.end());
    display(l);

    std::advance(it,-4); //point to the 100
    std::cout<<*it<<std::endl;

    l.erase(it); //remove the 100 - iterator becomes invalid

    display(l);
}

void test5(){
    std::cout<<"\nTest5============================="<<std::endl;
    std::list<Person> stooges{
        {"Larry",18},
        {"Moe",25},
        {"Curly",17}
    };

    display(stooges);
    std::string name;
    int age{};
    std::cout<<"\nEnter the name of the next stooge: ";
    getline(std::cin,name);
    std::cout<<"Enter their age: ";
    std::cin>>age;

    stooges.emplace_back(name,age);
    display(stooges);

    //Insert Frank before Moe
    auto it = std::find(stooges.begin(),stooges.end(), Person{"Moe",25});
    if(it != stooges.end())
        stooges.emplace(it,"Frank",18);
    display(stooges);

}


void test6(){
    std::cout<<"\nTest6============================="<<std::endl;
    std::list<Person> stooges{
        {"Larry",18},
        {"Moe",25},
        {"Curly",17}
    };
    display(stooges);
    stooges.sort();
    display(stooges);
}
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}

// OUTPUT::


// Test1=============================
// [1 2 3 4 5 ]
// [Front Back ]
// [1 2 3 4 5 6 7 8 9 10 ]
// [100 100 100 100 100 100 100 100 100 100 ]

// Test2=============================
// [1 2 3 4 5 6 7 8 9 10 ]
// Size: 10
// Front: 1
// Back : 10
// Clear the list: []
// Size: 0

// Test3=============================
// [1 2 3 4 5 6 7 8 9 10 ]
// [1 2 3 4 5 ]
// [1 2 3 4 5 0 0 0 0 0 ]
// [Unknown:0 Unknown:0 Unknown:0 Unknown:0 Unknown:0 ]

// Test4=============================
// [1 2 3 4 5 6 7 8 9 10 ]
// [1 2 3 4 100 5 6 7 8 9 10 ]
// [1 2 3 4 100 1000 2000 3000 5 6 7 8 9 10 ]
// 100
// [1 2 3 4 1000 2000 3000 5 6 7 8 9 10 ]

// Test5=============================
// [Larry:18 Moe:25 Curly:17 ]

// Enter the name of the next stooge: Vadim
// Enter their age: 26
// [Larry:18 Moe:25 Curly:17 Vadim:26 ]
// [Larry:18 Frank:18 Moe:25 Curly:17 Vadim:26 ]

// Test6=============================
// [Larry:18 Moe:25 Curly:17 ]
// [Curly:17 Larry:18 Moe:25 ]
