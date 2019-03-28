#include "Tests.h"


using namespace std;

void tests::constructors_test(){
    Sequence<int, int> tested_sequence;
    if(!tested_sequence.isEmpty())
        tests::errorInformation.addError("isEmpty() error constructor test");

    if(tested_sequence.size())
        tests::errorInformation.addError("size() error constructor test");

}

void tests::showReport(ostream &os){
    tests::errorInformation.showReport(os);
}

void tests::pushFrontBack_test(){
        Sequence<int, int> tested_sequence;

        tested_sequence.pushBack(3, 100);
        tested_sequence.pushBack(4, 200);
        tested_sequence.pushBack(5, 300);

        if(tested_sequence.isEmpty()){
            tests::errorInformation.addError("incorrect adding elements, list is Empty, pushBack method");
        }

        if(tested_sequence.size() != 3){
            tests::errorInformation.addError("incorrect adding elements, wrong size, pushBack method");
        }

        tested_sequence.pushFront(2, 200);
        tested_sequence.pushFront(1, 300);

        if(tested_sequence.size() != 5){
            tests::errorInformation.addError("incorrect adding elements, wrong size, pushFront method");
        }

        stringstream os;
        stringstream osOutPut("1 300\n2 200\n3 100\n4 200\n5 300\n");
        os << tested_sequence;
        if(osOutPut.str() != os.str()){
           tests::errorInformation.addError("incorrect operator << ");
        }

}

void tests::popFrontBack_test(){
        Sequence<int, int> tested_sequence;

        tested_sequence.pushBack(1, 100);
        tested_sequence.pushBack(2, 200);
        tested_sequence.pushBack(3, 300);
        tested_sequence.pushBack(4, 400);
        tested_sequence.pushBack(5, 500);

        tested_sequence.popBack();
        tested_sequence.popBack();


        if(tested_sequence.size() != 3){
            tests::errorInformation.addError("incorrect removing elements, popBack method");
        }

        stringstream os;
        stringstream osOutPut("1 100\n2 200\n3 300\n");
        os << tested_sequence;
        if(osOutPut.str() != os.str()){
           tests::errorInformation.addError("incorrect popBack method");
        }

        tested_sequence.popFront();
        tested_sequence.popFront();

        if(tested_sequence.size() != 1){
            tests::errorInformation.addError("incorrect removing elements, popFront method");
        }

        stringstream os2;
        stringstream osOutPut2("3 300\n");
        os2 << tested_sequence;
        if(osOutPut2.str() != os2.str()){
           tests::errorInformation.addError("incorrect popFront method");
        }


}

void tests::clear_test(){

    Sequence<int, int> tested_sequence;

        tested_sequence.pushBack(1, 100);
        tested_sequence.pushBack(2, 200);
        tested_sequence.pushBack(3, 300);
        tested_sequence.pushBack(4, 400);
        tested_sequence.pushBack(5, 500);

        tested_sequence.clear();

        if(tested_sequence.size() != 0){
            tests::errorInformation.addError("incorrect clearing lists, clear method");
        }

        stringstream os;
        os << tested_sequence;
        string outPut = os.str();
        if(outPut != ""){
            tests::errorInformation.addError("incorrect clearing lists, clear method operator <<");
        }

}

void tests::contain_test(){

    Sequence<int, int> tested_sequence;
        tested_sequence.pushBack(1, 100);
        tested_sequence.pushBack(2, 200);
        tested_sequence.pushBack(2, 300);
        tested_sequence.pushBack(3, 300);
        tested_sequence.pushBack(3, 400);
        tested_sequence.pushBack(3, 500);

        int numOfElements = 0;
        numOfElements = tested_sequence.contain(1);
        if(numOfElements != 1){
            tests::errorInformation.addError("test 1, contain method");  // test 1
        }

        numOfElements = 0;
        numOfElements = tested_sequence.contain(2);
        if(numOfElements != 2){
            tests::errorInformation.addError("test 2, contain method");  // test 1
        }

        numOfElements = 0;
        numOfElements = tested_sequence.contain(3);
        if(numOfElements != 3){
            tests::errorInformation.addError("test 3, contain method");  // test 1
        }

        numOfElements = 0;
        numOfElements = tested_sequence.contain(4);
        if(numOfElements != 0){
            tests::errorInformation.addError("test 4, contain method");  // test 1
        }

}

void tests::isEmpty_test(){

     Sequence<int, int> tested_sequence;
        tested_sequence.pushBack(1, 100);
        tested_sequence.pushBack(2, 200);
        tested_sequence.pushBack(2, 300);
        tested_sequence.pushBack(3, 300);
        tested_sequence.pushBack(3, 400);
        tested_sequence.pushBack(3, 500);

    if(tested_sequence.isEmpty() == true){
       tests::errorInformation.addError("test 1, isEmpty method");  // test 1
    }

    tested_sequence.clear();

    if(tested_sequence.isEmpty() != true){
       tests::errorInformation.addError("test 2, isEmpty method");  // test 2
    }

}

void tests::size_test(){

    Sequence<int, int> tested_sequence;
        tested_sequence.pushBack(1, 100);
        tested_sequence.pushBack(2, 200);
        tested_sequence.pushBack(3, 300);
        tested_sequence.pushBack(4, 400);
        tested_sequence.pushBack(5, 500);


    if(tested_sequence.size() != 5){
       tests::errorInformation.addError("test 1, size method");  // test 1
    }

    tested_sequence.pushBack(6, 600);
    if(tested_sequence.size() != 6){
       tests::errorInformation.addError("test 2, size method");  // test 2
    }

    tested_sequence.pushFront(7, 700);
    if(tested_sequence.size() != 7){
       tests::errorInformation.addError("test 3, size method");  // test 3
    }

    tested_sequence.popBack();
    tested_sequence.popBack();
    tested_sequence.popBack();
    if(tested_sequence.size() != 4){
       tests::errorInformation.addError("test 4, size method");  // test 4
    }

    tested_sequence.popFront();
    tested_sequence.popFront();
    if(tested_sequence.size() != 2){
       tests::errorInformation.addError("test 5, size method");  // test 5
    }

}

void tests::remove_test(){
    Sequence<int, int> tested_sequence;
        tested_sequence.pushBack(1, 100);
        tested_sequence.pushBack(2, 200);
        tested_sequence.pushBack(2, 300);
        tested_sequence.pushBack(2, 400);
        tested_sequence.pushBack(3, 300);
        tested_sequence.pushBack(4, 400);
        tested_sequence.pushBack(5, 500);



        if(tested_sequence.remove(1,-2)){
            tests::errorInformation.addError("test 1, remove method, removing element with index < 1");  // test 1
        }


        if(tested_sequence.remove(1,2)){
            tests::errorInformation.addError("test 2, remove method, removing element which not exist");  // test 2
        }

        if(!tested_sequence.remove(1)){
            tests::errorInformation.addError("test 3, remove method, element with default index not removed");  // test 3
        }


        if(!tested_sequence.remove(2,3)){
            tests::errorInformation.addError("test 4, remove method, element not removed");  // test 4
        }

        // check outPut

}

void tests::insertAfter_test(){
    Sequence<int, int> tested_sequence;
        tested_sequence.pushBack(1, 100);
        tested_sequence.pushBack(2, 200);

        tested_sequence.insertAfter(6,600,1,1);

        stringstream os;
        os << tested_sequence;
        stringstream osOutPut("1 100\n6 600\n2 200\n");

        if(os.str() != osOutPut.str()){
           tests::errorInformation.addError("test 1, insert after method");   // test 1
        }
}

void tests::frontBack_test(){
    Sequence<int, int> tested_sequence;
        tested_sequence.pushBack(1, 100);
        tested_sequence.pushBack(2, 200);
        tested_sequence.pushBack(3, 300);
        tested_sequence.pushBack(4, 400);
        tested_sequence.pushBack(5, 500);

        if(tested_sequence.front() != 100){
            tests::errorInformation.addError("test 1, front method");   // test 1
        }

        if(tested_sequence.back() != 500){
            tests::errorInformation.addError("test 2, back method");   // test 2
        }

}

void tests::getElement_test(){
    Sequence<int, int> tested_sequence;

    tested_sequence.pushBack(3, 100);
    tested_sequence.pushBack(4, 200);
    tested_sequence.pushBack(5, 300);

    try{
        tested_sequence.getElement(4, -5);
    }catch(exception &e){
        if((string)e.what() != "Negative parameter!"){
             tests::errorInformation.addError("test 1, getElement method, negative parameter");   // test 1
        }
    }

    try{
        tested_sequence.getElement(4, 5);
    }catch(exception &e){
        if((string)e.what() == "There is less object with that KEY than your parameter or object with that KEY not exist!"){
             tests::errorInformation.addError("test 2, getElement method, WHICH parameter is greater than number of element with that KEY");   // test 2
        }
    }

    try{
        tested_sequence.getElement(55, 5);
    }catch(exception &e){
        if((string)e.what() == "There is less object with that KEY than your parameter or object with that KEY not exist!"){
             tests::errorInformation.addError("test 3, getElement method, element with that KEY not exist");   // test 3
        }
    }


}

void tests::split_test(){
    Sequence<int,int> *seq1 = new Sequence<int, int>();
    Sequence<int,int> *seq2 = new Sequence<int, int>();
    Sequence<int,int> *seq3 = new Sequence<int, int>();


    try{
        Split(*seq1, 1, *seq2, 2, *seq3, 2);
    }catch(exception &e){
        if((string)e.what() != "Empty source!"){
             tests::errorInformation.addError("test 1, split method, Empty Source List");   // test 1
        }
    }

    seq1->pushBack(1, 100);
    seq1->pushBack(2, 200);
    seq1->pushBack(3, 300);
    seq1->pushBack(4, 400);
    seq1->pushBack(5, 500);
    seq1->pushBack(6, 600);
    seq1->pushBack(7, 700);
    seq1->pushBack(8, 800);
    seq1->pushBack(9, 900);

    // test 1 checking negative argument for start
    try{
        Split(*seq1, -2, *seq2, 2, *seq3, 2);
    }catch(exception &e){
        if((string)e.what() != "Wrong range! Wrong start parameter!"){
             tests::errorInformation.addError("test 2, split method, Wrong Start parameter for Source List -> negative");   // test 1
        }
    }

    // test 2 checking greater argument than size for start
    try{
        Split(*seq1, 550, *seq2, 2, *seq3, 2);
    }catch(exception &e){
        if((string)e.what() != "Wrong range! Wrong start parameter!"){
             tests::errorInformation.addError("test 3, split method, Wrong Start parameter for Source List ->greater than size");   // test 3
        }
    }

    // test 3 checking negative argument for step1
    try{
        Split(*seq1, 2, *seq2, -4, *seq3, 2);
    }catch(exception &e){
        if((string)e.what() != "Negative argument for step1!"){
             tests::errorInformation.addError("test 3, split method, Negative Step1 argument!");   // test 3
        }
    }


    // test 4 checking negative argument for step2
    try{
        Split(*seq1, 2, *seq2, 2, *seq3, -222);
    }catch(exception &e){
        if((string)e.what() != "Negative argument for step2!"){
             tests::errorInformation.addError("test 4, split method, Negative Step2 argument!");   // test 1
        }
    }

    int numArguments = Split(*seq1, 2, *seq2, 2, *seq3, 2);

    if(numArguments != 7){
       tests::errorInformation.addError("test 5, split method, Wrong number of elements which were used to split");   // test 5
    }



}
