#ifndef ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
#define ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H

#include <string>
#include "fstream"
#include "ProcessedImage.h"
#include "BitmapBoolImage.h"

using namespace std;

class ImageProcesser {
private:
    BitmapBoolImage img;
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

    void convertBmpImageToPairsOfLineBeginningAndEnd() // 2
    {
        const auto height = img.height();
        const auto width = img.width();

        for (int yy = 0; yy < height; ++yy) // for every line
        {
            Row row = createRowOfPairs(yy);


            imageResult.push_back(row);
        }
    }

    void fillResultWithPrevoiusAndNext() // 2
    {
        for (auto & row : imageResult)
        {
            fillFirstElementOfRow(row);
            fillMiddleElementsOfRow(row);
            fillLastElementOfRow(row);
        }
    }

    void saveResultToFile(const string &procesedImageFilename) // 2
    {
        for (auto &row : imageResult)
        {
            for (auto &pair : row)
                cout << pair << "  ";
            cout << endl;
        }
    }

    Row createRowOfPairs(const int yy) // 3
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
                while (xx < width && img[yy][xx])
                {
                    ++xx;
                }
                b = --xx;
                row.emplace_back(a, b);
            }
        }
        if( row.empty())
            row.emplace_back(Pair::getEmptyPair());
        return row;
    }

    void fillFirstElementOfRow(Row &row) const // 3
    {
        if( row[0].isEmptyPair() == false)
        {
            if( row.size() > 1 )
                row[0].aNext = row[1].a;
            else
                row[0].aNext = img.width() - 1;

            row[0].bPrevious = 0;
        }
    }

    void fillMiddleElementsOfRow(Row &row) // 3
    {
        if( row.size() > 2 )
            for (int k = 1; k < row.size() - 1; ++k)
            {
                row[k].aNext = row[k + 1].a;
                row[k].bPrevious = row[k - 1].b;
            }
    }

    void fillLastElementOfRow(Row &row) // 3
    {
        if( row.size() > 1 )
        {
            auto lastElement = row.size() - 1;
            row[lastElement].aNext = img.width() - 1;
            row[lastElement].bPrevious = row[lastElement - 1].b;
        }
    }
};


#endif //ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
