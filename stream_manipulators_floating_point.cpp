//Stream manipulators - Floating point manipulators
//scientific,setprecision,fixed,showpoint,showpos,uppercase

#include <iostream>
#include <iomanip>

int main(){
    double num1 {123456789.987654321};
    double num2 {1234.5678};
    double num3 {1234.0};

    //using default settings
    std::cout<<"--Defaults------------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;

    //Using precision 2
    std::cout<<std::setprecision(2);
    std::cout<<"--Precision 2---------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;

    //Using precision 5
    std::cout<<std::setprecision(5);
    std::cout<<"--Precision 5---------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;

    //Using precision 9
    std::cout<<std::setprecision(9);
    std::cout<<"--Precision 9---------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;

    //Using precision 3 and fixed
    std::cout<<std::setprecision(3)<<std::fixed;
    std::cout<<"--Precision 3-fixed---------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;

    //Using precision 3, fixed and scientific
    //Note precision is after the decimal
    std::cout<<std::setprecision(3)<<std::scientific;
    std::cout<<"--Precision 3- scientific---------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;

    //Same but display capital "E" in scientific

    std::cout<<std::setprecision(3)<<std::scientific<<std::uppercase;
    std::cout<<"--Precision 3-scientific-uppercase---------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;

    //Show '+' symbol for positive numbers

    std::cout<<std::setprecision(3)<<std::fixed<<std::showpos;
    std::cout<<"--Precision 3-fixed-showpos---------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;

    //Back to defaults
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout<<std::resetiosflags(std::ios::showpos);
    
    //Show trailing zeroes up to precision 10

    std::cout<<std::setprecision(10)<<std::showpoint;
    std::cout<<"--precision 10 - showpoint ----------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;

    //Back to defaults

    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout<<std::setprecision(6);
    std::cout<<std::resetiosflags(std::ios::showpoint);
    std::cout<<std::resetiosflags(std::ios::showpos);
    std::cout<<"--Back to defaults ----------------"<<std::endl;
    std::cout<<num1<<std::endl;
    std::cout<<num2<<std::endl;
    std::cout<<num3<<std::endl;
}



//OUTPUT:
// --Defaults------------------
// 1.23457e+08
// 1234.57
// 1234
// --Precision 2---------------
// 1.2e+08
// 1.2e+03
// 1.2e+03
// --Precision 5---------------
// 1.2346e+08
// 1234.6
// 1234
// --Precision 9---------------
// 123456790
// 1234.5678
// 1234
// --Precision 3-fixed---------------
// 123456789.988
// 1234.568
// 1234.000
// --Precision 3- scientific---------------
// 1.235e+08
// 1.235e+03
// 1.234e+03
// --Precision 3-scientific-uppercase---------------
// 1.235E+08
// 1.235E+03
// 1.234E+03
// --Precision 3-fixed-showpos---------------
// +123456789.988
// +1234.568
// +1234.000
// --precision 10 - showpoint ----------------
// 123456790.0
// 1234.567800
// 1234.000000
// --Back to defaults ----------------
// 1.23457E+08
// 1234.57
// 1234
