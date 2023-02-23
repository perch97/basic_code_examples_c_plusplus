#include <iostream>
#include <string>
// using namespace std;

class Base{
private:
    int value;
public:
    Base():value{0}{std::cout<<"Base no-args constructor"<<std::endl;}
    Base(int x):value{x}{std::cout<<"Base (int) overloaded constructor"<<std::endl;}
    ~Base(){std::cout<<"Base destructor"<<std::endl;}
    //Copy constructor
    Base(const Base& other)
        :value{other.value}{
            std::cout<<"Base copy constructor"<<std::endl;
        }
    //operator=
    Base& operator=(const Base& rhs){
        std::cout<<"Base operator="<<std::endl;
            if(this==&rhs)
                return *this;
            value = rhs.value;
            return *this;
    }

    };

class Derived:public Base{
private:
    int doubled_value;
public:
    Derived()
        :Base{},doubled_value{0}{std::cout<<"Derived no-args constructor"<<std::endl;}
    Derived(int x):Base{x}, doubled_value{x*2}{std::cout<<"Derived(int) overloaded constructor"<<std::endl;}
    ~Derived(){
        std::cout<<"Derived destructor"<<std::endl;
    }
};

class Account{
    friend std::ostream &operator<< (std::ostream& os, const Account& account);
protected:
    double balance;
public:
    Account();
    Account(double balance);
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
};
//Constructor
Account::Account()
    :Account(0.0){
       //Delegating constructor 
    }
Account::Account(double balance)
    :balance(balance){
    }

 void Account::deposit(double amount){
    balance+=amount;
}

 void Account::withdraw(double amount){
    if(balance-amount>=0)
       balance-=amount;
    else
        std::cout<<"Insufficient balance"<<std::endl;
}

std::ostream& operator<< (std::ostream& os, const Account& account){
    os<<"Account balance: "<<account.balance;
    return os;
}

class Savings_Account: public Account{
    friend std::ostream &operator<<(std::ostream& os, const Savings_Account& account);
protected:
    double int_rate;
public:
    Savings_Account();
    Savings_Account(double balance,double int_rate);
    virtual void deposit(double amount);
    //Withdraw is inherited
};

Savings_Account::Savings_Account(double balance, double int_rate)
    :Account(balance), int_rate{int_rate}{

    }

Savings_Account::Savings_Account()
    :Savings_Account{0.0,0.0}{

    }

 void Savings_Account::deposit(double amount){
    amount = amount + (amount*int_rate/100);
    Account::deposit(amount);
}

std::ostream &operator<<(std::ostream& os, const Savings_Account& account){
    os<<"Savings account balance: "<<account.balance<<" Interest rate: "<<account.int_rate;
    return os;
}

int main(){
    Account a1{1000.0};
    std::cout<<a1<<std::endl;

    a1.deposit(500.0);
    std::cout<<a1<<std::endl;

    a1.withdraw(1000);
    std::cout<<a1<<std::endl;

    a1.withdraw(5000.0);
    std::cout<<a1<<std::endl;

    std::cout<<"=============="<<std::endl;

    Savings_Account s1{1000,5.0};
    std::cout<<s1<<std::endl;

    s1.deposit(1000);
    std::cout<<s1<<std::endl;

    s1.withdraw(2000);
    std::cout<<s1<<std::endl;

    s1.withdraw(1000);
    std::cout<<s1<<std::endl;

}
