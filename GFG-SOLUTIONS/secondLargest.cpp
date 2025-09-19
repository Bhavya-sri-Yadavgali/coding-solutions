class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = 0;
        int secondLargest = -1 ;
        
        for(int x : arr){
            if(x > largest){
                if(largest != 0){
                    secondLargest = largest ;
                }
                largest = x ;
            }
            else if(x < largest && x > secondLargest){
                secondLargest = x ; 
            }
        }
    return secondLargest ;
    }
    
};