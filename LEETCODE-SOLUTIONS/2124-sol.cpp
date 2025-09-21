class Solution {
public:
    bool checkString(string& s) {
        bool check = true;
        for(const int& c : s){ // int& used to save memory
            if(check && c == 98) // 'b' = 98
                check = false;
            else if(!check && c == 97) // 'a' = 97
                return false;
        }
        return true;
    }
};