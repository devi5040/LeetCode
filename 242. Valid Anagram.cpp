// Sort technique
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};

// Hash table
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for(char ch1:s)
            map1[ch1]++;
        for(char ch2:t)
            map2[ch2]++;
        if(map1!=map2)
            return false;
        return true;
    }
};

// Optimized solution: Using vector
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> freq(26, 0);
        for(int i=0; i<s.size(); i++)
        {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(int count:freq)
            if(count!=0)
                return false;
        return true;
    }
};
