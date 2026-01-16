#include<iostream>
#include <vector>
#include<algorithm>
#include <string>
using namespace std;


//Enum to distinguish Buy and Sell actions
enum OrderType {
    BUY,
    SELL
};

//Class to represent a stock order
class StockOrder {
public:
    double price; // Price of the stock
    OrderType type;  //BUY OR SELL
    int quantity; // Number of shares

    //Constructor to initialize stock order
    StockOrder(double p, OrderType t, int q) : price(p), type(t), quantity(q) {}
};


int main(){
    cout<<"---Limit Order Book has been initialized---"<<endl;



    
    return 0;
}