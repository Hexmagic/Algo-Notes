#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;
using namespace cv;
int main(int argc, char** argv){
    
    string test = "JellKey";
    string_view view(test.c_str(),test.size());
    unordered_map<string_view,int> a;
    auto key= view.substr(0,2);
    a[key]=1;
    
}