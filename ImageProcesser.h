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
    ofstream saveFile;

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
        imageResult = ProcessedImage(height);
    }

    void convertBmpImageToProcessedImage() // 2
    {
        int rowNumber = 0;

        for (auto & row : imageResult)
        {
            row = getRowOfLines(rowNumber);
            ++rowNumber;
        }
    }

    void saveResultToFile(const string &procesedImageFilename) // 2
    {
        saveFile.open(procesedImageFilename.c_str());


        saveValueToFile(WIDTH_MAX);
        saveValueToFile(HEIGHT_MAX);

        saveValueToFile(imageResult.size()); // number of rows (height)

        for (auto &row : imageResult)
        {
            saveValueToFile(row.size());    // number of lines in a row

            for (auto &line : row)
            {
                saveValueToFile(line.a);
                saveValueToFile(line.b);
            }
        }

        saveFile.close();
    }

    template <typename T>
    void saveValueToFile(T val)  // 3
    {
        saveFile << val << " ";
    }

    Row getRowOfLines(const int rowNumber) // 3
    {
        Row row;
        const auto width = img.width();

        for (int x = 0, y = rowNumber; x < width; ++x)
        {
            if( isPixelBlack(x, y) )
            {
                Line line = getCompleteLineStartingFromGivenPoint(x, y, row);
                row.emplace_back(line);
            }
        }
        return row;
    }

    Line getCompleteLineStartingFromGivenPoint( int& x, const int y, Row& row) // 4
    {
        Line::point_type a = x++;

        while (isPixelBlack(x, y) && isPixelInRange(x, y))
            ++x;

        Line::point_type b = --x;

        return Line{a, b};
    }

    bool isPixelBlack(int x, int y) // 5
    {
        return img[y][x];
    }

    bool isPixelInRange(int xx, int yy) // 5
    {
        return xx < img.width() &&
               yy < img.height();
    }
};


#endif //ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
