// Corporate fligh bookings
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n,0);
        vector<int> diff(n,0);
        int sum=0;
        for(int i=0; i<bookings.size();i++)
        {
            diff[bookings[i][0]-1] += bookings[i][2];
            if(bookings[i][1]<n)
                diff[bookings[i][1]]-=bookings[i][2];
        }
        for(int i=0;i<n;i++){
            sum+= diff[i];
            answer[i] = sum;
        }
        return answer;
    }
};