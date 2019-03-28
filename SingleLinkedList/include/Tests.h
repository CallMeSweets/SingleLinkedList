#ifndef TESTS_H
#define TESTS_H

#include <sstream>
#include "Sequence.h"
#include "ErrorInformation.h"
#include "Split.h"

using namespace std;

namespace tests
{


        static ErrorInformation errorInformation;

        void constructors_test();  //
        void pushFrontBack_test();  //
        void popFrontBack_test();  //
        void clear_test();  //
        void remove_test(); //
        void insertAfter_test(); //
        void isEmpty_test(); //
        void size_test(); //
        void frontBack_test(); //
        void getElement_test();
        void contain_test(); //
        void split_test(); //

        void showReport(ostream &os);
};

#endif // TESTS_H
