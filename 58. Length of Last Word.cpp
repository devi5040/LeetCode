class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int end = n-1;
        int count = 0;

        while(s[end]==' ')
            end--;

        while(end>=0 && s[end]!=' '){
            count++;
            end--;
        }

        return count;
    }
};


class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        string lastWord;

        while (ss >> word) {
            lastWord = word;
        }

        return lastWord.length();
    }
};
