// 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            minPrice = min(minPrice, price);           // 更新最低买入价
            maxProfit = max(maxProfit, price - minPrice); // 更新最大利润
        }
        
        return maxProfit;
    }
};