class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        
        for(int i = 1; i < arr.size();i++){
            int j = i-1;
            int pass = arr[i] ;
            while(j >= 0 && arr[j] > pass){
                  arr[j+1] = arr[j] ;
                  j-- ;
            }
            arr[j+1] = pass ;
        }
    }
};