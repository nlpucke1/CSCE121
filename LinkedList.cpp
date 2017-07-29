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
    Node* currNode = source.getHead();
    LinkedList ll = LinkedList();
    while(currNode != nullptr)
    {
        this->insert(/*std::to_string*/(currNode->value), currNode->year, currNode->month, currNode->temperature);
        currNode = currNode->next;
    }
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
    Node* new_node = new Node(/*std::stoi*/location,year,month,temperature);
    Node* currNode = this->head;
    /*Verify correct location, year, month*/
    if(year < 1800 || year > 2017)
    {
        throw runtime_error("Error: invalid year.");
    }
    
    if(month < 1 || month > 12)
    {
        throw runtime_error("Error: invalid month.");
    }
    
    if(temperature < -50.0)
    {
        
    }
    
    if(this->head == nullptr)
    {
        this->head = new_node;
    }
    
    else if (new_node < (this->head))
    {
        new_node->next = this->head;
        this->head = new_node;
    }
    
    else
    {
        while(currNode != nullptr)
        {
            if(currNode->next == nullptr)
            {
                currNode->next = new_node;
                new_node->next = nullptr;
            }
            else if(new_node < (currNode->next))
            {
                new_node->next = currNode->next;
                currNode->next = new_node;
            }
            else
            {
                currNode = currNode->next;
            }
        }
    
    }
}

void LinkedList::clear()
{
    Node* current = head;
    while (current != nullptr)
    {
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
    Node* curr = ll.getHead();
    while(curr != nullptr)
    {
        os << curr->value << " " << curr->year << " " << curr->month << " " << curr -> temperature << endl;
        curr = curr->next;
    }
    return os;
}

