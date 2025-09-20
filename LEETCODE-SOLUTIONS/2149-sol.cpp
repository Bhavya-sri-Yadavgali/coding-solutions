class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos ;
        vector<int> neg ;

    
        int j = 0;
        int k = 0;

        for(int i = 0; i < n;i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);    
               
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        for(int i = 0;i < n;i++){
            if(i%2 == 0 && j < pos.size()){
                nums[i] = pos[j++];
            }
            else if(i%2 != 0 && k < neg.size()){
                nums[i] = neg[k++] ;
            }
        }
        
        

        return nums ;
    }
};