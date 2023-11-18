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
     test.pushFront(1, "Jim");
     test.pushBack(2, "Jenny");
     test.pushBack(2, "Arthur");
     test.pushFront(3, "Rey");
     test.pushBack(4, "Ollie");
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
     cout << "--pop--" << endl;
     assert(test2->popFront());
     assert(test2->popBack());
     assert(testNull.popFront() == 0);
     assert(testNull.popBack() == 0);
     test2->print();
     cout << "--assignment operator--" << endl;
     *test2 = test;
     cout << *test2;
     cout << "--remove--" << endl;
     test2->print();
     assert(test2->remove(2, 2));
     assert(test2->remove(2, -2) == 0);
     assert(test2->remove(3, 1));
     assert(test2->remove(4, 1));
     assert(test2->remove(99, 1) == 0);
     assert(test2->remove(2, 8) == 0);
     test2->pushBack(5, "Bob");
     cout << *test2;
     cout << "--insertAfter--" << endl;
     assert(test2->insertAfter(6, "Jennifer", 1, 1));
     assert(test2->insertAfter(6, "Robert", 6, 1));
     assert(test2->insertAfter(6, "Tom", 6, 2));
     assert(test2->insertAfter(7, "Lessy", 5, 1));
     assert(test2->insertAfter(1, "Patric", 1, 1));
     assert(test2->insertAfter(2, "Clarence", 6, 1));
     assert(test2->insertAfter(3, "Nick", 6, 2));
     assert(test2->insertAfter(4, "Thomas", 5, 1));
     assert(test2->insertAfter(3, "Sam", 6, 2));
     assert(test2->insertAfter(4, "Kim", 5, 1));
     assert(test2->insertAfter(7, "John", 99, 1) == 0);
     assert(test2->insertAfter(7, "Sky", 1, 99) == 0);
     cout << *test2;
     Sequence<int, string> *test3 = new Sequence<int, string>(*test2);

     try
     {
          cout << "--split_pos--" << endl;
          Sequence<int, string> seq1;
          Sequence<int, string> seq2;
          split_pos(*test2, 2, 2, 2, 2, seq1, seq2);
          cout << "seq: " << endl;
          test2->print();
          cout << endl
               << "seq1: " << endl
               << seq1 << endl;
          cout << "seq2: " << endl
               << seq2 << endl;
     }
     catch (const invalid_argument &e)
     {
          cout << "Invalid argument: " << e.what() << endl << endl;
     }

     cout << "--invalid parameters for spilt_key--" << endl;
     try
     {
          Sequence<int, string> seq_1;
          Sequence<int, string> seq_2;
          split_key(*test3, 3, 0, 2, 2, 2, seq_1, seq_2);
          cout << "seq: " << endl;
          test3->print();
          cout << endl
               << "seq1: " << endl
               << seq_1 << endl;
          cout << "seq2: " << endl
               << seq_2 << endl;
     }
     catch (const invalid_argument &e)
     {
          cout << "Invalid argument: " << e.what() << endl << endl;
     }

     cout << "--split_key--" << endl;
     try
     {
          Sequence<int, string> seq_1;
          Sequence<int, string> seq_2;
          split_key(*test3, 3, 2, 2, 2, 2, seq_1, seq_2);
          cout << "seq: " << endl;
          test3->print();
          cout << endl
               << "seq1: " << endl
               << seq_1 << endl;
          cout << "seq2: " << endl
               << seq_2 << endl;

          cout << "--merge--" << endl;
          Sequence<int, string> merged = merge(seq_1, seq_2);
          merged.print();
     }
     catch (const invalid_argument &e)
     {
          cout << "Invalid argument: " << e.what() << endl << endl;
     }

     cout << "*All tests succesful*" << endl;
}