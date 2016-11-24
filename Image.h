#ifndef ROBOCOREPRINTERFRONT_IMAGE_H
#define ROBOCOREPRINTERFRONT_IMAGE_H

#include "Row.h"

using ProcessedImage = std::vector<Row>;

ostream & operator<<(ostream & ostr, const ProcessedImage & image)
{
    ostr << image.size() << "\n";
    for(const Row& row : image)
    {
        ostr << row << "\n";
    }
    return ostr;
}


class ProcessedImageManager
{
private:
    static ifstream file;

public:
    static void saveProcessedImageToFile(const ProcessedImage& img, string & filename)
    {
        ofstream file;
        file.open(filename.c_str());
        file << img;
        file.close();
    }

    static ProcessedImage getProcessedImageFromFile(string & filename)
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

        return img;
    }

private:
    static Row getRow()
    {
        auto row = Row();

        int numberOfPairs;
        file >> numberOfPairs;
        row.reserve(numberOfPairs);

        for (int i = 0; i < numberOfPairs; ++i)
        {

        }

    }
};


#endif //ROBOCOREPRINTERFRONT_IMAGE_H