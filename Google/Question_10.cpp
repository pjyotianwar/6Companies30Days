// Network Delay Time


class Solution {
public:
    class Node{
    public:
        int ID;
        int weight;
        Node(int ID, int weight): ID(ID), weight(weight) {}
    };
    struct CompareNode {
        bool operator()(const Node &lhs, const Node &rhs) const {
            return lhs.weight > rhs.weight;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> g(N + 1, vector<pair<int, int>>());
        priority_queue<Node, vector<Node>, CompareNode> pq;
        for (auto &v : times) {
            g[v[0]].push_back(make_pair(v[1], v[2]));
        }
        pq.push(Node(K, 0));
        vector<int> weights(N+1, INT_MAX);
        weights[K] = 0;
        while(!pq.empty()) {
            Node t = pq.top();
            pq.pop();
            for(auto &p : g[t.ID]) {
                int new_weight =  t.weight + p.second;
                if (weights[p.first] > new_weight) {
                    weights[p.first] = new_weight;
                    pq.push(Node(p.first, new_weight));
                }
            }
        }
        int res = 0;
        for (int i = 1; i < N+1; ++i) {
            if (weights[i] == INT_MAX) return -1;
            res = max(res, weights[i]);
        }
        return res;
    }
};