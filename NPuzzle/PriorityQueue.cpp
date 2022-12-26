//
//  PriorityQueue.cpp
//  Project
//
//  Created by Mohamed Salah on 29/11/2022.
//

#include "PriorityQueue.hpp"
#include "PuzzleState.hpp"

//--- Definition of PriorityQueue constructor

template <typename ElementType>
PriorityQueue<ElementType>:: PriorityQueue(): myFront(0), myBack(0) { }

//--- Definition of PriorityQueue copy constructor
template <typename ElementType>
PriorityQueue<ElementType>:: PriorityQueue(const PriorityQueue<ElementType> & original) {
    myFront = myBack = 0;
    if (original.empty()) {
        return;
    }
    
    // Copy first node
    myBack = myFront = new QueueNode<ElementType>(*original.myFront);
    
    // Set pointer to run through original's linked list
    QueueNodePointer origPtr = original.myFront->next;
    while (origPtr != 0) {
        myBack->next = new QueueNode<ElementType>(*origPtr);
        myBack = myBack->next;
        origPtr = origPtr->next;
    }
}

//--- Definition of PriorityQueue destructor
template <typename ElementType>
PriorityQueue<ElementType>::~PriorityQueue() {
    // Set pointer to run through the queue
    QueueNodePointer prev = myFront, ptr;
    while (prev != 0) {
        ptr = prev->next;
        (prev->data).~ElementType();
        delete prev;
        prev = ptr;
    }
}

//--- Definition of assignment operator
template <typename ElementType>
const PriorityQueue<ElementType> & PriorityQueue<ElementType>::operator=(const PriorityQueue<ElementType> & rightHandSide) {
    if (this == &rightHandSide) {
        return *this;
    }
    
    this->~PriorityQueue(); // destroy current linked list
    if (rightHandSide.empty()) { // empty queue
        myFront = myBack = 0;
        return *this;
    }
    
    // Copy first node
    myFront = myBack = new QueueNode<ElementType>(*rightHandSide.myFront);
    
    // Set pointer to run through rightHandSide's linked list
    QueueNodePointer rhsPtr = rightHandSide.myFront->next;
    while (rhsPtr != 0) {
        myBack->next = new QueueNode<ElementType>(*rhsPtr);
        myBack = myBack->next;
        rhsPtr = rhsPtr->next;
    }
    
    return *this;
}

//--- Definition of empty()
template <typename ElementType>
bool PriorityQueue<ElementType>::empty() const {
    return (myFront == 0);
}

//--- Definition of enqueue()
template <typename ElementType>
void PriorityQueue<ElementType>::enqueue(ElementType & value, int key) {
    QueueNodePointer newptr = new QueueNode<ElementType>(value, key);
    if (empty()) {
        myFront = myBack = newptr;
        return;
    }
    
    QueueNodePointer start = myFront;
    if (myFront->key >= key) {
        newptr->next = myFront;
        myFront = newptr;
    } else {
        while (start->next != NULL &&
               start->next->key <= key) {
            start = start->next;
        }
        
        newptr->next = start->next;
        start->next = newptr;
    }
}

//--- Definition of display()
template <typename ElementType>
void PriorityQueue<ElementType>::display(ostream & out) const {
    QueueNodePointer ptr;
    out << "start" << endl;
    for (ptr = myFront; ptr != 0; ptr = ptr->next)
        out << ptr->data << endl;
    
    out << "end" << endl;
    
}

//--- Definition of output operator
template <typename ElementType>
ostream & operator<< (ostream & out, const PriorityQueue<ElementType> & aQueue) {
    aQueue.display(out);
    return out;
}

//--- Definition of front()
template <typename ElementType>
ElementType* PriorityQueue<ElementType>::front() const {
    if (!empty()) {
        return &(myFront->data);
    }
    
    cerr << "*** PriorityQueue is empty "
    " -- returning garbage ***\n";
    ElementType * temp = new(ElementType);
    ElementType garbage = *temp;     // "Garbage" value
    delete temp;
    return temp;
}

//--- Definition of dequeue()
template <typename ElementType>
void PriorityQueue<ElementType>::dequeue() {
    if (empty()) {
        cerr << "*** PriorityQueue is empty -- can't remove a value ***\n";
        return;
    }
    
    PriorityQueue<ElementType>::QueueNodePointer ptr = myFront;
    myFront = myFront->next;
    //delete ptr;
    if (myFront == 0)     // queue is now empty
        myBack = 0;
}


template class PriorityQueue<int>;
template class PriorityQueue<PuzzleState>;
