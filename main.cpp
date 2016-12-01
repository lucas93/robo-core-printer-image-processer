#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <assert.h>
using namespace std;

#include "ProcessedImage.h"
#include "simple_ostream_test.h"
#include "ImageProcesser.h"

#include "BitmapBoolImage.h"

#define DISP(VAR) cout << #VAR " = " << VAR << endl;
int lengthOfInt(int num)
{
    char buffer[10];
    return sprintf(buffer, "%d", num);
}

int numberOfCharactersInTextFile(const string& fileName)
{
    ifstream inMyStream (fileName);
    inMyStream.seekg(0,std::ios_base::end);
    std::ios_base::streampos end_pos = inMyStream.tellg();

    return end_pos;
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

void addNumberOfCharactersInFileToBeginningOfFile(const string& fileName)
{
    ofstream saveFile;

    int numberOfCharacters = numberOfCharactersInTextFile(fileName);
    numberOfCharacters += lengthOfInt(numberOfCharacters) + 1;

    string tempFileName = fileName + ".temp";
    copyFile(fileName, tempFileName);

    remove(fileName.c_str());
    saveFile.open(fileName);
    saveFile << (numberOfCharacters) << " ";
    saveFile.close();

    copyFile(tempFileName, fileName, true);

}


int main(int argc, char *argv[])
{
    assert(argc == 3);

    string bmpFileName{argv[1]};
    string RoboCoreFileName{argv[2]};

    auto baseImage = ImageProcesser().processImage(bmpFileName, RoboCoreFileName);

    auto loadedImg = ProcessedImageManager().loadProcessedImageFromTextFile(RoboCoreFileName);

    assert(baseImage == loadedImg);

//    string fileName = "savefile.txt";

//    addNumberOfCharactersInFileToBeginningOfFile(fileName);


    return 0;
}
