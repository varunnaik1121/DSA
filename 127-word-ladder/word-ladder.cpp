class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,0});
        if(beginWord==endWord ) return 0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string word=it.first;
            int val=it.second;
            if(word==endWord) return val+1;
             string temp=word;
            for(int i=0;i<word.size();i++){
               
                char prev=temp[i];
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(st.find(temp)!=st.end()){
                        q.push({temp,val+1});
                        st.erase(temp);
                    }
                }
                temp[i]=prev;
                
            }
        }
        return 0;
    }
};