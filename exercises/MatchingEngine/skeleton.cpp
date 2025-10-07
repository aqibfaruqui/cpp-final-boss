#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

// You can use standard library containers.
// Feel free to define enums and structs as you see fit.

enum class Side {
    Buy,
    Sell
};

class MatchingEngine {
public:
    // Processes a new incoming order
    void add_order(int order_id, int instrument_id, int price, int quantity, Side side);

    // Cancels an existing order from the book
    void cancel_order(int order_id);

    // You may want helper functions to print or inspect the book's state
    void print_order_book() const;

private:
    
};