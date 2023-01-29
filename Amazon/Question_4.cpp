// Tweet Counts Per Frequency

class TweetCounts {
    unordered_map<string, vector<int>> twitMap;
    
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        twitMap[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if (startTime > endTime || twitMap.find(tweetName) == twitMap.end())
            return vector<int>();
        
        int interval;
        if (freq == "minute")
            interval = 60;
        else if (freq == "hour")
            interval = 3600;
        else
            interval = 86400;
        
        // number of intervals
        int len = ceil((double) (endTime - startTime + 1) / interval);
        vector<int> ans(len, 0);
        for (int x: twitMap[tweetName]) {
            if (x < startTime || x > endTime) continue;
            // put the tweet in corresponding slot
            ans[floor((double) (x - startTime) / interval)]++;
        }
        
        return ans;
    }
};