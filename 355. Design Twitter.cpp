class Twitter
{
private:
    int timer;

    // userId -> set of followees
    unordered_map<int, unordered_set<int>> following;

    // userId -> {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter()
    {
        timer = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> result;

        // user always follows himself
        following[userId].insert(userId);

        // {timestamp, tweetId, userId, index}
        priority_queue<vector<int>> pq;

        for (int followee : following[userId])
        {
            if (!tweets[followee].empty())
            {
                int idx = tweets[followee].size() - 1;

                pq.push({tweets[followee][idx].first,  // timestamp
                         tweets[followee][idx].second, // tweetId
                         followee,
                         idx});
            }
        }

        while (!pq.empty() && result.size() < 10)
        {
            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            result.push_back(tweetId);

            idx--;
            if (idx >= 0)
            {
                pq.push({tweets[user][idx].first,
                         tweets[user][idx].second,
                         user,
                         idx});
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};