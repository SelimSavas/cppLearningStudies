#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    CascadeClassifier face_cascade;
    face_cascade.load("haarcascade_frontalface_default.xml"); // yüz tanıma verilerini yükle

    Mat image = imread("Aaron_Eckhart_0001.jpg"); // yüz tanıma yapılacak resmi yükle
    vector<Rect> faces;
    face_cascade.detectMultiScale(image, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

    for (size_t i = 0; i < faces.size(); i++)
    {
        rectangle(image, faces[i], Scalar(255, 0, 0), 2); // yüzlerin çevresine dikdörtgen çiz
    }

    imshow("Yüz Tanıma Uygulaması", image); // resmi göster

    waitKey(0); // bir tuşa basana kadar bekleyin

    return 0;
}
