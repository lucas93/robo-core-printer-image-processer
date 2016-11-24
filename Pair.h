#ifndef ROBOCOREPRINTERFRONT_PAIR_H
#define ROBOCOREPRINTERFRONT_PAIR_H

#include <string>
using std::ostream;
using String = std::string;

struct Pair
{
    using Int = int16_t ;
    Int a;
    Int b;
    Int aNext;
    Int bPrevious;

    Pair(Int a, Int b) : a(a), b(b) {}

    Int length() const
    {
        return b - a;
    }

    Int spaceAfter() const
    {
        return aNext - b;
    }

    Int spaceBefore() const
    {
        return a - bPrevious;
    }

    String toString()  const
    {
        String str = "a = ";
        str += a;
        str += "  b = ";
        str += b;
        str += "  len = ";
        str += length();

        return str;
    }

    static void serialize()
    {

    }
};

ostream & operator<<(ostream & ostr, const Pair & pair)
{
    ostr << "| "
         << bPrevious << ", "
         << a << ", "
         << b << ", "
         << aNext
            << " |";
    return ostr;
}

#endif //ROBOCOREPRINTERFRONT_PAIR_H