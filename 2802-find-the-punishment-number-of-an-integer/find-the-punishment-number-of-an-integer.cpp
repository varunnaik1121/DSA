class Solution {
public:
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(helper(i,to_string(i*i))){
                ans+=i*i;
            }
        }
        return ans;
    }
    bool helper(int target,string num){
        if(num.size()==0 && target==0){
            return true;
        }
        if(target<0) return false;
        for(int i=0;i<num.size();i++){
            string left=num.substr(0,i+1);
            string right=num.substr(i+1);
            if(helper(target-stoi(left),right)) return true;
        }
        return false;
    }
};