#ifndef ROBOCOREPRINTERFRONT_ROW_H
#define ROBOCOREPRINTERFRONT_ROW_H

#include "Pair.h"
#include <vector>

using Row = std::vector<Pair>;

ostream & operator<<(ostream & ostr, const Row & row)
{
    ostr << row.size() << " ";
    for(const auto& pair : row)
    {
        ostr << pair;
    }
    return ostr;
}

#endif //ROBOCOREPRINTERFRONT_ROW_H