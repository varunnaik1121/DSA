class Solution {
    bool helper(int i,int total,int n){
        if(total==n) return true;
        if(pow(3,i)+total>n) return false;
        if(helper(i+1,total+pow(3,i),n)){
            return true;
        } 
        if(helper(i+1,total,n)){
            return true;
        }
        return false;
    }
public:
    bool checkPowersOfThree(int n) {
        return helper(-1,0,n);
    }

};