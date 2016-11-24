#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

#include "ProcessedImage.h"
#include "simple_ostream_test.h"

int main(int argc, char *argv[])
{
    assert(argc == 2);

    string filename{argv[1]};

    auto image1 = getSimpleProcessedImage();

    ProcessedImageManager().saveProcessedImageToFile(image1, filename);

    auto image2 = ProcessedImageManager().getProcessedImageFromFile(filename);

    cout << image1 << endl << endl;
    cout << image2;

    cout << "input "
         << (image1 == image2 ? "==" : "!=")
         << " output";
    return 0;
}