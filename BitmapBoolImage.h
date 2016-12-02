#ifndef ROBOCOREPRINTERIMAGECONVERTER_BITMAPBOOLIMAGE_H
#define ROBOCOREPRINTERIMAGECONVERTER_BITMAPBOOLIMAGE_H

#include <vector>
#include <string>
#include "EasyBMP/EasyBMP.h"
using namespace std;

// Trzyma jednobitowe zdjęcie w formie macierzy zer i jedynek
class BitmapBoolImage : private vector< vector<bool> >
{
    using Bit = bool;
    using BitmapRow = vector<Bit>;
    using Bitmap = vector<BitmapRow>;

BMP img;
public:
    using Bitmap::begin;
    using Bitmap::end;
    using Bitmap::cbegin;
    using Bitmap::cend;
    using Bitmap::operator[];

    void prepareBmpImage(string bmpImageFilaname)
    {
        loadBmpImage(bmpImageFilaname);
        convertBmpImageToBoolBitmap();
    }

    int width() const { return at(0).size(); }
    int height() const { return size(); }

private:
    void loadBmpImage(string bmpImageFilaname)
    {
        img.ReadFromFile(bmpImageFilaname.c_str());
    }
    void convertBmpImageToBoolBitmap()
    {
        int height = img.TellHeight();
        int width= img.TellWidth();

        reserve(height);

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
            push_back(row);
        }

    }
};

#endif //ROBOCOREPRINTERIMAGECONVERTER_BITMAPBOOLIMAGE_H
