class Twitter {
    int time;
    unordered_map<int, vector<pair<int,int>>> User2Post;
    unordered_map<int, unordered_set<int>> User2Follow;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        User2Post[userId].push_back({time, tweetId});
        if (User2Follow[userId].find(userId) == User2Follow[userId].end()) {
            User2Follow[userId].insert(userId);
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
    
        for (auto f : User2Follow[userId]) {
            for (auto post : User2Post[f]) {
                pq.push(post);
            }
        }
        
        vector<int> res;
        for (int i = 0; i < 10; i++) {
            if (pq.size() > 0) {
                auto element = pq.top();
                res.push_back(element.second);
                pq.pop();
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        User2Follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (User2Follow[followerId].find(followeeId) != User2Follow[followerId].end()) {
            User2Follow[followerId].erase(followeeId);
        }
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
