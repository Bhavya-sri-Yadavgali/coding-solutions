class Solution {
  public:
    int countDigits(int n) {
        // code here
        
        int count = 0 ;
        do{
            
            count++ ;
            n = n/10 ;
            
        }while(n >  0);
        
        return count ;
    }
};