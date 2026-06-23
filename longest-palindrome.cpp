class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);
        int count = 0;
        for(char ch: s)
            freq[ch]++;
        for(int num:freq)
        {
            if(num!=0 && num%2==0)
                count+=num;
            else if(num!=0 && num!=1)
                count+=(num-1);
        }
        if(count!=s.size())
            count++;
        return count;
    }
};
