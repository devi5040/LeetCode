class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int dist = sqrt(pow((closestX - xCenter), 2) + pow((closestY - yCenter), 2));
        return dist <= radius;
    }
};