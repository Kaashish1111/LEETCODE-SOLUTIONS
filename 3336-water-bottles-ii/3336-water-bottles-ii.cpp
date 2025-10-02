class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
    int total = 0;               // total drunk
    int full = numBottles;       // current full bottles
    int empty = 0;               // empty bottles
    int cost = numExchange;      // current exchange cost

    while (full > 0) {
        // Drink all full bottles
        total += full;
        empty += full;
        full = 0;

        // Try to exchange if possible
        if (empty >= cost) {
            empty -= cost;   // spend empties
            full += 1;       // get 1 new full bottle
            cost += 1;       // cost increases for next time
        }
        else {
            break; // cannot exchange anymore
        }
    }

    return total;
    }
};