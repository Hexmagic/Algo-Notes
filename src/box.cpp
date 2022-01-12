#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
using namespace std;
using namespace cv;
namespace fs = std::filesystem;

int main(int argc,char **argv){
    fs::path folder("data");
    for(auto &dir: fs::directory_iterator(folder)){
        cout << dir.path().string() << endl;
        string img_path = dir.path().string();
        Mat clr = imread(img_path);
        Mat emp = Mat::ones(Size(clr.cols, clr.rows), CV_8U) * 255;
        copyMakeBorder(emp, emp, 20, 20, 20, 20, BORDER_CONSTANT, Scalar(255, 255, 255));
        copyMakeBorder(clr, clr, 20, 20, 20, 20, BORDER_CONSTANT, Scalar(255, 255, 255));
        Mat img;
        cvtColor(clr, img, COLOR_RGB2GRAY);
        int W = img.cols;
        int H = img.rows;

        imshow("mini", clr);
        threshold(img, img, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
        auto ker = getStructuringElement(MORPH_ELLIPSE, Size(5,5));
        imshow("close", img);
        morphologyEx(img, img, MORPH_CLOSE, ker);
        resize(img, img, Size(W/4,H/4));
        GaussianBlur(img, img, Size(3, 3),1);
        imshow("mini", img);
        resize(img, img, Size(W, H));
        GaussianBlur(img, img, Size(3, 3),1);
        imshow("closeBig", img);
        threshold(img, img, 70, 255, THRESH_BINARY);


        vector<vector<Point>> contours;
        findContours(img,contours,RETR_TREE,CHAIN_APPROX_SIMPLE);

        for (int i = 0; i < contours.size(); i++)
        {
            int arcLen = arcLength(contours[i],false);
            float eps = arcLen * 0.0001;
            cout << contourArea(contours[i]) << endl;
            if (contourArea(contours[i])> 400){
                drawContours(clr, contours, i, Scalar(255, 0, 255), 1, LINE_AA);
                approxPolyDP(contours[i], contours[i], eps, false);
                drawContours(emp, contours, i, Scalar(0, 0, 0), 1, LINE_AA);
            }
        }
        imshow("img", img);
        imshow("clr", clr);
        imshow("empty", emp);
        waitKey(0);
    }

}
