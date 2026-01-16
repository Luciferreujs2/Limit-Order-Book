# High-Performance C++ Limit Order Book

## 📌 Project Overview
As a Mechanical Engineering student at IIT Madras, I am fascinated by how complex systems handle high-speed inputs. This project is a simulation of a financial exchange matching engine. It’s designed to handle multiple buy and sell orders, organizing them by **Price-Time Priority** and executing trades the moment market conditions are met.

## ⚙️ How It Works
The engine uses a dual-vector system to manage the "market":
* **The Bid Queue (Buyers):** Automatically sorted so the highest bidder is at the front.
* **The Ask Queue (Sellers):** Automatically sorted so the cheapest seller is at the front.
* **The Matching Logic:** A `while` loop continuously monitors the "Top of Book." If a buyer's price is greater than or equal to a seller's price, the engine calculates the trade quantity, updates the order states, and clears filled orders from the system.

## 🛠 Technical Features
* **Object-Oriented Programming (OOP):** Used classes and constructors to represent `StockOrder` entities with unique IDs.
* **STL Optimization:** Leveraged C++ `sort` with custom **Lambda expressions( [] )** for O(N \log N) sorting efficiency.
* **State Management:** Implemented logic to handle partial fills (e.g., a 10-share buy order matching with a 5-share sell order, leaving 5 shares remaining).
* **Type Safety:** Utilized `enum` classes to distinguish between `BUY` and `SELL` actions, preventing logic errors.
