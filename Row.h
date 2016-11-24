#ifndef ROBOCOREPRINTERFRONT_ROW_H
#define ROBOCOREPRINTERFRONT_ROW_H

#include "Pair.h"
#include <vector>

using Row = std::vector<Pair>;

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

#endif //ROBOCOREPRINTERFRONT_ROW_H