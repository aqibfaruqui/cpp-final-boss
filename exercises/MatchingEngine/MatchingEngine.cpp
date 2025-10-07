/* 

Problem Statement:
You are tasked with implementing the core logic for a simplified high-frequency trading matching engine. 
The engine will process orders for a single financial instrument. Your system must maintain an order book, 
which is a list of all outstanding buy and sell orders, and execute trades whenever a new order can be matched against existing ones.

The system receives a stream of messages, each representing a client action. For this initial task, you 
will handle two primary message types: adding a new order and canceling an existing one. An order is defined 
by a unique ID, a side (Buy or Sell), a price, and a quantity.

When a new 'add' order message arrives, your engine must attempt to match it against resting orders in the 
book. A buy order can match with a sell order if the buy price is greater than or equal to the sell price. 
A sell order can match with a buy order if the sell price is less than or equal to the buy price. The best-priced
orders are always matched first (highest price for buys, lowest price for sells). If an incoming order (the "aggressor") 
is filled completely or partially, trades are generated. Any remaining quantity of the aggressor order is then placed in 
the book as a new resting ("passive") order.

A 'cancel' message will specify the unique ID of an existing order to be removed from the book.

Your goal is to design the classes and methods to process these messages and accurately maintain the state of the order book.

*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <unordered_map>

// You can use standard library containers.
// Feel free to define enums and structs as you see fit.

enum class Side {
    Buy,
    Sell
};

struct Order {
    int order_id;
    int instrument_id;
    int price;
    int quantity;
    Side side;
};

struct OrderReference {
    int instrument_id;
    int price;
    Side side;
    std::list<Order>::iterator it;
};

struct OrderBook {
    std::map<int, std::list<Order>, std::greater<int>> buy_book;        // Price (descending) -> List of orders (oldest -> newest)
    std::map<int, std::list<Order>> sell_book;                          // Price (ascending) -> List of orders (oldest -> newest)
};

class MatchingEngine {
public:
    // Processes a new incoming order
    void add_order(int order_id, int instrument_id, int price, int quantity, Side side) {
        Order order{order_id, instrument_id, price, quantity, side};
        OrderBook& orderbook = instrument_to_orderbook[instrument_id];
        
        if (side == Side::Buy) { 
            while (!orderbook.sell_book.empty() && order.quantity > 0) {
                auto it = orderbook.sell_book.begin();
                auto& lowest_sells = it->second;
                auto& sell = lowest_sells.front();
                if (order.price < sell.price) break;

                int traded_quantity = std::min(order.quantity, sell.quantity);
                order.quantity -= traded_quantity;
                sell.quantity -= traded_quantity;

                // Passive sell order fulfilled
                if (sell.quantity == 0) {
                    lowest_sells.pop_front();
                    order_locations.erase(sell.order_id);

                    if (lowest_sells.empty()) {
                        orderbook.sell_book.erase(it);
                    }
                }
            }

            // Aggressor buy order not fulfilled
            if (order.quantity > 0) {
                orderbook.buy_book[order.price].push_back(order);
                auto it_to_new = std::prev(orderbook.buy_book[order.price].end());
                order_locations[order_id] = {order.instrument_id, order.price, order.side, it_to_new};
            }

        } else { // side == Side::Sell
            while (!orderbook.buy_book.empty() && order.quantity > 0) {
                auto it = orderbook.buy_book.begin();
                auto& highest_buys = it->second;
                auto& buy = highest_buys.front();
                if (order.price > buy.price) break;

                int traded_quantity = std::min(order.quantity, buy.quantity);
                order.quantity -= traded_quantity;
                buy.quantity -= traded_quantity;

                // Passive buy order fulfilled
                if (buy.quantity == 0) {
                    highest_buys.pop_front();
                    order_locations.erase(buy.order_id);

                    if (highest_buys.empty()) {
                        orderbook.buy_book.erase(it);
                    }
                }   
            }

            // Aggressor sell order not fulfilled
            if (order.quantity > 0) {
                orderbook.sell_book[order.price].push_back(order);
                auto it_to_new = std::prev(orderbook.sell_book[order.price].end());
                order_locations[order_id] = {order.instrument_id, order.price, order.side, it_to_new};
            }
        }
    }

    // Cancels an existing order from the book
    void cancel_order(int order_id) {
        auto& it = order_locations.find(order_id);
        if (it == order_locations.end()) return;

        auto& order_reference = it->second;
        auto& orderbook = instrument_to_orderbook[order_reference.instrument_id];
        auto& price = order_reference.price;

        if (order_reference.side == Side::Buy) {
            auto& price_level = orderbook.buy_book.at(price);
            price_level.erase(order_reference.it);
            if (price_level.empty()) {
                orderbook.buy_book.erase(price);
            }

        } else { // order_reference.side == Side::Sell
            auto& price_level = orderbook.sell_book.at(price);
            price_level.erase(order_reference.it);
            if (price_level.empty()) {
                orderbook.sell_book.erase(price);
            }
        }

        order_locations.erase(it);
    }

    // You may want helper functions to print or inspect the book's state
    void print_order_book() const;

private:
    std::unordered_map<int, OrderBook> instrument_to_orderbook;
    std::unordered_map<int, OrderReference> order_locations;
};

/* 

Notes to make to mock interviewer:
- break after instrument_orderbook...erase if guaranteed to have unique order id's
    - or better way to erase?
- order id maps to Order, which includes order_id - is this okay?
- 

*/