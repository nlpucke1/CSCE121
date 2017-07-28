#ifndef NODE
#define NODE

struct Node {
    int value;
    int year;
    int month;
    Node* next;
    
    // Default constructor
    Node(); // remember to initialize next to nullptr
    Node(int value); // remember to initialize next to nullptr
    //The skeleton code provided made a constructor that doesn't match anything in the cpp file?? -N
    
    bool operator<(const Node& b); //No idea what to do with this -N
    
    // The function below is written. Do not modify it
    virtual ~Node() {}
};

#endif
