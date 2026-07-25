class Solution
{
public:
    int maxProduct(int n)
    {
        int product = 0, maxNum = 0;
        while (n > 0)
        {
            int rem = n % 10;
            product = max(product, rem * maxNum);
            maxNum = max(maxNum, rem);
            n /= 10;
        }

        return product;
    }
};

// convert to string solution
class Solution
{
public:
    int maxProduct(int n)
    {
        string num = to_string(n);
        sort(num.rbegin(), num.rend());
        return (num[0] - '0') * (num[1] - '0');
    }
};