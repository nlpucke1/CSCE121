#ifndef NODE
#define NODE

struct Node {
    std::string value;
    int year;
    int month;
    double temperature;
    Node* next;
    
    // Default constructor
    Node(); // remember to initialize next to nullptr
    Node(std::string value);
    Node(std::string value, int year, int month, double temperature);
    
    bool operator<(const Node& b); //No idea what to do with this -N
    
    // The function below is written. Do not modify it
    virtual ~Node() {}
};

#endif

