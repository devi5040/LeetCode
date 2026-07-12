class Solution
{
public:
    int secondsBetweenTimes(string startTime, string endTime)
    {
        int timeElapsed = 0;
        int seconds = stoi(endTime.substr(6, 2)) - stoi(startTime.substr(6, 2));
        int minutes = stoi(endTime.substr(3, 2)) - stoi(startTime.substr(3, 2));
        int hours = stoi(endTime.substr(0, 2)) - stoi(startTime.substr(0, 2));
        timeElapsed += (hours * 3600);
        timeElapsed += (minutes * 60);
        timeElapsed += seconds;
        return timeElapsed;
    }
};