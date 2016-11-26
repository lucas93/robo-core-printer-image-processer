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
    class BitmapImage
    {
        using Bit = bool;
        using BitmapRow = vector<Bit>;
        using Bitmap = vector<BitmapRow>;

        BMP img;
        Bitmap booleanBitmap;

    public:

        void prepareBmpImage(string bmpImageFilaname)
        {
            loadBmpImage(bmpImageFilaname);
            convertBmpImageToBoolBitmap();
        }

        BitmapRow operator[](size_t index) { return booleanBitmap[index]; }

        int width() { return booleanBitmap[0].size(); }

        int height() { return booleanBitmap.size(); }

    private:

        void loadBmpImage(string bmpImageFilaname)
        {
            img.ReadFromFile(bmpImageFilaname.c_str());
        }
        void convertBmpImageToBoolBitmap()
        {
            int height = img.TellHeight();
            int width= img.TellWidth();

            booleanBitmap = Bitmap(height);

            for (int j = 0; j < height; ++j)
            {
                BitmapRow row(width);
                for (int i = 0; i < width; ++i)
                {
                    Bit bit;
                    auto pixelValue = img(i, j)->Red; //read each pixel
                    if (pixelValue == 0)
                        bit = true;
                    else
                        bit = false;

                    row[i] = bit;   // insert pixel to bool bitmap
                }
                booleanBitmap[j] = row;
            }

        }
    };

    BitmapImage img;
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
