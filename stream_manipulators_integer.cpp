#include<iostream>
#include<iomanip>
int main(){
    int num1{255};

    //Displaying using different bases
    std::cout<<"\n--------------------------------------"<<std::endl;
    std::cout<<std::showbase<<std::endl; //std::noshowbase
    std::cout<<std::oct<<num1<<std::endl; //0377, 0 is a prefix for octal
    std::cout<<std::dec<<num1<<std::endl; 
    std::cout<<std::hex<<num1<<std::endl; //0xff, 0x is a prefix for hexadecimal

    //Displaying showing the base prefix for hex,oct and dec 
    std::cout<<"\n--------------------------------------"<<std::endl;
    std::cout<<std::showbase<<std::endl; 
    std::cout<<std::oct<<num1<<std::endl; //0377, 0 is a prefix for octal
    std::cout<<std::dec<<num1<<std::endl; 
    std::cout<<std::hex<<num1<<std::endl; //0xff, 0x is a prefix for hexadecimal
    
    //Display hex value in uppercase
    std::cout<<"\n--------------------------------------"<<std::endl;
    std::cout<<std::uppercase<<std::endl;
    std::cout<<std::hex<<num1<<std::endl; //0xff, 0x is a prefix for hexadecimal

    //Display the positive sign in front of positive base 10 numbers
    int num2{-255};
    std::cout<<"\n--------------------------------------"<<std::endl;

    //setting using the set method
    std::cout.setf(std::ios::basefield);
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::showpos);
    std::cout.setf(std::ios::uppercase);



    //resetting to defaults
    std::cout<<std::resetiosflags(std::ios::basefield);
    std::cout<<std::resetiosflags(std::ios::showbase);
    std::cout<<std::resetiosflags(std::ios::showpos);
    std::cout<<std::resetiosflags(std::ios::uppercase);




    std::cout<<num1<<std::endl;//255
    std::cout<<num2<<std::endl;//-255

    std::cout<<std::showpos;

    std::cout<<num1<<std::endl;//+255
    std::cout<<num2<<std::endl;//-255


}
