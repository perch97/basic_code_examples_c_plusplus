using namespace std;
#include <iostream>
//This class uses dynamic polymorphism for the withdraw method

class Account{
public:
     virtual void withdraw(double amount) {
        std::cout<<"In Account::witdraw"<<std::endl;
    }
    virtual ~Account(){std::cout<<"Account::destructor"<<std::endl;}
};

class Checking: public Account{
public:
     virtual void withdraw(double amount){
        std::cout<<"In Checking:: withdraw"<<std::endl;
    }
    virtual ~Checking(){std::cout<<"Checking::destructor"<<std::endl;}
};

class Savings: public Account{
     virtual void withdraw(double amount){
         std::cout<<"In Savings:: withdraw"<<std::endl;
    }
    virtual ~Savings(){std::cout<<"Savings::destructor"<<std::endl;}
};

class Trust: public Account{
public:
     virtual void withdraw(double amount){
        std::cout<<"In Trust:: withdraw"<<std::endl;
    }
    virtual ~Trust(){std::cout<<"Trust::destructor"<<std::endl;}
};

void do_withdraw(Account& account,double amount){
    account.withdraw(amount);
}

int main(){
    Account a;
    Account& ref =a;
    ref.withdraw(1000); //IN Account:: withdraw

    Trust t;
    Account& ref1 = t;
    ref1.withdraw(1000); //In Trust:: withdraw

    Account a1;
    Checking a3;
    Trust a4;

    do_withdraw(a1,1000);
    do_withdraw(a3,3000);
    do_withdraw(a4,4000);

}
