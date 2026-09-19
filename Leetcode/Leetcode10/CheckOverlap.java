class Solution {
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if ((xCenter - x1) * (xCenter - x1) + (yCenter - y1) * (yCenter - y1) <= radius * radius
        ||  (xCenter - x1) * (xCenter - x1) + (yCenter - y2) * (yCenter - y2) <= radius * radius
        ||  (xCenter - x2) * (xCenter - x2) + (yCenter - y1) * (yCenter - y1) <= radius * radius
        ||  (xCenter - x2) * (xCenter - x2) + (yCenter - y2) * (yCenter - y2) <= radius * radius) return true;
        if (xCenter >= x1 && xCenter <= x2 && y1 <= yCenter + radius && y2 >= yCenter - radius
        ||  yCenter >= y1 && yCenter <= y2 && x1 <= xCenter + radius && x2 >= xCenter - radius) return true;
        return false;
    }
}