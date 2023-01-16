// Course Schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[2000];
        vector<int> topo;
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        int indegree[2000] = {0};
        for(int i=0;i<numCourses;i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }

        if(numCourses==topo.size()) return true;
        return false;
    }
};