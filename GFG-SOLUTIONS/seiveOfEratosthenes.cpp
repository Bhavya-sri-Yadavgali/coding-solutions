class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<bool> isPrime(n+1,true) ;
        vector<int> vec ;
        
        for(int i = 2 ; i <= n ;i++){
            if(isPrime[i]){
                vec.push_back(i) ;
                for(int j = i*i ;j <= n;j=j+i){
                    isPrime[j] = false ;
                }
            }
        }
        
        return vec ;
    }
};