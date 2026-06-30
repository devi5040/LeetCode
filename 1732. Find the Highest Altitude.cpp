// Find the highest altitude
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        vector<int> altitudes;
        altitudes.push_back(sum);
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            altitudes.push_back(sum);
        }
        return *max_element(altitudes.begin(), altitudes.end());
    }
};