class Solution {
public:
    bool isPalindrome(string s) {
        int start=0,end=s.length()-1;
        while(start<end){
            while(start<=s.length()-1 && !isalnum(s[start])){
                start++;
            }
            while(end>=0 && !isalnum(s[end])) end--;
            if (start<end){
                
                if(!isalnum(s[start])||!isalnum(s[end])) return false;
                if(tolower(s[start])!=tolower(s[end])) return false;
                start++;end--;
            }
        }
        return true;
    }
};