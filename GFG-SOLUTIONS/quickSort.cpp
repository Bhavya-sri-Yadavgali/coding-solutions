class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        
        if(low <= high){
            int p = partition(arr,low,high) ;
            quickSort(arr,low,p-1) ;
            quickSort(arr,p+1,high) ;
        }
        
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        
        
        int pivot = arr[high] ;
        int k = low-1 ;
        for(int i = low ;i < high;i++){
            
            if(arr[i] < pivot){
                std::swap(arr[i],arr[++k]) ;
            }
            
           
        }
           swap(arr[k+1],arr[high]) ;
           return k+1 ;
    }
};