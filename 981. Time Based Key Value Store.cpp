class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> time_map;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        time_map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (time_map.find(key) == time_map.end())
            return "";
        auto &vec = time_map[key];
        int left = 0;
        int right = vec.size() - 1;
        string ans = "";
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (vec[mid].first <= timestamp)
            {
                ans = vec[mid].second;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */