class Solution {
public:
    bool AnyCommonLanguage(vector<int> a,vector<int> b){

        unordered_set<int> set(a.begin(),a.end()) ;

        for(int i = 0 ; i < b.size();i++){

            if(set.find(b[i]) != set.end()){
                return true ;
            }

        }

       return false ;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int count = INT_MAX;
        unordered_set<int> people ;
        
       for(vector<int> t : friendships){
           if(!AnyCommonLanguage(languages[t[0]-1],languages[t[1]-1])){
              people.insert(t[0]);
              people.insert(t[1]) ;
           }
       }

        for(int i = 1 ; i <= n ;i++){
            int c = 0 ;
            for(int x : people){
                if( !AnyCommonLanguage(languages[x-1],{i})){
                    c++ ;
                }
            }
            count = min(count,c) ;
        }
        

        return count ;
    }
};