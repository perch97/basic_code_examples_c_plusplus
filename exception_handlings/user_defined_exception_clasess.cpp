//User-defined Exception Classes

#include <iostream>

class DevideByZeroException{};
class NegativeValueException{};

double calculate_mpg(int miles,int gallons){
    if(gallons == 0)
        throw DevideByZeroException();
    if(miles<0 || gallons<0)
        throw NegativeValueException();
    return static_cast<double>(miles)/gallons;
}

int main(){
    double miles{};
    double gallons{};
    double miles_per_gallon{};

    std::cout<<"Enter the miles driven: ";
    std::cin>>miles;
    std::cout<<"Enter the gallons used: ";
    std::cin>>gallons;

    try{
        miles_per_gallon = calculate_mpg(miles,gallons);
        std::cout<<"Result: "<<miles_per_gallon<<std::endl;
    }
    catch(const DevideByZeroException& ex){
        std::cerr<<"You can't devide by zero"<<std::endl;
    }
    catch(const NegativeValueException& ex){
        std::cerr<<"Sorry,one of your parameter is negative"<<std::endl;
    }
    std::cout<<"Bye"<<std::endl;
}
