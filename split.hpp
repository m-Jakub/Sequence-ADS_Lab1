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

    Key key;
    Info info;
    int i = 1;

    for (; i <= seq1.getSize() / 2; i++)
    {
        key = newSeq.getKeyByPos(i);
        info = newSeq.getInfoByPos(i);
        newSeq.pushBack(key, info);
    }

    seq2.getFront(info, key);

    newSeq.pushBack(key, info);

    for (; i <= seq1.getSize(); i++)
    {
        key = newSeq.getKeyByPos(i);
        info = newSeq.getInfoByPos(i);
        newSeq.pushBack(key, info);
    }

    return newSeq;
};