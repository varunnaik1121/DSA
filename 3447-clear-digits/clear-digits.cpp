class Solution {
public:
    string clearDigits(string s) {
        string temp="";
        int j;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                j=i-1;
                while(j>=0){
                    if(isalpha(s[j])){
                        s[j]='#';
                        break;
                    }
                    j--;
                }
            }
        }
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i]) && s[i]!='#'){
                temp+=s[i];
            }
        }
        return temp;
    }
};