

using namespace std;

template <typename Key, typename Info>
class Sequence
{

public:
    Sequence() : head(nullptr), tail(nullptr) {}
    ~Sequence()
    {
        clear();
    }
    Sequence(const Sequence<Key, Info> &src) : head(nullptr), tail(nullptr), size(0)
    {
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
    unsigned int size() const
    {
        return size;
    }
    bool insertAfter(const Key &kWhat, const Info iWhat, const Key &where, int which = 1) // inserting element after "which-th" element of the given "where" Key
    {
        Node *ptrFound = FindByKey(kWhat, which);
        if (ptrFound == nullptr)
            return 0;
        Node *newNode = new Node(kWhat, iWhat);
        newNode->next = ptrFound->next;
        ptrFound->next = newNode;
    }
    void pushFront(const Key &key, const Info &info)
    {
        Node *newNode = new Node(kWhat, iWhat);
        newNode->next = head;
    }
    void pushBack(const Key &key, const Info &info)
    {
        Node *newNode = new Node(kWhat, iWhat);
        tail->next = newNode;
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
            return 1;
        }

        Node *nodePtr = head;
        head = head->next;
        delete nodePtr;
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
        return 1;
    }
    bool getFront(Info &info, Key &key) // returning front element's Info and Key by reference
    {
        if (isEmpty())
            return 0;
        info = head->info;
        key = head->key;
    }
    bool getBack(Info &, Key &)
    {
        if (isEmpty())
            return 0;
        info = tail->info;
        key = tail->key;
    }
    bool getInfo(Info &info, const Key &key, int n = 1) // returning the Info of the n-th element of the given Key by reference
    {
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
    }
    void clear()
    {
        while (!isEmpty())
        {
            popBack();
        }
    }
    bool search(const Key &key, unsigned int n) // checks if an element of the given key can be found at least n times
    {
        if (n == 0)
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
    bool remove(const Key &keyRemove, unsigned int which = 1)
    {
        if (which == 0)
            return 0;

        if (isEmpty())
            return 0;

        Node *nodePtrPrevious = head;
        int key_count = 0;

        if (head->key == keyRemove)
        {
            if (which = 1)
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
                    popBack();
                else
                {
                    Node *toBeRemoved = nodePtrPrevious->next;
                    nodePtrPrevious->next = toBeRemoved->next;
                    delete toBeRemoved;
                    return 1;
                }
            }
            nodePtr = nodePtr->next;
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
    bool extractSubsequence(Sequence<Key, Info> &subsequence, const Key &startK, int startNr, const Key &endK, int endNr) // returns a Sequence extracted from the original sequence starting from "startNr-th" element of the "startK" Key and ending on "endNr-th" element of the "endK" Key
    {
        Node *start = FindByKey(startK, startNr);
        if (start == nullptr)
            return 0;

        Node *end = FindByKey(endK, endNr);
        if (end == nullptr)
            return 0;

        Node *nodePtr = start;
        while (nodePtr != end)
        {
            subsequence.pushBack(nodePtr->key, nodePtr->info);
            nodePtr = nodePtr->next;
        }
        subsequence.pushBack(end->key, end->info);
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
        if (which == 0)
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
