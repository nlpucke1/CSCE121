#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Customer
{
    int id;
    std::string name;
    bool credit;
    double balance;
    //vector productsPurchased <Product>;
    
public:
    Customer(int, std::string, bool);
    int getID();
    std::string getName();
    void setName(std::string);
    bool getCredit();
    void setCredit(bool);
    double getBalance();
    void processPayment(double);
    void processPurchase(double, Product);
    std::string getProductsPurchased();
    
};
//std::ostream& operator<<(std::ostream& os);
#endif
