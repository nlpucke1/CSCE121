#include <string>
#include "Node.hpp"

using namespace std;

// Default constructor
Node::Node(): value(0), year(0), month(0), temperature(0), next(nullptr)
{
    
} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string value, int year, int month, double temperature): value(value), year(year), month(month), temperature(temperature), next(nullptr)
{
    
}

Node::Node(string value) : value(value), year(0), month(0), temperature(0), next(nullptr)
{
    
}
// remember to initialize next to nullptr

bool Node::operator<(const Node& b)
{
    if(this->value > b.value)
    {
        return false;
    }
    if(this->year > b.year)
    {
        return false;
    }
    if(this->month > b.month)
    {
        return false;
    }
    if(this->temperature > b.temperature)
    {
        return false;
    }
    else
    {
        return true;
    }
}
