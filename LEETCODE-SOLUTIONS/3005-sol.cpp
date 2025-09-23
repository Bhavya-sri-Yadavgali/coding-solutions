class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> map ;
        int max = 0 ;

        for(int x :nums){
            map[x]++ ;
            max = std::max(max,map[x]) ;
        }

        int count = 0;

        for(auto x : map){

            if(x.second >= max){

                count++ ;

            }

        }

        return count*max ;
    }
};