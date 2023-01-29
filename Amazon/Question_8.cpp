// Destroying Asteroids

class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& ast) {
        
        long long int planetMass = m;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto n : ast)
            pq.push(n);
        
        while(pq.size())
        {
            if(pq.top() <= planetMass)
            {
                planetMass+=pq.top();
                pq.pop();
            }
            else
            {
                break;
            }
        }
           
        return pq.empty();
    }
    
};