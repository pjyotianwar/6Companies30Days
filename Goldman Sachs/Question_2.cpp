// Valid Square

class Solution {
public:
    bool validIsoscelesRightTriangle(vector<int>& p1, vector<int>& p2, vector<int>& p3){
        int a = (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
        int b = (p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1]);
        int c = (p2[0]-p3[0])*(p2[0]-p3[0]) + (p2[1]-p3[1])*(p2[1]-p3[1]);
        return (a > b && a > c && b+c==a && b==c) 
        || (b > c && b > a && a+c==b && a==c) 
        || (c > a && c > b && a+b==c && a==b);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return validIsoscelesRightTriangle(p1, p2, p3) 
        && validIsoscelesRightTriangle(p1, p2, p4) 
        && validIsoscelesRightTriangle(p2, p3, p4);
    }
};