class Solution
{
public:
    int reverseDegree(string s)
    {
        int answer = 0;

        for (int i = 0; i < s.size(); i++)
            answer += (i + 1) * (26 - (s[i] - 'a'));

        return answer;
    }
};