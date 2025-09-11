class Solution {
  public:
    void merge(vector<int>& arr, int l,int mid,int r){
        vector<int> left(mid-l+1);
        vector<int> right(r-mid);
        for(int i = 0 ; i < mid-l+1;i++){
            left[i] = arr[l+i] ;
        }
        for(int i = 0 ; i < r-mid;i++){
            right[i] = arr[mid+1+i] ;
        }
        int n = left.size();
        int m = right.size();
        int j = 0 ;//left
        int i = 0 ; //right
        int k = l ;
        
        while(i < m && j < n){
            if(right[i] <= left[j]){
                arr[k++] = right[i++];
            }
            else{
                arr[k++] = left[j++] ;
            }
        }
        while(j < n){
            arr[k++] = left[j++] ;
        }
        while(i < m){
            arr[k++] = right[i++] ;
        }
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l < r){
            int mid = l + (r-l)/2 ;
            mergeSort(arr,l,mid) ;
            mergeSort(arr,mid+1,r) ;
            merge(arr,l,mid,r);
        }
    }
};