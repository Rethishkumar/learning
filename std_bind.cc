#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using namespace std::placeholders;

void foo(){
    std::cout << "in foo"  << std::endl;
}

void foo_one_arg(const string &one) {
    std::cout << "foo_one_arg: " << one << std::endl;
}

void foo_two_arg(const string &one, const string &two){
    std::cout << "foo_two_arg " << one << " " << two << std::endl; 
}

void execute (const vector<function<void ()>>& fs){
    for (auto &f: fs){
        f();
    }
}

int main() {
    // your code goes here
    std::vector <function<void ()>> func_list;
    
    func_list.push_back(foo);
    func_list.push_back(bind(foo_one_arg, "kunju"));
    
    function<void()> f1 = bind(foo_two_arg, "one", "two");
    func_list.push_back(f1);

    execute(func_list);


    auto f2 = bind(foo_two_arg, "one_1", _1);
    f2("two_1");

    auto f3 = bind(foo_two_arg, _1, "one_2");
    f3("two_2");
    
    return 0;
}

/*
Output:
in foo
foo_one_arg: kunju
foo_two_arg one two
foo_two_arg one_1 two_1
foo_two_arg two_2 one_2
*/
