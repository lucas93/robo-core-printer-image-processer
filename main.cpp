#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

#include "ProcessedImage.h"
#include "simple_ostream_test.h"
#include "ImageProcesser.h"

#include "BitmapBoolImage.h"

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


    BitmapBoolImage img;
    img.prepareBmpImage(filename);

    for(auto const & row : img)
    {
        for(auto const & pix : row)
        {
            cout << (pix ? "1" : " ") << " ";
        }
        cout << endl;
    }

    return 0;
}