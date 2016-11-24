#ifndef ROBOCOREPRINTERFRONT_IMAGE_H
#define ROBOCOREPRINTERFRONT_IMAGE_H

#include "Row.h"

using Image = std::vector<Row>;

/*ostream & operator<<(ostream & ostr, const Image & image)
{
    ostr << "<-------------------" << endl;
    for(const Row& row : image)
    {
        ostr << "-[";
        ostr << row;
        ostr << "]-";
    }
    ostr << ">-------------------" << endl;
    return ostr;
}*/

#endif //ROBOCOREPRINTERFRONT_IMAGE_H