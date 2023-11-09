

using namespace std;

template <typename Key, typename Info>
class Sequence
{
    // implemented as singly linked list

public:
    Sequence();
    ~Sequence();
    Sequence(const Sequence<Key, Info> &src)
    {
        // initialize properly data members
        // probably as in default constructor
        *this = src;
    }
    Sequence<Key, Info> &operator=(const Sequence<Key, Info> &src);
    unsigned int size() const;
    bool insertAfter(const Key &kWhat, const Info iWhat, const Key &where, int which = 1)
    void pushFront(const Key &key, const Info &info); // keys are not unique!
    void pushBack(const Key &key, const Info &info);
    bool popFront();
    bool popBack();
    bool getFront(Info &, Key &); // returning front element's Info and Key by reference
    bool getBack(Info &, Key &);
    bool getInfo(Info &, const Key &, int n = 1); // returning the Info of the n-th element of the given Key by reference
    bool isEmpty();
    void clear();
    bool search(const Key &, int n); // checks if an element of the given key can be found at least n times
    int search(const Key &); // returns the number of elements with such Key
    friend ostream &operator<<(ostream &, const Sequence<Key, Info);


    // and the rest of the interface
private:
};


//added locallyyyyyyyyyyyyyyy