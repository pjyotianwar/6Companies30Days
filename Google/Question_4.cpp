// Fruit Into Baskets


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0, n=fruits.size(), st=0, i=0;

        if(n<=2)
        return n;

        vector<vector<int>> v;

        for( ; i<n; i++){
            switch(v.size()){
                case 0:
                    st=i;
                    v.push_back({fruits[i], i, i});
                    break;
                case 1:
                    if(v[0][0]!=fruits[i])
                    v.push_back({fruits[i], i, i});
                    else
                    v[0][2] = i;
                    break;
                default:
                    if(v[0][0]==fruits[i])
                    v[0][2]=i;
                    else if(v[1][0]==fruits[i])
                    v[1][2]=i;
                    else if(v[0][2]<v[1][2]){
                        ans = max(ans, i-st);
                        st = v[1][2] = max(v[0][2]+1, v[1][1]);
                        v[0] = {fruits[i], i, i};
                    }
                    else{
                        ans = max(ans, i-st);
                        st = v[0][2] = max(v[1][2]+1, v[0][1]);
                        v[1] = {fruits[i], i, i};
                    }
            }
        }
        ans = max(ans, i-st);
        return ans;
    }
};