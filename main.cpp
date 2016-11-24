#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

#include "Image.h"
#include "simple_ostream_test.h"

int main(int argc, char *argv[])
{
    assert(argc == 2);

    string arg1{argv[1]};

    auto image = getSimpleProcessedImage();

    saveProcessedImageToFile(image, arg1);

    cout << image;
    return 0;
}