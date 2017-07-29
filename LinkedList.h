#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include "Node.hpp"

class LinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    // Default constructor
    LinkedList();
    
    // Destructor
    ~LinkedList();
    
    // Copy constructor
    LinkedList(const LinkedList& other);
    
    // Assignment constructor
    LinkedList& operator=(const LinkedList& other);
    
    //I added these with permission of TA -N
    Node* getHead() const;
    Node* getTail() const;
    
    // Insert a record to the linked list
    //Need to figure this out. -N
    void insert(std::string location, int year, int month, double temperature);
    
    // Clear the content of this linked list
    //I just used this in the deconstructor
    void clear();
    
    friend std::ostream& operator<<(std::ostream&, const LinkedList&);
    
    // The functions below are written already. Do not modify them.
    void print() const;
    void print(std::ostream&) const;
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
#endif
