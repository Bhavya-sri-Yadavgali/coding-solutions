class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        int i ;
        for( i = 1;i*i <= n;i++){
            if(n%i == 0){
                cout << i << " " ;
            }
        }
        i = i-1 ;
        
        for( ;i >= 1;i--){
            if(i != n/i  && n%i == 0){
                cout<< n/i << " ";
            }
        }
    }
};