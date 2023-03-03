#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <iomanip>
template <typename T>
void display(const std::deque<T>& d){
    std::cout<<"[";
    for(const auto& elem: d)
        std::cout<<elem<<" ";
    std::cout<<"]"<<std::endl;
}

bool is_palindrome_1(const std::string& s){
    std::deque<char> d1;
    std::deque<char> d2;
    // std::cout<<"Use two deques comparison method"<<std::endl;
    for(const auto& c: s)
        if(std::isalpha(c)){
            d1.push_back(std::toupper(c));
            d2.push_front(std::toupper(c));
        }
    // display(d1);
    // display(d2);
    int k=0;
    for(int i=0;i<d1.size();i++)
        if(d1[i]==d2[i])
            k++;
        else
            return false;
     return k==d1.size();
}

bool is_palindrome_2(const std::string& s){
    //  std::cout<<"Use pop_front / pop_back method"<<std::endl;
    //while are more than 1 characters in the deque
    //remove and compare the fron character with the back character
    //if they are not the same - return false since it can't a palindrome
    std::deque<char> d1;
   for(char c: s){
      if(std::isalpha(c)){
            d1.push_back(std::toupper(c));
        }
    }
    while(d1.size()>1){
        char c1=d1.front();
        char c2=d1.back();
        d1.pop_back();
        d1.pop_front();
        if(c1!=c2)
            return false;
    }
    return true;
}
int main(){
    std::vector<std::string> test_strings{"a","aa","abba","abbcbba","ab","abc","radar","bob","ana"
    ,"avid diva","Amore, Roma","A Toyota's a toyota","A Santa at NASA","C++",
    "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!","This is a palindrome",
    "palindrome"};

    std::cout<<std::boolalpha;
    std::cout<<std::setw(8)<<std::left<<"Result"<<"String"<<std::endl;
    for(const auto& s: test_strings){
        std::cout<<std::setw(8)<<std::left<<is_palindrome_1(s)<<s<<std::endl;
    }
    std::cout<<"\nUse another function\n"<<std::endl;
    std::cout<<std::setw(8)<<std::left<<"Result"<<"String"<<std::endl;
    for(const auto& s: test_strings){
        std::cout<<std::setw(8)<<std::left<<is_palindrome_2(s)<<s<<std::endl;
    }

}

// OUTPUT:
// Result  String
// true    a
// true    aa
// true    abba
// true    abbcbba
// false   ab
// false   abc
// true    radar
// true    bob
// true    ana
// true    avid diva
// true    Amore, Roma
// true    A Toyota's a toyota
// true    A Santa at NASA
// true    C++
// true    A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!
// false   This is a palindrome
// false   palindrome

// Use another function

// Result  String
// true    a
// true    aa
// true    abba
// true    abbcbba
// false   ab
// false   abc
// true    radar
// true    bob
// true    ana
// true    avid diva
// true    Amore, Roma
// true    A Toyota's a toyota
// true    A Santa at NASA
// true    C++
// true    A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!
// false   This is a palindrome
// false   palindrome
