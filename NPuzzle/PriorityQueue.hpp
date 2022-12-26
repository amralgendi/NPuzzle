//
//  PriorityQueue.hpp
//  Project
//
//  Created by Mohamed Salah on 29/11/2022.
//

#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

template <typename ElementType>
class QueueNode {
public:
    
    // MARK: - Data Members
    
    QueueNode<ElementType> * next;
    ElementType data;
    
    int key;
    
    // MARK: - Constructor
    
    QueueNode(ElementType & _data, int _key, QueueNode<ElementType> * _next = 0): data(_data), key(_key), next(_next) { }
    
    QueueNode() { }
    
    QueueNode(QueueNode<ElementType> & original) {
        next = original.next;
        data = *new ElementType(original.data);
        key = original.key;
    }
};

template <typename ElementType>
class PriorityQueue {
public:
    
    /***** Function Members *****/
    /***** Constructors *****/
    
    PriorityQueue();
    /*-----------------------------------------------------------------------
     Construct a PriorityQueue object.
     
     Precondition:  None.
     Postcondition: An empty PriorityQueue object has been constructed.
     (myFront and myBack are initialized to null pointers).
     -----------------------------------------------------------------------*/
    
    PriorityQueue(const PriorityQueue & original);
    /*-----------------------------------------------------------------------
     Copy Constructor
     
     Precondition:  original is the queue to be copied and is received
     as a const reference parameter.
     Postcondition: A copy of original has been constructed.
     -----------------------------------------------------------------------*/
    
    /***** Destructor *****/
    ~PriorityQueue();
    /*-----------------------------------------------------------------------
     Class destructor
     
     Precondition:  None.
     Postcondition: The linked list in the queue has been deallocated.
     -----------------------------------------------------------------------*/
    
    /***** Assignment *****/
    const PriorityQueue & operator= (const PriorityQueue & rightHandSide);
    /*-----------------------------------------------------------------------
     Assignment Operator
     
     Precondition:  rightHandSide is the queue to be assigned and is
     received as a const reference parameter.
     Postcondition: The current queue becomes a copy of rightHandSide
     and a reference to it is returned.
     -----------------------------------------------------------------------*/
    
    bool empty() const;
    /*-----------------------------------------------------------------------
     Check if queue is empty.
     
     Precondition:  None.
     Postcondition: Returns true if queue is empty and false otherwise.
     -----------------------------------------------------------------------*/
    
    void enqueue(ElementType & value, int key);
    /*-----------------------------------------------------------------------
     Add a value to the priority queue, values with higher key values are always added to the top.
     
     Precondition:  value is to be added to this queue.
     Postcondition: value is added at a place according to key where nodes with higher key values are always added to the top.
     -----------------------------------------------------------------------*/
    
    void display(ostream & out) const;
    /*-----------------------------------------------------------------------
     Display values stored in the queue.
     
     Precondition:  ostream out is open.
     Postcondition: Queue's contents, from front to back, have been
     output to out.
     -----------------------------------------------------------------------*/
    
    ElementType * front() const;
    /*-----------------------------------------------------------------------
     Retrieve value at front of queue (if any).
     
     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue is returned, unless the queue
     is empty; in that case, an error message is displayed and a
     "garbage value" is returned.
     -----------------------------------------------------------------------*/
    
    void dequeue();
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).
     
     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless
     queue is empty; in that case, an error message is displayed
     and execution allowed to proceed.
     -----------------------------------------------------------------------*/
    
private:
    typedef QueueNode<ElementType> * QueueNodePointer;
    
    // MARK: - Data Members
    
    QueueNodePointer myFront, myBack;
    
}; // end of class declaration

#endif /* PriorityQueue_hpp */
