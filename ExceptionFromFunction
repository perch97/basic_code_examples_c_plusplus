//Throwing an Exception from a Function
#include <iostream>
double calculate_mpg(int miles, int gallons){
    if(gallons ==0)
        throw 0;
    return static_cast<double>(miles)/gallons;
}

int main(){
    double miles{};
    double gallons{};
    double miles_per_gallon {};
    std::cout<<"Enter the miles drivens: ";
    std::cin>>miles;
    std::cout<<"Enter the gallons used: ";
    std::cin>>gallons;
    try{
        miles_per_gallon = calculate_mpg(miles,gallons);
        std::cout<<"Result: "<<miles_per_gallon<<std::endl;
    }
    catch(int& ex){
        std::cerr<<"Sorry, you can't devide by zero"<<std::endl;
    }
    
    std::cout<<"Bye"<<std::endl;
}
