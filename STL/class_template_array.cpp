#include <iostream>
#include <string>
template <typename T, int N> // The user provides the n at compile time
class Array{
    int size{N};
    T values[N];

    friend std::ostream& operator<<(std::ostream& os, const Array<T,N>& arr){
        os<<"[";
        for(const auto& val: arr.values)
            os<<val<<" ";
        os<<"]"<<std::endl;
        return os;
    }
public:
    //A default constructor is a constructor which can be called with no arguments
    // (either defined with an empty parameter list,
    // or with default arguments provided for every parameter).
    Array()=default;
    Array(T init_val){
        for(auto& item: values)
            item=init_val;
    }
    void fill(T val){
        for(auto& item: values)
            item=val;
    }
    int get_size() const{
        return size;
    }

    //overloaded subscript operator for easy use

    T& operator[](int index){
        return values[index];
    }
};

int main(){
    Array<int,5> nums;
    std::cout<<"The size of nums is: "<<nums.get_size()<<std::endl;
    std::cout<<nums<<std::endl;

    nums.fill(0);
    std::cout<<"The size of nums is: "<<nums.get_size()<<std::endl;
    std::cout<<nums<<std::endl;

    nums.fill(10);
    std::cout<<nums<<std::endl;

    nums[0]=1000;
    nums[3]=2000;
    std::cout<<nums<<std::endl;

    Array<double,100> nums2{1};
    std::cout<<"The size of nums2 is: "<<nums2.get_size()<<std::endl;
    std::cout<<nums2<<std::endl;

    Array<std::string,10> strings(std::string{"Frank"});
    std::cout<<"The size of strings is: "<<strings.get_size()<<std::endl;
    std::cout<<strings<<std::endl;

    strings[0] = std::string{"Larry"};
    std::cout<<strings<<std::endl;

    strings.fill(std::string{"X"});
    std::cout<<strings<<std::endl;


}
