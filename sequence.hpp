

using namespace std;

template <typename Key, typename Info>
class Sequence
{
    // implemented as singly linked list

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
    bool getFront(Info &, Key &); // returning front element's Info and Key by reference
    bool getBack(Info &, Key &);
    bool getInfo(Info &, const Key &, int n = 1); // returning the Info of the n-th element of the given Key by reference
    bool isEmpty();
    void clear();
    bool search(const Key &, int n); // checks if an element of the given key can be found at least n times
    int search(const Key &);         // returns the number of elements with such Key
    friend ostream &operator<<(ostream &, const Sequence < Key, Info);
    void sort();
    void reverse();
    void swap(Sequence<Key, Info> &);
    Sequence<Key, Info> subsequence(const Key &startK, int startCh, const Key &endK, int endCh); // returns a Sequence extracted from the original sequence starting from "startCh-th" element of the "startK" Key and ending on "endCh-th" element of the "endK" Key

private:
    struct Node
    {
        Key key;
        Info info;
        Node *next;

        Node(const Key &k, const Info &i) : key(k), info(i), next(nullptr) {}
    };

    Node *FindByKey(const Key &key, int which) // helping function for finding "i-th" element of a given Key
    {
        Node *nodePtr = head;

        while (nodePtr->key != key)
        {
            if (nodePtr == nullptr)
                return nullptr;
            nodePtr = nodePtr->next;
        }

        while (i != which)
        {
            if (nodePtr == nullptr)
                return nullptr;
            nodePtr = nodePtr->next;
        }

        return nodePtr;
    }

    Node *head;
    Node *tail;
    unsigned int size;
};

// added locallyyyyyyyyyyyyyyy