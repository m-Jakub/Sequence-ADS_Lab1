

using namespace std;

template <typename Key, typename Info>
class Sequence
{
    // implemented as singly linked list

public:
    Sequence();
    ~Sequence();
    Sequence(const Sequence &src)
    {
        // initialize properly data members
        // probably as in default constructor
        *this = src;
    }
    Sequence &operator=(const Sequence &src);
    bool insertAfter(const Key &kWhat, const Info iWhat, const Key &where, int which = 1)
    void pushFront(const Key &key, const Info &info); // keys are not unique!
    void pushBack(const Key &key, const Info &info);
    bool popFront();
    bool popBack();
    bool 
    unsigned int size() const;

    // and the rest of the interface
private:
};


//added locallyyyyyyyyyyyyyyy