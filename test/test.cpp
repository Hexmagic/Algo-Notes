
bool less(int a, int b)
{
    return a <= b;
}
#include <iostream>

void test(bool(*cmp)(int,int)){
    std::cout << "Hello, world!" << std::endl;
    cmp(1,2);
}


int main(){
    test(less);
    std::cout << (nullptr==0)<<std::endl;
}