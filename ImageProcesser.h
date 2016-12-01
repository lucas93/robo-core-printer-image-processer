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
    int WIDTH_MAX = 220;
    int HEIGHT_MAX = 270;
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

        //addNumberOfCharactersInFileToBeginningOfFile(procesedImageFilename);
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

    void addNumberOfCharactersInFileToBeginningOfFile(const string& fileName)
    {
        int numberOfCharacters = numberOfCharactersInTextFile(fileName);
        numberOfCharacters += lengthOfInt(numberOfCharacters) + 1;

        string tempFileName = fileName + ".temp";
        copyFile(fileName, tempFileName);

        remove(fileName.c_str());
        saveFile.open(fileName);
        saveValueToFile(numberOfCharacters);
        saveFile.close();

        appendToFile(tempFileName, fileName);
        remove(tempFileName.c_str());
    }

    void copyFile(const string& source, const string& target, bool append = false )
    {
        ifstream in(source);
        ofstream out;

        if(append)
            out.open(target, std::ios_base::app);
        else
            out.open(target);

        string str;
        while(getline(in,str))
        {
            out<<str;
        }
        in.close(); // <---
        out.close(); // <---
    }

    void appendToFile(const string& source, const string& target )
    {
        copyFile(source, target, true);
    }

    int numberOfCharactersInTextFile(const string& fileName)
    {
        ifstream inMyStream (fileName);
        inMyStream.seekg(0,std::ios_base::end);
        std::ios_base::streampos end_pos = inMyStream.tellg();

        return end_pos;
    }

    int lengthOfInt(int num)
    {
        char buffer[10];
        return sprintf(buffer, "%d", num);
    }
};


#endif //ROBOCOREPRINTERIMAGECONVERTER_IMAGEPROCESSER_H
