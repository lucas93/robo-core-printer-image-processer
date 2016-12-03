#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

#include "ConvertedImage.h"
#include "Converter.h"

int main(int argc, char *argv[])
{
    assert(argc == 5);

    string bmpFileName{argv[1]};
    string RoboCoreFileName{argv[2]};
    int WIDTH_MAX{ stoi(argv[3]) };
    int HEIGHT_MAX{ stoi(argv[4]) };

    ImageConverter converter(bmpFileName,
                             RoboCoreFileName,
                             WIDTH_MAX,
                             HEIGHT_MAX);
    auto baseImage = converter.ConvertAndSaveImage();


    // test
    auto loadedImg = ConvertedImageManager().loadConvertedImageFromTextFile(RoboCoreFileName);
    assert(baseImage == loadedImg);


    cout << "\nSuccesfully saved RoboCoreImage to file: "<< RoboCoreFileName << endl;

    return 0;
}
