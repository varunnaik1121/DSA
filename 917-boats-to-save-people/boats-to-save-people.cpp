class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boatsUsed=0;
        int L=0,R=people.size()-1;
        while(L<=R){
            int weight=people[L]+people[R];
            if(weight<=limit){
                boatsUsed+=1;
                L++;
                R--;
            }else{
                boatsUsed+=1;
                R--;
            }
        }
        return boatsUsed;
        
    }
};