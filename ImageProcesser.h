#ifndef ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
#define ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H

#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include "fstream"
#include "ProcessedImage.h"
#include "BitmapBoolImage.h"

using namespace std;

class ImageProcesser
{
    BitmapBoolImage img;
    ProcessedImage imageResult;
    int WIDTH_MAX;
    int HEIGHT_MAX;
    string bmpImageFilaname;
    string procesedImageFilename;
    ofstream saveFile;

public:
    ImageProcesser(const string& bmpImageFilaname,
                   const string& procesedImageFilename,
                   int WIDTH_MAX,
                   int HEIGHT_MAX) :
                   bmpImageFilaname(bmpImageFilaname),
                   procesedImageFilename(procesedImageFilename),
                   WIDTH_MAX(WIDTH_MAX),
                   HEIGHT_MAX (HEIGHT_MAX)
    {}

    ProcessedImage ConvertAndSaveImage()// 1
    {
        prepare(bmpImageFilaname);
        convertBmpImageToProcessedImage();
        createMirrorOfImage(imageResult); // potrzebne by nie drukowało lustrzanego odbicia
        saveResultToFile(procesedImageFilename);
        return imageResult;
    }

private:

    void prepare(const string &bmpImageFilaname)
    {
        prepareBmpImage(bmpImageFilaname);
        prepareResultImage();
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

    void prepareBmpImage(const string &bmpImageFilaname) // 2
    {
        img.prepareBmpImage(bmpImageFilaname);
    }

    void prepareResultImage() //  2
    {
        const auto height = img.height();
        imageResult = ProcessedImage(height);
    }

    Row getRowOfLines(const int rowNumber) // 3
    {
        Row row;
        const auto width = img.width();

        const int y = rowNumber;
        for (int x = 0; x < width; ++x)
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

    ProcessedImage createMirrorOfImage(const ProcessedImage& sourceImage)
    {
        int height = sourceImage.size();
        ProcessedImage mirroredImage(height);

        std::transform(begin(sourceImage), end(sourceImage), begin(mirroredImage), [this](const Row & sourceRow)
        {
            int numberOfLines = sourceRow.size();
            Row mirroredRow(numberOfLines);
            std::transform(rbegin(sourceRow), rend(sourceRow), begin(mirroredRow), [this](const Line sourceLine)
            {
                auto mirrorA = WIDTH_MAX - sourceLine.b;
                auto mirrorB = WIDTH_MAX - sourceLine.a;

                return Line{ mirrorA, mirrorB };
            });

            return mirroredRow;
        });

        return mirroredImage;
    }
};


#endif //ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
