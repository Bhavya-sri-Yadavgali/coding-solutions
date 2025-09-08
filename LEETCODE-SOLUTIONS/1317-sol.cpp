class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int place = 1 ;
        int a = 0;
        int b = 0 ;
        while(n > 0){
          // HANDLING EXPLICITY IF N == 1 
            if(n == 1){

                a = a + 1 * place ;
                return {a,b} ;

            }
            int d = n%10 ;
            n = n/10 ;

            if(d == 0 || d == 1){
                d = d+10;
                n-- ;
            }

            if(d == 11){
                a = a + 9*place ;
                b = b + 2*place ;
            }
            else{
                a = a + (d-1)*place ;
                b = b + 1*place ;
            }

            place = place * 10 ;

        }

        return {a,b} ;
    }
};