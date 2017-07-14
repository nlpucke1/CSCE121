#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

// note cannot have a "using namespace std;" statement in header file

class Product {
    int id;
    std::string name;
    std::string description;
    int inventory;
    int numSold;
    double totalPaid;

public:
    Product(int, std::string);
    int getID();
    std::string getName();
    void setName(std::string);
    std::string getDescription();
    void setDescription(std::string);
    int getNumberSold();
    double getTotalPaid();
    int getInventoryCount();
    double getPrice();
    void addShipment(int, double);
    void reduceInventory(int);
};
std::ostream& operator<<(std::ostream& os, const Product& p);
#endif
