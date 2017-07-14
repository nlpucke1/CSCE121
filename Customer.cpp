#include <iostream>
#include <string>
#include <stdexcept>
#include "Product.h"
#include "Customer.h"
using namespace std;

Customer::Customer(int id, std::string name, bool credit) :
id(id), name(name), credit(credit), balance(0.0)
{
    if (name.length()==0)
        throw runtime_error("Product name cannot be empty.");
}

int Customer::getID()
{
    return id;
}

void Customer::setName(std::string name)
{
    this->name = name;
}

std::string Customer::getName()
{
    return name;
}

void Customer::setCredit(bool credit)
{
    this-> credit = credit;
}

bool Customer::getCredit()
{
    return credit;
}

double Customer::getBalance()
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
}
/*
std::string getProductsPurchased()
{
    return
}
*/
std::ostream& operator<<(std::ostream& os, const Customer& cust){

}
