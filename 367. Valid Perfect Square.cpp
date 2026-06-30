class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num, mid;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            long long square = (long long)mid*mid;
            if(square==num)
                return true;
            if(square>num)
                right = mid-1;
            else
                left = mid+1;
        }
        return false;
    }
};
