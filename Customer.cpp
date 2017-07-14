#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <sstream>
#include "Product.h"
#include "Customer.h"
using namespace std;

Customer::Customer(int id, std::string name, bool credit) :
id(id), name(name), credit(credit), balance(0.0)
{
    if (name.length()==0)
        throw runtime_error("Product name cannot be empty.");
}

int Customer::getID() const
{
    return id;
}

void Customer::setName(std::string name)
{
    this->name = name;
}

std::string Customer::getName() const
{
    return name;
}

void Customer::setCredit(bool credit)
{
    this-> credit = credit;
}

bool Customer::getCredit() const
{
    return credit;
}

double Customer::getBalance() const
{
    return balance;
}

void Customer::processPayment(double amount)
{
    if (amount < 0)
        throw runtime_error("Amount cannot be less than 0");
    balance += amount;
    
}

void Customer::processPurchase(double amount, Product product)
{
    if(credit == true)
    {
        balance -= amount;
    }
    
    if(credit == false)
    {
        if(balance <= amount)
        {
            balance -= amount;
        }
        else
            throw runtime_error("Amount cannot exceed balance.");
    }
    productsPurchased.push_back(product);
}

std::string Customer::getProductsPurchased() const
{
    /*
    std::stringstream buffer;
    for(int i = 0; i < productsPurchased.size(); i++)
    {
        buffer << productsPurchased.at(i) << endl;
    }
    return buffer.str();
    */
    
}


std::ostream& operator<<(std::ostream& os, Customer& rhs)
{
    os << "Customer Name: " << rhs.getName() << endl;
    os << "Customer ID: " << rhs.getID() << endl;
    os << "Has Credit: " << rhs.getCredit() << endl;
    os << "Balance: " << rhs.getBalance() << endl;
    os << "Products purchased--" << endl;
    os << endl;
    os << rhs.getProductsPurchased() << endl;
    return os;
    
}
