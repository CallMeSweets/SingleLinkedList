#include <iostream>

#include "Sequence.h"
#include "Split.h"
#include "Tests.h"

using namespace std;

int main()
{






    tests::constructors_test();
    tests::pushFrontBack_test();
    tests::popFrontBack_test();
    tests::clear_test();
    tests::contain_test();
    tests::isEmpty_test();
    tests::size_test();
    tests::remove_test();
    tests::insertAfter_test();
    tests::frontBack_test();
    tests::getElement_test();
    tests::split_test();

    tests::showReport(cout);
    return 0;
}
