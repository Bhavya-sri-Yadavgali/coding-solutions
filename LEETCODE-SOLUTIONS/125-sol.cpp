class Solution {
public:
    bool isPalindrome(string s) {
        int j = 0 ;
        string rev ;
        for(int i = 0 ; i < s.length();i++){
            char c = s[i] ;
            if(int(c) >= (int)'A'&& int(c) <= (int)'Z'){
                 s[i] = tolower(c) ;
                 s[j++] = s[i] ;
            }
            else if(int(c) >= (int)'a' && int(c) <= (int)'z'){

                s[j++] = s[i] ;

            }
            else if(int(c) >= (int)'0' && int(c) <= (int)'9'){
                s[j++] = s[i] ;
            }
        }

        s.resize(j) ;


        rev.resize(j) ;

        reverse_copy(s.begin(),s.end(),rev.begin()) ;

        if(s == rev){
            return true ;
        }

            return false ;
    }
};