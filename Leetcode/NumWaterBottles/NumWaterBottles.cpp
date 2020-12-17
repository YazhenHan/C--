class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        numBottles = numBottles / numExchange + numBottles % numExchange;
        while (numBottles >= numExchange)
        {
            res += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }
        return res;
    }
};