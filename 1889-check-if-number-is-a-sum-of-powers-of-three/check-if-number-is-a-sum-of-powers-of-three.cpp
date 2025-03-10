class Solution {
    bool helper(int i,int total,int n){
        if(total==n) return true;
        if(total>n){
            return false;
        }
        if(pow(3,i)+total>n) return false;
        return helper(i+1,total+pow(3,i),n) || helper(i+1,total,n);
    }
public:
    bool checkPowersOfThree(int n) {
        return helper(-1,0,n);
    }

};