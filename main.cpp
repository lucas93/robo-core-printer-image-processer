#include <iostream>
#include "Image.h"

using namespace std;

int main()
{
    auto i = 1;

    auto pair1 = Pair{--i, ++i, ++i, ++i};
    auto pair2 = Pair{--i, ++i, ++i, ++i};
    auto pair3 = Pair{--i, ++i, ++i, ++i};
    auto pair4 = Pair{--i, ++i, ++i, ++i};
    auto pair5 = Pair{--i, ++i, ++i, ++i};
    auto pair6 = Pair{--i, ++i, ++i, ++i};
    auto pair7 = Pair{--i, ++i, ++i, ++i};
    auto pair8 = Pair{--i, ++i, ++i, ++i};
    auto pair9 = Pair{--i, ++i, ++i, ++i};

    auto row1 = Row{pair1, pair2, pair3};
    auto row2 = Row{pair4, pair5, pair6};
    auto row3 = Row{pair7, pair8, pair9};

    auto Image = {row1, row2, row3};

    cout << Image;
    return 0;
}