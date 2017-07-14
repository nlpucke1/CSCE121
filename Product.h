#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
    int id;
    std::string name;
    std::string description;
    int inventory;
    int numSold;
    double totalPaid;
    
public:
    Product(int, std::string);
    int getID() const;
    std::string getName() const;
    std::string setName(std::string);
    std::string getDescription() const;
    void setDescription(std::string);
    int getNumberSold() const;
    double getTotalPaid() const;
    int getInventoryCount() const;
    double getPrice() const;
    void addShipment(int, double);
    void reduceInventory(int);
};
std::ostream& operator<<(std::ostream& os, Product&);
#endif

