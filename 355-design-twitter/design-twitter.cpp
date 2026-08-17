class Twitter {
    int time;
    // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,<pair<int,int>>>> pq;
    vector<pair<int,pair<int,int>>> pq;
    unordered_map<int,vector<int>> mpp;
    unordered_map<int,set<int>> followMpp;
public:
    Twitter() {
       time=0; 
    }
    
    void postTweet(int userId, int tweetId) {
       time+=1;
       pq.push_back({time,{tweetId,userId}});
       mpp[userId].push_back(tweetId); 
    }
    
    vector<int> getNewsFeed(int userId) {
        set<int> userIds;
        userIds.insert(userId);
        for(auto it:followMpp[userId]){
            userIds.insert(it);
        }
        int cnt=0;
        vector<int> newsFeedIds;
        int n=pq.size();
        for(int i=n-1;i>=0;i--){
            auto temp=pq[i];
            if(userIds.find(temp.second.second)!=userIds.end() && newsFeedIds.size()<10){
                newsFeedIds.push_back(temp.second.first);
            }

        }
        return newsFeedIds;

    }
    
    void follow(int followerId, int followeeId) {
        followMpp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMpp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */