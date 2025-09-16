class Solution {
public:
    int gcd(int a,int b){
        if(a%b == 0){
            return b ;
        }
        return gcd(b,a%b) ;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st ;
       for(int x : nums){
            long long  cur = x ;
            while(!st.empty()){
                int d = gcd(st.back(),cur);
                if(d == 1){
                    break ;
                }
                cur = ((st.back()/d) * cur) ;
                st.pop_back();
            }
            st.push_back(cur) ;
       }
        return vector<int>(st.begin(),st.end()) ;
    }
};