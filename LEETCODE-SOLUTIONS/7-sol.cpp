class Solution {
public:
    int reverse(int x) {

        int rev = 0;
        
        
        while(x !=  0){

            // % stores the sign of the dividend 

            // division trucates towards zero and also stores the the sign of the dividend 

            int pop = x % 10 ;

            if( rev == INT_MAX/10 && pop > 7) {
                return 0 ;
            }
            else if(rev > INT_MAX/10){
                return 0 ;
            }
            else if(rev < INT_MIN/10){
                return 0 ;
            }
            else if(rev == INT_MIN/10 && pop < -8){
                return 0 ;
            }

            rev = rev*10 + pop ;

            x = x/10 ;

        }

        return  rev ;

    }
};