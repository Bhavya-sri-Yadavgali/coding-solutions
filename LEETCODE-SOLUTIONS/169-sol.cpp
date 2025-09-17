class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // BRUTE FORCE APPROACH 

        
        int n = nums.size();
        unordered_map<int,int> m ;
        for(int i=0;i< nums.size();i++){       
                m[nums[i]]++;     
        }
        int max ;

        for(auto p : m){
            if(p.second > (n/2)){
                max = p.first ;
                return p.first ;
            }
        }

        return max ;
    }
};