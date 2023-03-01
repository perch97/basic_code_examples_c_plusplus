#include<iostream>
#include<vector>
#include <cstring>
using namespace std;

class Mystring{
    friend bool operator==(const Mystring& lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring& obj);
    friend Mystring operator+(const Mystring& lhs);
private:
    char* str; //pointer to a char[] that holds a C-style string
public:
    Mystring(); //No-args Constructor
    Mystring(const char* s); //Overloaded constructor
    Mystring(const Mystring &source); //Copy COnstructor
    Mystring(Mystring&& source); //Move constructor
    ~Mystring();//Destructor
    Mystring& operator=(const Mystring& rhs); //Copy assignment
    Mystring& operator=( Mystring&& rhs); //Move assignment
    
    Mystring operator-() const; // make lowercase
    Mystring operator+(const Mystring& rhs) const;//concatenate
    bool operator==(const Mystring& rhs) const;

    
    virtual void display() const;

    int get_length() const; //getters
    const char* get_str() const;
};

bool operator==(const Mystring& lhs, const Mystring& rhs){
    return(std::strcmp(lhs.str,rhs.str)==0);
}

//No-args constructor
Mystring::Mystring()
    :str{nullptr}{
        str = new char[1];
        *str = '\0';
    }

//Overloaded construcotr
Mystring::Mystring(const char* s)
    :str{nullptr}{
        if(s==nullptr){
            str = new char[1];
            *str = '\0';
        }else{
            str = new char[std::strlen(s)+1];
            std::strcpy(str,s);
        }
    }

//Constructor
Mystring::Mystring(const Mystring &source)
    :str{nullptr}{
        str = new char[std::strlen(source.str)+1];
        std::strcpy(str,source.str);
    }

//Destructor
Mystring::~Mystring(){
    if(str==nullptr){
        std::cout<<"Calling destructor for Mystring: nullptr"<<std::endl;
    }else{
        std::cout<<"Calling destructor for Mystring:"<<str<<std::endl;
    }
    delete [] str;

}

//Copy asssignment
Mystring& Mystring::operator=(const Mystring& rhs){
    std::cout<<"Copy assignment"<<std::endl;
    if(this==&rhs)
        return *this;
    delete [] str; // delete [] this -> str;
    str = new char[std::strlen(rhs.str)+1];
    std::strcpy(this->str,rhs.str);
    return *this;
}

//Display method
 void Mystring::display() const{
    std::cout<<str<<" : "<<get_length()<<std::endl;
}

//Move constructor 
Mystring::Mystring(Mystring&& source) //creating a new object based on an r-value
    :str(source.str){//I am taking the source object's pointer and moving it right to str
        source.str = nullptr;//nullifying the source object pointer
        std::cout<<"Move constructor used"<<std::endl;
        //We just stole the pointer, that other object will eventually be destroyed
    }

//Move assignment operator
Mystring& Mystring::operator=(Mystring&& rhs){
    std::cout<<"Using move assignment"<<std::endl;
    if(this==&rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str=nullptr;
    return *this;
}
//Equality
bool Mystring::operator==(const Mystring& rhs) const {
    return(std::strcmp(str,rhs.str)==0);
}

//Make lowercase
Mystring Mystring::operator-() const{
    char* buff = new char[std::strlen(str)+1];
    std:: strcpy(buff,str);
    for(size_t i=0;i<std::strlen(buff);i++)
        buff[i]=std::tolower(buff[i]);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

//Concatenate

Mystring Mystring::operator+(const Mystring& rhs) const{
    char* buff = new char[std::strlen(str)+std::strlen(rhs.str)+1];
    std::strcpy(buff,str);
    std::strcat(buff,rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

//getters
int Mystring::get_length() const {return strlen(str);}
const char *Mystring::get_str() const {return str;}


int main(){
    // Mystring a{"Hello"};  //overloaded constructor
    // Mystring b; //no-args constructor
    // b = a; //copy assignment
    //        //b.operator = (a)

    // b = "This is a test"; //b.operator = ("This is a test")
    // return 0;
    Mystring a{"Hello"}; //Overloaded constructor
    a = Mystring{"Hola"};//Overloaded constructor then move assignment
    a = "Bonjour"; //Overloaded constructor then move assignment
    
    Mystring empty;//no-args constructor
    Mystring larry("Larry"); //overloaded constructor
    Mystring stooge{larry}; //copy constructor
    Mystring stooges; //no-args constructor

    empty = stooge; //copy assignment operator , stooge is an l-value

    empty = "Funny"; //move assignment operator, "Funny" is an r-value

    empty.display();
    larry.display();
    stooge.display();
    empty.display();

    stooges = "Larry, Moe, and Curly";
    stooges.display();


}
