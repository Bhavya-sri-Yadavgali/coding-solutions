class Solution {
public:
    bool isPalindrome(int x) {
         long result = 0 ;
         if(x < 0){
            return false ;
         }
         
         int n = x ;

         while(n > 0){
             result = result * 10 ;
             result += (n % 10) ;
             n = n/10 ;
         }

         if(result == (long)x){
            return true ;
         }

        
        return false ;
    }
};