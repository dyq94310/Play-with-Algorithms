#include <iostream>
#include <sstream>
#include "UnionFindTestHelper.h"
#include "QuickUnion.h"

int main() {
    UnionFindTestHelper::TestUf(100000);
    UnionFindTestHelper::TestQU(100000);

//    UnionFindQuickUnion::QuickUnion quickUnion = UnionFindQuickUnion::QuickUnion(10);
//    quickUnion.unionElements(1, 2);
//    bool is = quickUnion.connected(1, 2);
//    ostringstream os1;
//    os1 << is;
//    cout << ":" + string(os1.str()) << endl;

    return 0;
}