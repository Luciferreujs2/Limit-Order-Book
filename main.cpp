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
    int id; // Unique identifier for the order              
    double price; // Price of the stock
    OrderType type;  //BUY OR SELL
    int quantity; // Number of shares   

    //Constructor to initialize stock order
    StockOrder(int i,double p, OrderType t, int q) : id(i), price(p), type(t), quantity(q) {}
};

class OrderBook{
private:
    vector<StockOrder> buyOrders; // Vector to store buy orders
    vector<StockOrder> sellOrders; // Vector to store sell orders

public:
    //Function to add a new order to the order book
    void addOrder(int id, OrderType type, double price,int quantity){
        StockOrder newOrder(id,price, type, quantity);
        
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
        matchOrders(); //Check for matches after adding a new order
    }

    void matchOrders(){
        // While there are buy and sell orders and the highest buy price is greater than or equal to the lowest sell price
        while(!buyOrders.empty() && !sellOrders.empty() && buyOrders[0].price >= sellOrders[0].price){
            int tradeQuantity = min(buyOrders[0].quantity, sellOrders[0].quantity);
            cout<<"Trade executed: "<<tradeQuantity<<" shares at price "<<sellOrders[0].price<<endl;   
            buyOrders[0].quantity -= tradeQuantity;
            sellOrders[0].quantity -= tradeQuantity;
            if(buyOrders[0].quantity == 0){
                buyOrders.erase(buyOrders.begin());
            }
            if(sellOrders[0].quantity == 0){
                sellOrders.erase(sellOrders.begin());
            }
        }
    }   
};
int main(){
    cout<<"---Limit Order Book has been initialized---"<<endl;
    OrderBook exchange;
    exchange.addOrder(1, BUY, 100.0, 10); // Buy
    exchange.addOrder(2, SELL, 99.0, 5);  // Sell
    exchange.addOrder(3, SELL, 98.0, 10); // Sell
    exchange.addOrder(4, BUY, 101.0, 15); // Buy


    
    return 0;
}               
