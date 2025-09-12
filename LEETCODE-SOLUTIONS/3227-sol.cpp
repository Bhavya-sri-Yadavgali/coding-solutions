class Solution {
public:
    bool doesAliceWin(string s) {
       static const unordered_set<char> set = {'a','e','i','o','u'} ;
        return any_of(s.begin(),s.end(),[](char c){
            return set.count(c) ;
        }) ;
    }
};