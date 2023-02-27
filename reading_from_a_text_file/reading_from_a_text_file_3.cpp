//Read and display Sheakespeare Sonnet 18 using unformatted get

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
    char c;
    while(in_file.get(c)){ //  !in_file.eof()
        std::cout<<c;
    }
    
    std::cout<<"File is good to go"<<std::endl;
    in_file.close();
}

