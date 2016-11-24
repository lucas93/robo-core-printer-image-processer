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
    fstream file;

public:
    void saveProcessedImageToFile(const ProcessedImage& img, string & filename)
    {
        ofstream file;
        file.open(filename.c_str());
        file << img;
        file.close();
    }

    ProcessedImage getProcessedImageFromFile(string & filename)
    {
        auto img = ProcessedImage();
        file.open(filename.c_str());

        int numberOfRows;
        file >> numberOfRows;
        img.reserve(numberOfRows);

        for (int i = 0; i < numberOfRows; ++i)
        {
            img.push_back(getRow());
        }

        file.close();
        return img;
    }

private:
    Row getRow()
    {
        auto row = Row();

        int numberOfPairs;
        file >> numberOfPairs;
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

        file >> bPrevious;
        file >> a;
        file >> b;
        file >> aNext;

        return { bPrevious, a, b, aNext };
    }
};


#endif //ROBOCOREPRINTERFRONT_IMAGE_H