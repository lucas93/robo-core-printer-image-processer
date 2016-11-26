#ifndef ROBOCOREPRINTERFRONT_IMAGE_H
#define ROBOCOREPRINTERFRONT_IMAGE_H

#include "Row.h"

using ProcessedImage = std::vector<Row>;

ostream & operator<<(ostream & ostr, const ProcessedImage & image)
{
    ostr << image.size() << "\n";
    for(const auto& row : image)
    {
        ostr << row << "\n";
    }
    return ostr;
}

class ProcessedImageManager
{
private:
    fstream textFile;

public:
    void saveProcessedImageTextToFile(const ProcessedImage &img, string &filename)
    {
        ofstream file;
        file.open(filename.c_str());
        file << img;
        file.close();
    }

    ProcessedImage getProcessedImageFromSD(string &filename)
    {
        return ProcessedImage();
    }

    ProcessedImage getProcessedImageFromTextFile(string &filename)
    {
        auto img = ProcessedImage();
        textFile.open(filename.c_str());

        int numberOfRows;
        textFile >> numberOfRows;
        img.reserve(numberOfRows);

        for (int i = 0; i < numberOfRows; ++i)
        {
            img.push_back(getRow());
        }

        textFile.close();
        return img;
    }

private:
    Row getRow()
    {
        auto row = Row();

        int numberOfPairs;
        textFile >> numberOfPairs;
        row.reserve(numberOfPairs);

        for (int i = 0; i < numberOfPairs; ++i)
        {
            row.push_back(getPair());
        }
        return row;
    }

    Pair getPair()
    {
        using Int = Pair::Int;

        Int bPrevious, a, b, aNext;

        textFile >> bPrevious;
        textFile >> a;
        textFile >> b;
        textFile >> aNext;

        return { bPrevious, a, b, aNext };
    }
};


#endif //ROBOCOREPRINTERFRONT_IMAGE_H