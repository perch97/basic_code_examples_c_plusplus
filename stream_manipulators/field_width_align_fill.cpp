#include <iostream>
#include <iomanip>

void ruler(){
    std::cout<<"\n1234567890123456789012345678901234567890"<<std::endl;
}

int main(){
    int num1 {1234};
    double num {1234.5678};
    std::string hello{"Hello"};
    std::cout<<"\n--Defaults----------------------------"<<std::endl;
    ruler();
    std::cout<<num1
             <<num 
             <<hello<<std::endl;  
    std::cout<<"\n--Defaults-one per line---------------"<<std::endl;
    ruler();
    std::cout<<num1<<std::endl;
    std::cout<<num<<std::endl;
    std::cout<<hello<<std::endl;  

    std::cout<<"\n--width 10 for num1--------------------------------------"<<std::endl;
    ruler();
    std::cout<<std::setw(10)<<num1<<num<<hello<<std::endl; //only affect num

    std::cout<<"\n--width 10 for num1 and num----------"<<std::endl;
    ruler();
    std::cout<<std::setw(10)<<num1
             <<std::setw(10)<<num
             <<hello<<std::endl;

    std::cout<<"\n--width 10 for num1 and num and hello----------"<<std::endl;
    ruler();
    std::cout<<std::setw(10)<<num1
             <<std::setw(10)<<num
             <<std::setw(10)<<hello<<std::endl;

    std::cout<<"\n--width 10 for num1 and num and hello left for all----------"<<std::endl;
    ruler();
    std::cout<<std::setw(10)<<std::left<<num1
             <<std::setw(10)<<std::left<<num
             <<std::setw(10)<<std::left<<hello<<std::endl;
    
    std::cout<<std::setfill('-');
    std::cout<<"\n--width 10 for num1 and num and hello left for all setfill to dash----------"<<std::endl;
    ruler();
    std::cout<<std::setw(10)<<std::left<<num1
             <<std::setw(10)<<std::left<<num
             <<std::setw(15)<<std::left<<hello
             <<std::endl;
   

    //Set width to 10 for all,left justify all and carry the setfill character
    std::cout<<"\n--width 10 for num1 and num and hello - setfill varies----------"<<std::endl;
    ruler();
    
    std::cout<<std::setw(10)<<std::left<<std::setfill('*')<<num1
             <<std::setw(10)<<std::left<<std::setfill('#')<<num
             <<std::setw(10)<<std::left<<std::setfill('-')<<hello
             <<std::endl;
}

// OUTPUT:
// --Defaults----------------------------

// 1234567890123456789012345678901234567890
// 12341234.57Hello

// --Defaults-one per line---------------

// 1234567890123456789012345678901234567890
// 1234
// 1234.57
// Hello

// --width 10 for num1--------------------------------------

// 1234567890123456789012345678901234567890
//       12341234.57Hello

// --width 10 for num1 and num----------

// 1234567890123456789012345678901234567890
//       1234   1234.57Hello

// --width 10 for num1 and num and hello----------

// 1234567890123456789012345678901234567890
//       1234   1234.57     Hello

// --width 10 for num1 and num and hello left for all----------

// 1234567890123456789012345678901234567890
// 1234      1234.57   Hello     

// --width 10 for num1 and num and hello left for all setfill to dash----------

// 1234567890123456789012345678901234567890
// 1234------1234.57---Hello----------

// --width 10 for num1 and num and hello - setfill varies----------

// 1234567890123456789012345678901234567890
// 1234******1234.57###Hello-----
