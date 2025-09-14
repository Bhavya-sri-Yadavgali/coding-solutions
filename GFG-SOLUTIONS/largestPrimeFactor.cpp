class Solution {
  public:
    int largestPrimeFactor(int n) {
        // code here
       vector<int> vec ;
       
       while(n%2 == 0){
           vec.push_back(2);
           n = n/2 ;
       }
       
       while(n%3 == 0){
           vec.push_back(3);
           n = n/3 ;
       }
       
       for(int i = 5 ; i*i <= n ;i=i+6){
           
           while(n%i == 0){
               vec.push_back(i) ;
               n = n/i ;
           }
           while(n % (i+2) == 0){
               vec.push_back(i+2);
               n = n / (i+2) ;
           }
           
       }
       
       if(n > 3){
           vec.push_back(n) ;
       }
       
       sort(vec.begin(),vec.end());
       
       return vec.back() ;
        
    }
};