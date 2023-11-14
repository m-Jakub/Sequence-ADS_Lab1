

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
    bool remove(const Key &keyToRemove, int which = 1);
    friend ostream &operator<<(ostream &, const Sequence < Key, Info);
    void swap(Sequence<Key, Info> &);
    Sequence<Key, Info> subsequence(const Key &startK, int startCh, const Key &endK, int endCh); // returns a Sequence extracted from the original sequence starting from "startCh-th" element of the "startK" Key and ending on "endCh-th" element of the "endK" Key
    void print();

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
