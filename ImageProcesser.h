#ifndef ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
#define ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H

#include <string>
#include "fstream"
#include "ProcessedImage.h"
#include "BitmapBoolImage.h"

using namespace std;

class ImageProcesser
{
    BitmapBoolImage img;
    ProcessedImage imageResult;
    int WIDTH_MAX = 310;
    int HEIGHT_MAX = 730;
    string bitmapImageSourceName;
    string processedImageTargetName;

public:
    ProcessedImage processImage(const string& bmpImageFilaname, const string& procesedImageFilename) // 1
    {
        prepareBmpImage(bmpImageFilaname);
        prepareResultImage();
        convertBmpImageToProcessedImage();
        saveResultToFile(procesedImageFilename);
        return imageResult;
    }

private:

    void prepareBmpImage(const string &bmpImageFilaname) // 2
    {
        img.prepareBmpImage(bmpImageFilaname);
    }

    void prepareResultImage() //  2
    {
        const auto height = img.height();
        imageResult.reserve(height);
    }

    void convertBmpImageToProcessedImage() // 2
    {
        const auto height = img.height();

        for (int yy = 0; yy < height; ++yy) // for every line
        {
            Row row = createRowOfLines(yy);
            imageResult.push_back(row);
        }
    }


    void saveResultToFile(const string &procesedImageFilename) // 2
    {
        for (auto &row : imageResult)
        {
            cout << row.size() << " ";
            for (auto &line : row)
                cout << line << "  ";
            cout << endl;
        }
    }

    Row createRowOfLines(const int yy) // 3
    {
        Row row;
        const auto width = img.width();
        int a = 0, b = 0;

        for (int xx = 0; xx < width; ++xx)  // for every pixel
        {
            auto pixel = img[yy][xx];
            if( pixel )
            {
                a = xx++;

                while (isPixelBlack(xx, yy))
                    ++xx;

                b = --xx;
                row.emplace_back(a, b);
            }
        }
        return row;
    }

    bool isPixelBlack(int xx, int yy)
    {
        return xx < img.width() && img[yy][xx];
    }
};


#endif //ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
