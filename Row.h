#ifndef ROBOCOREPRINTERFRONT_ROW_H
#define ROBOCOREPRINTERFRONT_ROW_H

#include "Pair.h"
#include <vector>

using Row = std::vector<Pair>;

ostream & operator<<(ostream & ostr, const Row & row)
{
    for(const Pair& pair : row)
    {
        ostr << pair;
    }
    return ostr;
}

#endif //ROBOCOREPRINTERFRONT_ROW_H