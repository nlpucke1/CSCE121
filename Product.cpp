#include <iostream>
#include <string>
#include <stdexcept>
#include "Product.h"
using namespace std;

Product::Product(int id, string name) : id(id), name(name),
inventory(0), numSold(0), totalPaid(0.0)
{
    if (name.length()==0)
        throw runtime_error("Product name cannot be empty.");
}

int Product::getID() const
{
    return id;
}

string Product::getName() const
{
    return name;
}

std::string Product::setName(std::string name)
{
    if (name.length()==0)
        throw runtime_error("Product name cannot be empty.");
    this->name = name; // could use an else, but it will only get here
    //   if there was not an exception!
    return this->name;
}

string Product::getDescription() const
{
    return description;
}

void Product::setDescription(string description)
{
    if(description == "")
    {
        description = "No description.";
    }
    this-> description = description;
}

int Product::getNumberSold() const
{
    return numSold;
}

double Product::getTotalPaid() const
{
    return totalPaid;
}

int Product::getInventoryCount() const
{
    return inventory;
}

double Product::getPrice() const
{
    double price = (totalPaid / (inventory + numSold)) * 1.25;
    return price;
}

void Product::addShipment(int quantity, double shipmentCost)
{
    if (quantity < 0)
        throw runtime_error("Shipment quantity must be positive.");
    if (shipmentCost < 0)
        throw runtime_error("Shipment cost must be positive.");
    inventory += quantity;
    totalPaid += shipmentCost;
    //cout << "quantity: " << quantity << endl;
    //cout << "inventory: " << inventory << endl;
}

void Product::reduceInventory(int purchaseQuantity)
{
    if(inventory < purchaseQuantity)
    {
        throw runtime_error("Purchase quantity exceeds inventory.");
    }
    if(purchaseQuantity < 0)
    {
        throw runtime_error("Purchase quantity cannot be negative.");
    }
    inventory -= purchaseQuantity;
    numSold += purchaseQuantity;
}

std::ostream& operator<<(std::ostream& os, Product& rhs)
{
    os << "Product Name: " << rhs.getName() << endl;
    os << "Product ID: " << rhs.getID() << endl;
    os << "Description: " << rhs.getDescription() << endl;
    os << "Inventory: " << rhs.getInventoryCount() << endl;
    os << "Total Paid: " << rhs.getTotalPaid() << endl;
    return os;
}

