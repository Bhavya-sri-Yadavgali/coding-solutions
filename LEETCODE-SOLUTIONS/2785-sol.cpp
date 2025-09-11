class Solution {
public:
    string sortVowels(string s) {
        string vowelOrder = "AEIOUaeiou" ;
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'} ;
       unordered_map<char,int> map ;


        int k = 0 ;
        
         for(char x : s){
            if(vowels.count(x)){
               map[x]++ ;
            }
         }

         
         for(int i = 0 ;i < s.size();i++){
            char x = s[i] ;
            if(vowels.count(x)){
               while(k < vowelOrder.size() && map[vowelOrder[k]] == 0){
                 k++ ;
               }
               s[i] = vowelOrder[k] ;
               map[vowelOrder[k]]-- ;
            }
         }

         return s ;
    }
};