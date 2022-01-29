#include <string>
#include <iostream>
using namespace std;

int main(){
    std::string str = "Hello, world!";
    cout<<"strlen get len of word: "<<strlen(str.c_str())<<endl;
    char dst[16];
    strcpy(dst,str.c_str());
    cout<<"strcpy str to dst: "<<dst<<endl;
    std::string word = "world";
    auto ind = strstr(str.c_str(),word.c_str());
    cout<< ind<<endl;
}