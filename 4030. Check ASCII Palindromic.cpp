class Solution
{
public:
    bool isPalindromic(string s)
    {
        string binary = "";

        for (char c : s)
        {
            int ascii = (int)c;

            for (int i = 7; i >= 0; i--)
            {
                binary += ((ascii >> i) & 1) + '0';
            }
        }

        int left = 0;
        int right = binary.length() - 1;

        while (left < right)
        {
            if (binary[left] != binary[right])
            {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};