class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
        int xn=max(x1,min(xc,x2));
        int yn=max(y1,min(yc,y2));

        int dx=xc-xn;
        int dy=yc-yn;
        int add=dx*dx+dy*dy;
        int d=sqrt(add);
        if(d<=radius)return true;
        return false;
    }
};