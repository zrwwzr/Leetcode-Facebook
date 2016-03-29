class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;
        int start = 0, end = s.length() - 1;
        while(start < end){
            while(start < s.length() && !isalpha(s[start]) && !isdigit(s[start])) start++;
            while(end > 0 && !isalpha(s[end]) && !isdigit(s[end])) end--;
            //mean there is no alphanumerics
            if(start >= end) return true;
            if(tolower(s[start++]) != tolower(s[end--])) return false;
        }
        return true;
    }
};
