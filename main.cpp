#include <iostream>
#include <stdexcept>
#include "Product.h"
#include "Customer.h"
using namespace std;

int main(int argc, const char * argv[])
{
    try
    {
        Product p(1234, "Carrots");
        p.setDescription("Orange.");
        p.addShipment(25, 100);
        cout << p << endl;
        
        Customer a(123, "Jessica Alba", true);
        a.processPayment(1000);
        a.processPurchase(200, p);
        a.processPurchase(100, p);
        
        cout << a << endl;
        
    }
    catch(runtime_error &e)
    {
        cout << "Exception caught: " <<  e.what() << endl;
    }
    
    return 0;
}
