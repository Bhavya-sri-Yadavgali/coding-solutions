class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int x = n ;
        int result = 0 ;
        while(x > 0){
            int p = x%10 ;
            result += p*p*p ;
            x = x/10 ;
        }
        
        return result == n ;
    }
};