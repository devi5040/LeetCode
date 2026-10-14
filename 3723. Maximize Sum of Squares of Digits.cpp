class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>(9*num))
            return "";

        string result = "";

        int nines = sum/9;
        int rem = sum%9;

        result.append(nines, '9');

        if(rem>0)
            result+=to_string(rem);

        result.append(num-result.size(), '0');

        return result;
    }
};
