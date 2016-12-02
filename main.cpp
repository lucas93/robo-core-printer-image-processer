#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

#include "ProcessedImage.h"
#include "ImageProcesser.h"



int main(int argc, char *argv[])
{
    assert(argc == 5);

    string bmpFileName{argv[1]};
    string RoboCoreFileName{argv[2]};
    int WIDTH_MAX{ stoi(argv[3]) };
    int HEIGHT_MAX{ stoi(argv[4]) };

    ImageConverter processer(bmpFileName,
                             RoboCoreFileName,
                             WIDTH_MAX,
                             HEIGHT_MAX);
    auto baseImage = processer.ConvertAndSaveImage();


    // test
    auto loadedImg = ProcessedImageManager().loadProcessedImageFromTextFile(RoboCoreFileName);
    assert(baseImage == loadedImg);


    cout << "\nSuccesfully saved RoboCoreImage to file: "<< RoboCoreFileName << endl;

    return 0;
}
