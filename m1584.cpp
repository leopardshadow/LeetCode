
// 2022.4.26

/*
用 Prim's algorithm 來找 minimum spanning tree
想法是讓走過的 vertex set 慢慢長大，用 min heap 來找最小的 edge (連接 visited 和 un-visited 的)，逐步擴充 visited set
---
去公司還要練習題目好累，真心 respect 正常上下班 (甚至加班) 每天還可以刷個 20 題的人
*/

typedef tuple<int, int, int> Edge;

class Solution {
    int distance(vector<vector<int>>& points, int a, int b) {
        return abs(points[a][0] - points[b][0]) + abs(points[a][1] - points[b][1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int cost = 0;
        
        set<int> visited;
        visited.insert(0);
        
        // cost, vertex_a, vertex_b
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;  // min heap
        
        for (int i = 1; i < points.size(); i++)
            pq.push({distance(points, 0, i), 0, i});
        
        // find | V - 1 | edges
        int v = 1;
        while(v < points.size() && pq.size()) {
            
            tuple<int, int, int> edge = pq.top();
            pq.pop();
            
            if (visited.count(get<2>(edge)))
                continue;
            else
                v++;
            
            visited.insert(get<2>(edge));
            cost += get<0>(edge);
                        
            for (int i = 1; i < points.size(); i++) {
                if (visited.count(i))
                    continue;
                else
                    pq.push({distance(points, get<2>(edge), i), get<2>(edge), i});  // only push the difference
            }
        }
                    
        return cost;
    }
};
