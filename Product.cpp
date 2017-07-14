#include <iostream>
#include <string>
#include <stdexcept>
#include "Product.h"

using namespace std;

Product::Product(int id, string name) : id(id), name(name),
inventory(0), numSold(0), totalPaid(0.0),  description("")
{
    if (name.length()==0)
        throw runtime_error("Product name cannot be empty.");
}

int Product::getID()
{
    return id;
}

void Product::setName(string name)
{
    if (name.length()==0)
        throw runtime_error("Product name cannot be empty.");
    this->name = name; // could use an else, but it will only get here
    //   if there was not an exception!
}

string Product::getName()
{
    return name;
}

void Product::setDescription(string description)
{
    if(description == "")
    {
        description = "No description.";
    }
    this -> description = description;
}

string Product::getDescription()
{
    return description;
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

int Product::getNumberSold()
{
    return numSold;
}

double Product::getTotalPaid()
{
    return totalPaid;
}

int Product::getInventoryCount()
{
    return inventory;
}

double Product::getPrice()
{
    double price = (totalPaid / (inventory + numSold)) * 1.25;
    return price;
}
std::ostream& operator<<(std::ostream& os, const Product& p)
{

}
