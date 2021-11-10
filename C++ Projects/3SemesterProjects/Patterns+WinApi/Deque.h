#pragma once

#include <initializer_list>
#include <ostream>

class Deque;

class Visitor {
public:
     virtual void visitDeque(Deque&) = 0;
};

class Element {
    virtual void accept(Visitor&) = 0;
    
};

class DequeVisitor : public Visitor {
private:
    double average_;
public:
    void visitDeque(Deque&) override;
    double getAverage() { return average_;}
};

class Deque: public Element {
private:
    int* data_;
    int size_ = 1;
    int amountOfElements_ = 0;
    int firstElementIndex_ = 0;
    int lastElementIndex_ = 0;
public:
    class Iterator;
    Deque();
    Deque(int);
    Deque(Deque&&);
    Deque(const Deque&);
    Deque(const std::initializer_list<int>);
    ~Deque();

    bool isEmpty();
    int size();
    void clear();
    int front();
    int back();
    void pushFront(int);
    void pushBack(int);
    void popFront();
    void popBack();
    void swap(Deque&);
    void setNewSize(int);
    Deque& operator=(Deque&);
    Deque& operator=(Deque&&);
    friend bool operator == (const Deque&, const Deque&);
    friend bool operator != (const Deque&, const Deque&);
    friend Deque& operator += (Deque&, const Deque&);
    friend Deque operator + (const Deque&, const Deque&);
    friend std::ostream& operator<<(std::ostream&, const Deque&);
    friend std::istream& operator>>(std::istream&, Deque&);

    void accept(Visitor&) override;

    Iterator* createIterator() const { return new Iterator(this); }

    class Iterator {
        const Deque* deque;
        int position;
        bool isOver;
    public:
        Iterator(const Deque* deque1) {
            deque = deque1;
            position = deque->firstElementIndex_;
            isOver = false;
        }
        void next() { 
            if (position == deque->lastElementIndex_)
                isOver = true;
            else
                isOver = false;
            position = (position + 1) % deque->size_; 
        }
        void previous() { 
            if (position == deque->firstElementIndex_)
                isOver = true;
            else
                isOver = false;
            position = position == 0 ? deque->size_ - 1 : position - 1; 
        }
        int element() { return deque->data_[position]; }
        void first() { 
            isOver = false;
            position = deque->firstElementIndex_; }
        void last() { position = deque->lastElementIndex_; }
        bool isDone() { return isOver; }
    };
};