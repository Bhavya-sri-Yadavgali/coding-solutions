class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        int least ;
        int min;
        for(int pass=0;pass<=n-2;pass++){
            least = arr[pass];
            min = pass;
            for(int i = pass+1 ; i < n ; i++){
                if(arr[i]<least){
                    least = arr[i];
                    min = i;
                }   
            }
            swap(arr[pass],arr[min]);
        }
    }
};