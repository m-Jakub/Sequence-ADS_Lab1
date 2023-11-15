#include <iostream>
#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

using namespace std;

template <typename Key, typename Info>
class Sequence
{

public:
    Sequence() : head(nullptr), tail(nullptr) { size = 0; }
    ~Sequence()
    {
        clear();
    }
    Sequence(const Sequence<Key, Info> &src) : head(nullptr), tail(nullptr)
    {
        size = 0;
        Node *nodePtr = src.head;
        while (nodePtr != nullptr)
        {
            pushBack(nodePtr->key, nodePtr->info);
            nodePtr = nodePtr->next;
        }
    }
    Sequence<Key, Info> &operator=(const Sequence<Key, Info> &src)
    {
        if (this == &src)
            return *this;

        clear();
        Node *nodePtr = src.head;
        while (nodePtr != nullptr)
        {
            pushBack(nodePtr->key, nodePtr->info);
            nodePtr = nodePtr->next;
        }

        return *this;
    }
    unsigned int getSize() const
    {
        return size;
    }
    bool insertAfter(const Key &kWhat, const Info iWhat, const Key &where, int which = 1) // inserting element after "which-th" element of the given "where" Key
    {
        if (which < 1)
            return 0;
        Node *ptrFound = FindByKey(where, which);
        if (ptrFound == nullptr)
            return 0;

        Node *newNode = new Node(kWhat, iWhat);
        newNode->next = ptrFound->next;
        ptrFound->next = newNode;
        size++;
        return 1;
    }
    void pushFront(const Key &key, const Info &info)
    {
        Node *newNode = new Node(key, info);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void pushBack(const Key &key, const Info &info)
    {
        Node *newNode = new Node(key, info);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    bool popFront()
    {
        if (isEmpty())
            return 0;
        if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return 1;
        }

        Node *nodePtr = head;
        head = head->next;
        delete nodePtr;
        size--;
        return 1;
    }
    bool popBack()
    {
        if (isEmpty())
            return 0;
        if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return 1;
        }

        Node *nodePtr = head;
        while (nodePtr->next != tail)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = nullptr;
        delete tail;
        tail = nodePtr;
        size--;
        return 1;
    }
    bool getFront(Info &info, Key &key) // returning front element's Info and Key by reference
    {
        if (isEmpty())
            return 0;
        info = head->info;
        key = head->key;
    }
    bool getBack(Info &info, Key &key)
    {
        if (isEmpty())
            return 0;
        info = tail->info;
        key = tail->key;
    }
    bool getInfo(const Key &key, Info &info, int n = 1) // returning the Info of the n-th element of the given Key by reference
    {
        if (n < 1)
            return 0;
        Node *nodePtr = FindByKey(key, n);
        if (nodePtr == nullptr)
            return 0;
        else
        {
            info = nodePtr->info;
            return 1;
        }
    }
    bool isEmpty()
    {
        if (size == 0)
            return 1;
        if (size > 0)
            return 0;
        else
            return 0;
    }
    void clear()
    {
        while (!isEmpty())
        {
            popBack();
        }
    }
    bool search(const Key &key, int n) // checks if an element of the given key can be found at least n times
    {
        if (n < 1)
            return 1;

        Node *nodePtr = FindByKey(key, n);
        if (nodePtr == nullptr)
            return 0;
        else
            return 1;
    }
    int search(const Key &key) // returns the number of elements with such Key
    {
        Node *nodePtr = head;
        int key_count = 0;

        while (nodePtr != nullptr)
        {
            if (nodePtr->key == key)
                key_count++;
            nodePtr = nodePtr->next;
        }
        return key_count;
    }
    bool remove(const Key &keyRemove, int which = 1)
    {
        if (which < 1)
            return 0;

        if (isEmpty())
            return 0;

        Node *nodePtrPrevious = head;
        int key_count = 0;

        if (head->key == keyRemove)
        {
            if (which == 1)
                return popFront();
            key_count++;
        }

        while (nodePtrPrevious->next != nullptr)
        {
            if (nodePtrPrevious->next->key == keyRemove)
                key_count++;
            if (key_count == which)
            {
                if (nodePtrPrevious->next->next == nullptr)
                {
                    popBack();
                    return 1;
                }
                else
                {
                    Node *toBeRemoved = nodePtrPrevious->next;
                    nodePtrPrevious->next = toBeRemoved->next;
                    delete toBeRemoved;
                    size--;
                    return 1;
                }
            }
            nodePtrPrevious = nodePtrPrevious->next;
        }
        return 0;
    }
    friend ostream &operator<<(ostream &os, const Sequence<Key, Info> &sequence)
    {
        Node *nodePtr = sequence.head;
        while (nodePtr != nullptr)
        {
            os << nodePtr->key << "\t" << nodePtr->info << endl;
            nodePtr = nodePtr->next;
        }
        return os;
    }
    bool extractSubsequence(Sequence<Key, Info> &subsequence, const Key &startK, int startNr, int len) // returns a Sequence extracted from the original sequence starting from "startNr-th" element of the "startK" Key and ending on "endNr-th" element of the "endK" Key (removes the extracted part from the original sequence)
    {
        if ((startNr < 0) || (len < 0))
            return 0;
        Node *nodePtr = FindByKey(startK, 1);
        for (int i = 0; i < startNr; i++)
        {
            if (nodePtr == nullptr)
                return 0;
            nodePtr = nodePtr->next;
        }
        Node *toBeRemoved;

        for (int i = 0; i < len; i++)
        {
            if (nodePtr == nullptr)
                return 0;
            subsequence.pushBack(nodePtr->key, nodePtr->info);
            toBeRemoved = nodePtr;
            nodePtr = nodePtr->next;
            remove(toBeRemoved->key);
        }
        return 1;
    }
    bool extractSubsequence(Sequence<Key, Info> &subsequence, int startNr, int len) // returns a Sequence extracted from the original sequence starting from "startNr-th" element of the "startK" Key and ending on "endNr-th" element of the "endK" Key (removes the extracted part from the original sequence)
    {
        if ((startNr < 0) || (len < 0))
            return 0;

        Node *nodePtr = head;
        for (int i = 0; i < startNr; i++)
        {
            if (nodePtr == nullptr)
                return 0;
            nodePtr = nodePtr->next;
        }
        
        Node *toBeRemoved;
        for (int i = 0; i < len; i++)
        {
            if (nodePtr == nullptr)
                return 0;
            subsequence.pushBack(nodePtr->key, nodePtr->info);
            toBeRemoved = nodePtr;
            nodePtr = nodePtr->next;
            remove(toBeRemoved->key);
        }
        return 1;
    }
    void print()
    {
        Node *nodePtr = head;
        while (nodePtr != nullptr)
        {
            cout << nodePtr->key << "\t" << nodePtr->info << endl;
            nodePtr = nodePtr->next;
        }
    }

private:
    struct Node
    {
        Key key;
        Info info;
        Node *next;

        Node(const Key &k, const Info &i) : key(k), info(i), next(nullptr) {}
    };

    Node *FindByKey(const Key &key, unsigned int which) // helping function for finding "which-th" element of a given Key
    {
        if (which < 1)
            return nullptr;

        Node *nodePtr = head;
        int key_count = 0;

        while (nodePtr != nullptr)
        {
            if (nodePtr->key == key)
                key_count++;
            if (key_count == which)
                return nodePtr;
            nodePtr = nodePtr->next;
        }
        return nullptr;
    }

    Node *head;
    Node *tail;
    unsigned int size;
};

#endif // SEQUENCE_HPP