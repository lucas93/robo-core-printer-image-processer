#ifndef ROBOCOREPRINTERFRONT_ROW_H
#define ROBOCOREPRINTERFRONT_ROW_H

#include "Line.h"
#include <vector>

using Row = std::vector<Line>;

ostream & operator<<(ostream & ostr, const Row & row)
{
    ostr << row.size() << " ";
    for(const auto& line : row)
        ostr << line;

    return ostr;
}

#endif //ROBOCOREPRINTERFRONT_ROW_H
