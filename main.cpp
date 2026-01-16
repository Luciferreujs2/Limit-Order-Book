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

class OrderBook{
private:
    vector<StockOrder> buyOrders; // Vector to store buy orders
    vector<StockOrder> sellOrders; // Vector to store sell orders

public:
    //Function to add a new order to the order book
    void addOrder(int id OrderType type, double price,int quantity){
        StockOrder newOrder(price, type, quantity);
        if(type == BUY){
            buyOrders.push_back(newOrder);
            // [] is a lambda function to sort buy orders
            sort(buyOrders.begin(), buyOrders.end(), [](const StockOrder &a, const StockOrder &b){
                return a.price > b.price; //Highest price wins
                // Sort buy orders in descending order of price so person offering most money gets priority
            });
        } else {
            sellOrders.push_back(newOrder);
            sort(sellOrders.begin(), sellOrders.end(), [](const StockOrder &a, const StockOrder &b){
                return a.price < b.price; //Lowest price wins
                // Sort sell orders in ascending order of price so person asking least money gets priority
            });
        }
    }



}

int main(){
    cout<<"---Limit Order Book has been initialized---"<<endl;



    
    return 0;
}       
