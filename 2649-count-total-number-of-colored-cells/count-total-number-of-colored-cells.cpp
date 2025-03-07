class Solution {
public:
    long long coloredCells(int n) {
        long long temp=0;
        
        if(n==1){
            return 1;
        }else{
            long long j=1;
    
            for(int i=1;i<=n-1;i++){
                temp+=j;
                j+=2;
            }
            temp=2*temp;
            temp+=j;
        }
        return temp;
    }
};