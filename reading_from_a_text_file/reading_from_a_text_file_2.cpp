//Read and display Shakespeare Sonnet 18 poem using getline
#include <iostream>
#include <fstream>
#include <iomanip>
int main(){
    std::ifstream in_file;
    in_file.open("poem.txt");
    if(!in_file){
        std::cerr<<"Problem opening file"<<std::endl;
        return 1;//std::exit(1);
    }
    std::string line{};
    while(std::getline(in_file,line)){ 
        std::cout<<line<<std::endl;
    }
    
    std::cout<<"File is good to go"<<std::endl;
    in_file.close();
}
