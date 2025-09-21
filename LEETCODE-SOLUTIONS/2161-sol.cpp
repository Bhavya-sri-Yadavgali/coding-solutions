class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        

        vector<int> lessThanPivot ;
        vector<int> equalToPivot  ;
        vector<int> greaterThanPivot ;
        

        for(int i = 0 ;i < nums.size();i++){
            if(nums[i] < pivot){
                lessThanPivot.push_back(nums[i]);
            }
            else if(nums[i] == pivot){
                equalToPivot.push_back(nums[i]);
            }
            else{
                greaterThanPivot.push_back(nums[i]);
            }
        }

        lessThanPivot.insert(lessThanPivot.end(),equalToPivot.begin(),equalToPivot.end()) ;

        lessThanPivot.insert(lessThanPivot.end(),greaterThanPivot.begin(),greaterThanPivot.end()) ;



       return lessThanPivot ;
    }
};