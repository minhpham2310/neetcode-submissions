using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min{ prices[0] };
        int maxSell{ 0 };
        for (int i{ 1 }; i < prices.size(); ++i) {
            int profit{ prices[i] - min };
            maxSell = maxSell > profit ? maxSell : profit;
            min = min > prices[i] ? prices[i] : min;
        }
        return maxSell;
    }
};