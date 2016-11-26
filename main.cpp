#define private public

#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

#include "ProcessedImage.h"
#include "simple_ostream_test.h"
#include "ImageProcesser.h"



#define DISP(VAR) cout << #VAR " = " << VAR << endl;


int main(int argc, char *argv[])
{
    assert(argc == 2);

    string filename{argv[1]};

//    auto image1 = getSimpleProcessedImage();
//
//    ProcessedImageManager().saveProcessedImageTextToFile(image1, filename);
//
//    auto image2 = ProcessedImageManager().getProcessedImageFromTextFile(filename);


    ImageProcesser::BitmapImage img;
    img.prepareBmpImage(filename);

    for (int j = 0; j < img.height(); ++j) {
        for (int i = 0; i < img.width(); ++i) {
            cout << (img[j][i] ? "1" : " ") << " ";
        }
        cout << endl;
    }

    return 0;
}