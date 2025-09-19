class Solution {
public:

    // KADANE'S   ALGORITHM
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = nums[0];

        for(int j = 0 ; j < nums.size();j++){
               sum += nums[j];
               if(sum > max){
                max = sum ;
               }
               if(sum < 0){
                sum = 0 ;
               }
        }

        return max ;
    }
};