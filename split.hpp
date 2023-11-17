#include "sequence.hpp"

using namespace std;

template <typename Key, typename Info>
void split_pos(Sequence<Key, Info> &seq, int start_pos, int len1, int len2, int count, Sequence<Key, Info> &seq1, Sequence<Key, Info> &seq2)
{
    for (int i = 0; i < count; i++)
    {
        if (seq.extractSubsequence(seq1, start_pos, len1) == 0)
            return;

        if (seq.extractSubsequence(seq2, start_pos, len2) == 0)
            return;
        // seq1.print(); cout<<endl; seq2.print(); cout<<endl; //-----------
    }
};

template <typename Key, typename Info>
void split_key(Sequence<Key, Info> &seq, const Key &start_key, int start_occ, int len1, int len2, int count, Sequence<Key, Info> &seq1, Sequence<Key, Info> &seq2)
{
    for (int i = 0; i < count; i++)
    {
        if (seq.extractSubsequence(seq1, start_key, start_occ, len1) == 0)
            return;

        if (seq.extractSubsequence(seq2, start_key, start_occ, len2) == 0)
            return;
    }
};

template <typename Key, typename Info>
Sequence<Key, Info> merge(Sequence<Key, Info> &seq1, Sequence<Key, Info> &seq2) // taking the first element of the 2nd sequence, putting in the midlle of the first and returning as a new sequence
{
    Sequence<Key, Info> newSeq;

    int seq1Size = seq1.getSize();

    for (int i = 0; i < seq1Size / 2; i++)
    {
        Key key = seq1.getKeyByPos(i);
        Info info = seq1.getInfoByPos(i);
        newSeq.pushBack(key, info);
    }

    Key key;
    Info info;
    seq2.getFront(info, key);
    newSeq.pushBack(key, info);

    for (int i = seq1Size / 2; i < seq1Size; i++)
    {
        Key key = seq1.getKeyByPos(i);
        Info info = seq1.getInfoByPos(i);
        newSeq.pushBack(key, info);
    }

    return newSeq;
};

// template <typename Key, typename Info>
// Sequence<Key, Info> merge(Sequence<Key, Info> &seq1, Sequence<Key, Info> &seq2)
// {
//     Sequence<Key, Info> newSeq;

//     // Copy elements from seq1 to newSeq
//     for (int i = 0; i < seq1.getSize(); i++)
//     {
//         Key key = seq1.getKeyByPos(i);
//         Info info = seq1.getInfoByPos(i);
//         newSeq.pushBack(key, info);
//     }

//     // Insert the first element of seq2 into the middle of newSeq
//     Key key;
//     Info info;
//     seq2.getFront(info, key);
//     int middle = newSeq.getSize() / 2 + 1;
//     newSeq.insertAfter(key, info, newSeq.getKeyByPos(middle), middle);

//     return newSeq;
// }