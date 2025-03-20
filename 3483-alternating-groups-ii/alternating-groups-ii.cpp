class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        for(int l=0;l<k-1;l++){
            colors.push_back(colors[l]);
        }
        int i=0,j=1;
        int ans=0;
        while(j<colors.size()){
            if(colors[j]==colors[j-1]){
                i=j;
                j++;
                continue;
            }
            if(j-i+1==k){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};