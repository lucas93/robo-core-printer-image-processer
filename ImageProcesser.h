#ifndef ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
#define ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H

#include <string>
#include "ProcessedImage.h"
using namespace std;

class ImageProcesser
{
private:
    int WIDTH_MAX = 310;
    int HEIGHT_MAX = 730;
    string bitmapSourceName;
    string processedImageTargetName;

    ProcessedImage imageResult;

};


#endif //ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
