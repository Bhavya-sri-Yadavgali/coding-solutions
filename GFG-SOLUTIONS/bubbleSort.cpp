class Solution {
  public:
  // USING RECURSION 
    void bubbleSort(vector<int>& arr,int lastindex){
        
        if(lastindex > 0){
             for(int j = 0 ; j < lastindex;j++){
                if(arr[j+1] < arr[j]){
                    std::swap(arr[j+1],arr[j]) ;
                }
          }
    
          bubbleSort(arr,lastindex-1) ;
        }
        
    }
    void bubbleSort(vector<int>& arr) {
        // code here
        int n = arr.size() ;
         
        bubbleSort(arr,n-1) ; 
    }
};