#include "Deque.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

//
// Created by a3057 on 9/1/2021.

Deque::Deque() {
    data_ = new int[size_];
}

Deque::Deque(int number) {
    data_ = new int[size_];
    pushBack(number);
}

Deque::Deque(const Deque& deque) {
    data_ = new int[deque.size_];
    auto it = deque.createIterator();
    if (deque.amountOfElements_ > 0) {
        for (it->first(); !it->isDone(); it->next()) {
            pushBack(it->element());
        }
    }
    
}

Deque::Deque(const std::initializer_list<int> list) {
    data_ = new int[size_];
    for (auto element : list)
        pushBack(element);
}

Deque::~Deque() {
    delete[] data_;
}

Deque::Deque(Deque&& deque) {
    data_ = deque.data_;
    size_ = deque.size_;
    amountOfElements_ = deque.amountOfElements_;
    firstElementIndex_ = deque.firstElementIndex_;
    lastElementIndex_ = deque.lastElementIndex_;
    deque.data_ = nullptr;
}


void Deque::pushBack(int number) {
    if (amountOfElements_ == size_) { setNewSize(size_ * 2); }
    lastElementIndex_ = (lastElementIndex_ + 1) % size_;
    data_[lastElementIndex_] = number;
    amountOfElements_++;
}

void Deque::pushFront(int number) {
    if (amountOfElements_ == size_) { setNewSize(size_ * 2); }
    firstElementIndex_ = firstElementIndex_ == 0 ? size_ - 1 : firstElementIndex_ - 1;
    data_[firstElementIndex_] = number;
    amountOfElements_++;
}

void Deque::popBack() {
    if (!isEmpty()) {
        if (amountOfElements_ == size_ / 4) {
            setNewSize(size_ / 2);
        }
        lastElementIndex_ = lastElementIndex_ == 0 ? size_ - 1 : lastElementIndex_ - 1;
        amountOfElements_--;
    }
    else
        std::cout << "The deque is empty!" << std::endl;
}

void Deque::popFront() {
    if (!isEmpty()) {
        if (amountOfElements_ == size_ / 4) {
            setNewSize(size_ / 2);
        }       
        firstElementIndex_ = (firstElementIndex_ + 1) % size_;
        amountOfElements_--;
    }
    else
        std::cout << "The deque is empty!" << std::endl;

}


void Deque::setNewSize(int newSize) {
    int* tempData = new int[newSize];
    for (int i = 0; i < amountOfElements_; i++) {
        tempData[i] = data_[(firstElementIndex_ + i) % size_];
    }
    size_ = newSize;
    firstElementIndex_ = 0;
    lastElementIndex_ = firstElementIndex_ + amountOfElements_ - 1;
    delete[] data_;
    data_ = tempData;
}

bool Deque::isEmpty() {
    return amountOfElements_ == 0;
}

int Deque::back() {
    return data_[lastElementIndex_];
}

int Deque::front() {
    return data_[firstElementIndex_];
}

void Deque::swap(Deque& deque) {
    Deque tempDeque = deque;
    deque = *this;
    *this = tempDeque;
    //size_ = tempDeque.size_;
    //delete[] data_;
    //data_ = new int[size_];
    //for (int i = 0; i < size_; i++) {
    //    data_[i] = tempDeque.data_[i];
    //}
    //amountOfElements_ = tempDeque.amountOfElements_;
    //firstElementIndex_ = tempDeque.firstElementIndex_;
    //lastElementIndex_ = tempDeque.lastElementIndex_;

}

int Deque::size() {
    return amountOfElements_;
}

void Deque::clear() {
    delete[] data_;
    data_ = new int[1];
    lastElementIndex_ = 0;
    firstElementIndex_ = 0;
    size_ = 1;
    amountOfElements_ = 0;
}

Deque& Deque::operator=(Deque& deque) {
    if (this == &deque)
        return *this;
    size_ = deque.size_;
    delete[] data_;
    data_ = new int[size_];
    for (int i = 0; i < deque.size_; i++) {
        data_[i] = deque.data_[i];
    }
    amountOfElements_ = deque.amountOfElements_;
    firstElementIndex_ = deque.firstElementIndex_;
    lastElementIndex_ = deque.lastElementIndex_;
    return *this;
}

Deque& Deque::operator=(Deque&& deque) {
    if (this == &deque)
        return *this;
    data_ = deque.data_;
    deque.data_ = nullptr;
    size_ = deque.size_;
    amountOfElements_ = deque.amountOfElements_;
    firstElementIndex_ = deque.firstElementIndex_;
    lastElementIndex_ = deque.lastElementIndex_;
    return *this;
}

bool operator == (const Deque& deque1, const Deque& deque2) {

    if (deque1.amountOfElements_ != deque2.amountOfElements_) { return false; }
    auto it1 = deque1.createIterator();
    auto it2 = deque2.createIterator();
    while (!it1->isDone()) {
        if (it1->element() != it2->element())
            return false;
        it1->next();
        it2->next();
    }
    return true;
}

bool operator != (const Deque& deque1, const Deque& deque2) {
    return !(deque1 == deque2);
}

Deque& operator += (Deque& deque1, const Deque& deque2) {
    for (auto it = deque2.createIterator(); !it->isDone(); it->next()) {
        deque1.pushBack(it->element());
    }
    return deque1;
}

Deque operator + (const Deque& deque1, const Deque& deque2) {
    Deque result = deque1;
    result += deque2;
    return result;
}

std::ostream& operator<<(std::ostream& stream, const Deque& deque) {
    for (int i = deque.firstElementIndex_; i != deque.lastElementIndex_; i = (i + 1) % deque.size_) {
        stream << deque.data_[i] << " ";
    }
    stream << deque.data_[deque.lastElementIndex_] << std::endl;
    return stream;
}

std::istream& operator>>(std::istream& stream, Deque& deque) {
    int amount = 0;
    stream >> amount;
    for (int i = 0; i < amount; i++) {
        int element;
        stream >> element;
        deque.pushBack(element);
    }
    return stream;
}

void Deque::accept(Visitor& visitor){
    visitor.visitDeque(*this);
}

void DequeVisitor::visitDeque(Deque& deque) {
    double summ = 0;
    for (auto it = deque.createIterator(); !it->isDone(); it->next()) {
        summ += it->element();
    }
    average_ = summ / deque.size();
}