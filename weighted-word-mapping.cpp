class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string answer = "";
        for (const string &str : words)
        {
            int sum = 0;
            for (char ch : str)
                sum += weights[ch - 'a'];
            int res = sum % 26;
            char temp = 'z' - res;
            answer += temp;
        }
        return answer;
    }
};