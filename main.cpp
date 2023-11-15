#include <iostream>
#include <string.h>
#include "sequence.hpp"
#include "split.hpp"
#include <assert.h>

using namespace std;

int main()
{
    Sequence<int, string> test;
    Sequence<int, string> testNull;
    cout << "--pushing--" << endl;
    test.pushFront(1, "John");
    test.pushBack(2, "Anna");
    test.pushBack(2, "Angela");
    test.pushFront(3, "Kyle");
    test.pushBack(4, "Carol");
    test.print();
    cout << "size: " << test.getSize() << endl;
    cout << "searching result: " << test.search(2) << endl;
    string info;
    if (test.getInfo(2, info, 1) == 1)
    {
        cout << "Info: " << info << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    assert(test.getInfo(99, info, 1) == 0);
    assert(test.getInfo(2, info, 99) == 0);
    cout << "--Copy constructor--" << endl;
    Sequence<int, string> *test2 = new Sequence<int, string>(test);
    test2->print();
    cout << "--popping--" << endl;
    assert(test2->popFront());
    assert(test2->popBack());
    assert(testNull.popFront() == 0);
    assert(testNull.popBack() == 0);
    test2->print();
    cout << "--assignment--" << endl;
    *test2 = test;
    cout << *test2;
    cout << "--removing--" << endl;
    test2->print();
    assert(test2->remove(2, 2));
    assert(test2->remove(2, -2) == 0);
    assert(test2->remove(3, 1));
    assert(test2->remove(4, 1));
    assert(test2->remove(99, 1) == 0);
    assert(test2->remove(2, 8) == 0);
    test2->pushBack(5, "Bob");
    cout << *test2;
    cout << "--inserting after--" << endl;
    assert(test2->insertAfter(6, "Garry", 1, 1));
    assert(test2->insertAfter(6, "Geralt", 6, 1));
    assert(test2->insertAfter(6, "Gabriel", 6, 2));
    assert(test2->insertAfter(7, "Monica", 5, 1));
    assert(test2->insertAfter(1, "", 1, 1));
    assert(test2->insertAfter(2, "", 6, 1));
    assert(test2->insertAfter(3, "", 6, 2));
    assert(test2->insertAfter(4, "", 5, 1));
    assert(test2->insertAfter(7, "Lorem", 99, 1) == 0);
    assert(test2->insertAfter(7, "Lorem", 1, 99) == 0);
    cout << *test2;
    cout << "--splitting--" << endl;
    Sequence<int, string> seq1;
    Sequence<int, string> seq2;
    split_pos(*test2, 2, 2, 3, 2, seq1, seq2);
    cout << "*All tests passed*" << endl;
}