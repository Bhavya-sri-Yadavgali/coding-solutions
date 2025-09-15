class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = brokenLetters.length() ;
        int count = 0 ;
        unordered_set<char> bl(brokenLetters.begin(),brokenLetters.end());
        for(int i = 0 ; i < text.length();i++){
            bool flag = true ;
            while(i < text.length() && text[i] != ' '){
                if(bl.count(text[i])){
                    flag = false ;
                }
                i++ ;
            }

            if((((i < text.length() && text[i] == ' ') || (i >= text.length())) && flag == true)){
                count++ ;
            }
        }

        return count ;
    }
};