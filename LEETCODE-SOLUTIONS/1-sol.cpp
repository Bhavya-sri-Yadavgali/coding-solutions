class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> j ;
        // m.insert({nums[0],0});
        for(int i = 0;i<nums.size();i++){
           if(m.find(target - nums[i]) != m.end()){
               auto it = m.find(target - nums[i]);
               j = {it ->second , i};
               return j;
           }
           else{
             m.insert({nums[i],i});
           }
        }
        return j ;
    }
    
};