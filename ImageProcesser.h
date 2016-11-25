#ifndef ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
#define ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H

#include <string>
#include "fstream"
#include "ProcessedImage.h"
#include "EasyBMP/EasyBMP.h"

using namespace std;

class ImageProcesser
{
private:
    class BMP_Image
    {
        BMP img;
    public:
        void loadBmpImage(string bmpImageFilaname)
        {
            img = BMP();
            img.ReadFromFile(bmpImageFilaname.c_str());
        }

        bool operator[](size_t )
    };

    BMP_Image img;
    ProcessedImage imageResult;
    int WIDTH_MAX = 310;
    int HEIGHT_MAX = 730;
    string bitmapSourceName;
    string processedImageTargetName;



public:
    ProcessedImage processImage(string bmpImageFilaname, string procesedImageFilename) // 1
    {
        prepareBmpImage(bmpImageFilaname);
        prepareResultImage();
        convertBmpImageToPairsOfLineBeginningAndEnd();
        fillResultWithPrevoiusAndNext();
        saveResultToFile(procesedImageFilename);
    }

private:

    void prepareBmpImage(string bmpImageFilaname) // 2
    {


    }

    void prepareResultImage() //  2
    {

    }

    void convertBmpImageToPairsOfLineBeginningAndEnd() // 2
    {

    }

    void fillResultWithPrevoiusAndNext() // 2
    {

    }

    void saveResultToFile(string basic_string) // 2
    {

    }
};


#endif //ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
