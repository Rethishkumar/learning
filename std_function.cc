#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void foo(){
    std::cout << "in foo"  << std::endl;
}

class functor {
    public:
    void operator()(){
        std::cout << "in functor" << std::endl;
    }
};

void execute (const vector<function<void ()>>& fs){
    for (auto &f: fs){
        f();
    }
}

int main() {
    // your code goes here
    std::vector <function<void ()>> func_list;
    
    func_list.push_back(foo);
    functor functor_instance;
    func_list.push_back(functor_instance);
    func_list.push_back([] () 
        { std::cout << "in lambda" << std::endl;});
        
    execute(func_list);

    
    return 0;
}

