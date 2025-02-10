class Solution {
public:
    string clearDigits(string s) {
        string temp="";
        for(auto ch:s){
            if(isdigit(ch)){
                if(temp.size()>0){
                    temp.pop_back();
                }
            }else{
                temp+=ch;
            }
        }
        return temp;
    }
};