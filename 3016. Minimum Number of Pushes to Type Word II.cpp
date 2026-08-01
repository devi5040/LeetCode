class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);

        for(char ch:word)
            freq[ch-'a']++;

        sort(freq.rbegin(), freq.rend());

        int level = 1, current = 0, totalPush = 0;
        for(int i=0; i<26; i++){
            current++;
            totalPush += (freq[i]*level);
            if(current==8){
                level++;
                current = 0;
            }
            if(freq[i]==0)
                break;
        }

        return totalPush;
    }
};
