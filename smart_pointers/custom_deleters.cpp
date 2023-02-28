//Custom deleters
#include <iostream>
#include <memory>

class Test{
private:
    int data;
public:
    Test():data{0}{std::cout<<"\tTest constructor("<<data<<")"<<std::endl;}
    Test(int data):data{data}{std::cout<<"\tTest constructor("<<data<<")"<<std::endl;}
    int get_data() const {return data;}
    ~Test(){std::cout<<"\tTest destructor("<<data<<")"<<std::endl;}
};

void my_deleter(Test* ptr){//the raw pointer is being passed into my_deleter function and is being wrapped by shared pointer
    std::cout<<"\tUsing my custom function deleter"<<std::endl;
    delete ptr;
}

int main(){
    {
        std::shared_ptr<Test> ptr1 {new Test{100},my_deleter}; //shared pointer to a test object
        //when this pointer is deleted and it has to clean up the memory,
        // it's going to call the my_deleter fulction to do it
        // and we can have complete control of how to do it
    }

    std::cout<<"=================="<<std::endl;

    {
        //Using a Lambda expression
        std::shared_ptr<Test> ptr2 (new Test{100},
        [] (Test* ptr){
            std::cout<<"\tUsing my custom function deleter"<<std::endl;
            delete ptr;
        });
    }
}
