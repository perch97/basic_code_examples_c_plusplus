#include <iostream>
#include <memory>
#include <vector> 


int main(){
    std::shared_ptr<int> p1 { new int{100}};
    std::cout<<p1.use_count()<<std::endl; // the number of shared_ptr objects managing the heap object
    std::cout<<*p1<<std::endl; //100
    
    std::shared_ptr<int> p2 {p1}; // use copy constructor to initialize p1; We could not do this with unique pointer
    std::cout<<p1.use_count()<<std::endl; //2

    p1.reset();// decrement the use_count; p1 is nulled out;
    std::cout<<p1.use_count()<<std::endl;//0
    std::cout<<p2.use_count()<<std::endl; //1

    std::vector<std::shared_ptr<int>> vec;
    std::shared_ptr<int> ptr {new int{100}};
    vec.push_back(ptr);
    std::cout<<ptr.use_count()<<std::endl;//2

    //Better (preferred) way to initialize shared pointer
    // the make_shared function returns a shared pointer of the specified type
    // It allows us to pass initialization values into the constructor for the managed object
    // This creates a data sctructure that holds information about the reference count, the raw pointer,
    // the actual heap object and other data as well.
     std::shared_ptr<int> p3 = std::make_shared<int>(100);
    
     std::shared_ptr<int> p4 {p3}; // create p4 as a shared pointer to an int and use its copy constructor to initialize it to p3;
    
     //p3 and p4 refer to the same object on the heap
    
     std::shared_ptr<int> p5; //initializes as empty, it doesn't point to any shared object yet
    
    // there is no chances that we can have an uninitialized or a wild pointer when we use smart pointers

    p5=p3;

    //p4 and p5 will be destroyed before p3
}
