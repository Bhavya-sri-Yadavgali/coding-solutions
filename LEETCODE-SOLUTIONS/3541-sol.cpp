class Solution {
public:
    int maxFreqSum(string s) {
        
        unordered_map<char,int> vowels = {{'a',0},{'e',0},{'i',0},{'o',0},{'u',0}};
        unordered_map<char,int> consonants ;
        int vowelmax = 0 ;
        int consonantmax = 0 ;

        for(char x : s){
            if(vowels.count(x)){
                vowels[x]++ ;
                vowelmax = max(vowelmax,vowels[x]);
            }
            else{
                consonants[x]++ ;
                consonantmax = max(consonantmax,consonants[x]) ;

            }
        }

        return vowelmax + consonantmax ;

            }

};