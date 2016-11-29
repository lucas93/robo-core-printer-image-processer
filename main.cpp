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
    assert(argc == 3);

    string bmpFileName{argv[1]};
    string RoboCoreFileName{argv[2]};


//    auto image1 = getSimpleProcessedImage();
//
//    ProcessedImageManager().saveProcessedImageTextToFile(image1, filename);
//
//    auto image2 = ProcessedImageManager().getProcessedImageFromTextFile(filename);

    auto baseImage = ImageProcesser().processImage(bmpFileName, RoboCoreFileName);

    auto loadedImg = ProcessedImageManager().loadProcessedImageFromTextFile(RoboCoreFileName);

    assert(baseImage == loadedImg);

    return 0;
}
