#ifndef ROBOCOREPRINTERFRONT_PAIR_H
#define ROBOCOREPRINTERFRONT_PAIR_H

#include <string>
using std::ostream;
using String = std::string;

struct Pair
{
    using Int = int16_t ;
    using type = Int;

    Int a;
    Int b;
    Int aNext;
    Int bPrevious;

    Pair() = default;
    Pair(Int a, Int b) : a(a), b(b) {}
    Pair(Int bPrevious, Int a, Int b, Int aNext)
            : bPrevious(bPrevious), a(a), b(b), aNext(aNext) {}
    bool operator==(const Pair& other) const
    {
        return a == other.a &&
               b == other.b &&
               bPrevious == other.bPrevious &&
               aNext == other.aNext;
    }

    bool isEmptyPair()
    {
        return (a == -1)
            || (b == -1)
            || (aNext == -1)
            || (bPrevious == -1);
    }

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

    static Pair getEmptyPair()
    {
        return Pair{-1, -1, -1, -1};
    }
};

ostream & operator<<(ostream & ostr, const Pair & pair)
{
    ostr << pair.bPrevious << " "
         << pair.a << " "
         << pair.b << " "
         << pair.aNext << " ";
    return ostr;
}

#endif //ROBOCOREPRINTERFRONT_PAIR_H