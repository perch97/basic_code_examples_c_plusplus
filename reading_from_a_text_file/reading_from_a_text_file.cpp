#include <iostream>
#include <fstream>
#include <iomanip>
int main(){
    std::ifstream in_file;
    std::string line;
    int num;
    double total;
    in_file.open("test.txt");
    if(!in_file){
        std::cerr<<"Problem opening file"<<std::endl;
        return 1;//std::exit(1);
    }

    while(in_file>>line>>num>>total){ //  !in_file.eof()
        
        std::cout<<std::setw(10)<<std::left<<line
        <<std::setw(10)<<num
        <<std::setw(10)<<total
        <<std::endl;
    }
    
    std::cout<<"File is good to go"<<std::endl;
    in_file.close();
}
