// Perfect Rectangle

class Solution {
void  CheckCorner(unordered_map<string, int> &ss, int x, int y, int pos)
{
	static vector<string> ssPos{ "BR", "BL", "TL", "TR" };
	string sx = to_string(x);
	string sy = to_string(y);
	if (ss.find(sx + ssPos[(pos+1)%4] + sy) != ss.end())
		ss.erase(sx + ssPos[(pos + 1) % 4] + sy);
	else if (ss.find(sx + ssPos[(pos +3) % 4] + sy) != ss.end())
		ss.erase(sx + ssPos[(pos +3) % 4] + sy);
	else
		ss[sx + ssPos[pos] + sy]++;
}

public:
bool isRectangleCover(vector<vector<int>>& rectangles) {
	unordered_map<string,int> ss;
	for (int i = 0; i < rectangles.size(); i++)
	{
		//BL
		CheckCorner(ss, rectangles[i][0], rectangles[i][1], 1);
		//BR
		CheckCorner(ss, rectangles[i][2], rectangles[i][1], 0);
		//TL
		CheckCorner(ss, rectangles[i][0], rectangles[i][3], 2);
		//TR
		CheckCorner(ss, rectangles[i][2], rectangles[i][3], 3);
	}

	if (ss.size() != 4)
		return false;
	for (auto x : ss)
	{
		if (x.second != 1)
			return false;
	}
	return true;
}
};