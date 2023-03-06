//Stack

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
//This function displays a queue of
// by repeatedly removing elements from the front
//Note that the queue is passed in value so
//we don't affect the passed in stack.

template <typename T>
void display(std::queue<T> q){
    std::cout<<"[";
    while(!q.empty()){
        T elem = q.front();
        q.pop();
        std::cout<<elem<<" ";
    }
    std::cout<<"]"<<std::endl;
 }

 int main(){
    std::queue<int> q;

    for(int i:{1,2,3,4,5})
        q.push(i);
    display(q);
    std::cout<<"Front: "<<q.front()<<std::endl;
    std::cout<<"Back: "<<q.back()<<std::endl;
    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);

    while(!q.empty())
        q.pop();
    display(q);

    std::cout<<"Size: "<<q.size()<<std::endl;

    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);

    std::cout<<"Front: "<<q.front()<<std::endl;
    std::cout<<"Back: "<<q.back()<<std::endl;

    q.front()=5;
    q.back()=5000;

    display(q);

    std::cout<<"Front: "<<q.front()<<std::endl;
    std::cout<<"Back: "<<q.back()<<std::endl;

    }

    // OUTPUT:
    // [1 2 3 4 5 ]
    // Front: 1
    // Back: 5
    // [1 2 3 4 5 100 ]
    // [3 4 5 100 ]
    // []
    // Size: 0
    // [10 100 1000 ]
    // Front: 10
    // Back: 1000
    // [5 100 5000 ]
    // Front: 5
    // Back: 5000  
