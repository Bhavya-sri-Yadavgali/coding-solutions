class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size() ;
        for(int x = 0 ; x < nums.size() ; x++){
                if(nums[x] >  nums[(x+1)%n]){
                    count++ ;
                }
        }
        if(count == 0 || count == 1){
            return true ;
        }
        else{
           return false ;
        }
    }
};