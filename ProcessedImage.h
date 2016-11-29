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

    ProcessedImage loadProcessedImageFromSD(string &filename)
    {
        // TODO
        return ProcessedImage();
    }

    ProcessedImage loadProcessedImageFromTextFile(string &filename)
    {
        textFile.open(filename.c_str());

        int HEIGHT_MAX, WIDTH_MAX, numberOfRows;

        textFile >> HEIGHT_MAX;
        textFile >> WIDTH_MAX;

        textFile >> numberOfRows;
        auto img = ProcessedImage(numberOfRows);

        for (auto & row : img)
            row = getRow();

        textFile.close();
        return img;
    }

private:
    Row getRow()
    {
        int numberOfLines;
        textFile >> numberOfLines;

        auto row = Row(numberOfLines);

        for (auto & line : row)
        {
            line = getLine();
        }
        return row;
    }

    Line getLine()
    {
        Line::point_type a, b;

        textFile >> a;
        textFile >> b;

        return Line{ a, b };
    }
};


#endif //ROBOCOREPRINTERFRONT_IMAGE_H
