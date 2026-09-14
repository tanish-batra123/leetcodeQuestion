class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int r1TopX = rec1[2];
        int r1TopY = rec1[3];
        int r1BottomX = rec1[0];
        int r1BottomY = rec1[1];

        int r2BottomX = rec2[0];
        int r2BottomY = rec2[1];
        int r2TopX = rec2[2];
        int r2TopY = rec2[3];

        if (r1TopX > r2BottomX && r1TopY > r2BottomY &&
            r2TopX > r1BottomX && r2TopY > r1BottomY)
            return true;

        return false;
    }
};