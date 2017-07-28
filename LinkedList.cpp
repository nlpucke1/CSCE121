#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr)
{
    // Implement this function
}

LinkedList::~LinkedList()
{
    this->clear();
}

LinkedList::LinkedList(const LinkedList& source) //Don't know what to do here -N
{
    // Implement this function
   
}

//Copied this from previous assignment, definitely check to see if it looks right. -N
LinkedList& LinkedList::operator=(const LinkedList& source)
{
    Node* head;
    Node* tail;
    if(this != &source)
    {
        this->clear();
        if(source.getHead() == nullptr && source.getTail() == nullptr)
        {
            return *this;
        }
        
        if(source.getTail() == source.getHead())
        {
            head = new Node(source.getHead()->value);
            tail = head;
            return *this;
        }
        Node* curr_rhs = source.getHead();
        head  = new Node(curr_rhs->value);
        curr_rhs = curr_rhs->next;
        Node* curr_lhs = head;
        while(curr_rhs != nullptr)
        {
            curr_lhs->next = new Node(curr_rhs->value);
            tail = curr_lhs->next;
            curr_rhs = curr_rhs->next;
            curr_lhs = curr_lhs->next;
        }
    }
    return *this;
}

Node* LinkedList::getHead() const
{
    return head;
}

Node* LinkedList::getTail() const
{
    return tail;
}

void LinkedList::insert(string location, int year, int month, double temperature)
{
    //Need to figure this out. -N
}

void LinkedList::clear()
{
    Node* current = head;
    while (current != nullptr) {
        Node* deleteNode = current;
        current = current->next;
        delete deleteNode;
    }
    head = nullptr;
    tail = nullptr;
}

void LinkedList::print() const
{
    /* Do not modify this function */
    print(cout);
}

void LinkedList::print(ostream& os) const
{
    /* Do not modify this function */
    os << *this;
}

ostream& operator<<(ostream& os, const LinkedList& ll)
{
    //We'll probably figure this out towards the end. 
    return os;
}
