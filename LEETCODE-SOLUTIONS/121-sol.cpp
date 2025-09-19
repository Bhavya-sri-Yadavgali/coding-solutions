class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
       int maxProfit  = 0 ;

       int Min  = prices[0];
       int n = prices.size();
       int profit ;

       for(int i =1;i<n;i++){
           if(Min > prices[i]){
             Min = prices[i];
           }
           else{
              profit = prices[i] - Min;
              maxProfit = std::max(maxProfit,profit);
           }
       }
    return maxProfit ;
    }
};