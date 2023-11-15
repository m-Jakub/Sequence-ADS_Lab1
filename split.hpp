#include "sequence.hpp"

using namespace std;

template <typename Key, typename Info>
void split_pos(const Sequence<Key, Info> &seq, int start_pos, int len1, int len2, int count, Sequence<Key, Info> &seq1, Sequence<Key, Info> &seq2)
{
    for (int i = 0; i < count; i++)
    {
        if (seq.extractSubsequence(seq1, start_pos, len1) == 0)
            return;

        if (seq.extractSubsequence(seq2, start_pos, len2) == 0)
            return;
    }
};

template <typename Key, typename Info>
void split_key(const Sequence<Key, Info> &seq, const Key &start_key, int start_occ, int len1, int len2, int count, Sequence<Key, Info> &seq1, Sequence<Key, Info> &seq2)
{
    for (int i = 0; i < count; i++)
    {
        if (seq.extractSubsequence(seq1, start_key, start_occ, len1) == 0)
            return;

        if (seq.extractSubsequence(seq2, start_key, start_occ, len2) == 0)
            return;
    }
};