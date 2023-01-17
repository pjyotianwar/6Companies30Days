// Number of Boomerangs

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int booms = 0;
        unordered_map<int, int> ctr(points.size());
        for (auto &p : points) {
            ctr.clear();
            for (auto &q : points)
                booms += 2 * ctr[(p[0] - q[0])*(p[0] - q[0]) + (p[1] - q[1])*(p[1] - q[1])]++;
        }
        return booms;
    }
};