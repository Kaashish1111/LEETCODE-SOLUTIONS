class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
    int total = 0;          // total bottles drunk
    int empties = 0;        // empty bottles we have

    int full = numBottles;  // start with the given full bottles

    while (full > 0) {
        // Drink all the full bottles
        total += full;
        empties += full;
        full = 0;

        // Now exchange empties if possible
        if (empties >= numExchange) {
            int newFull = empties / numExchange;   // how many new fulls you can get
            empties = empties % numExchange;       // leftovers after exchange
            full = newFull;                        // drink them in next round
        }
    }
    return total;
    }
};