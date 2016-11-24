#ifndef ROBOCOREPRINTERFRONT_IMAGE_H
#define ROBOCOREPRINTERFRONT_IMAGE_H

#include "Row.h"

using Image = std::vector<Row>;

ostream & operator<<(ostream & ostr, const Image & image)
{
    ostr << "<\n";
    for(const Row& row : image)
    {
        ostr << "[";
        ostr << row;
        ostr << "]\n";
    }
    ostr << ">";
    return ostr;
}

#endif //ROBOCOREPRINTERFRONT_IMAGE_H