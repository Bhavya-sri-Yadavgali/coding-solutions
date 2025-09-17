class Solution {
public:

   int fib(int n){

    vector<int> dp(n+1,-1) ;
    return fibo(n,dp) ;

   }
    int fibo(int n,vector<int>& dp) {
        //your code goes here

        if(n==0){
            return 0;
        }
        if(n == 1){
            return 1 ;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        else{
            return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
        }

    }
};