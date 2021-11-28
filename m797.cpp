// 2021.11.28


class Solution {
    vector<bool> visited;
    vector<vector<int>> ans;
    vector<int> path;
public:
    void dfs(int start, int &dst, vector<vector<int>>& graph) {
        if(start == dst) {
            ans.push_back(path);
            return;
        }
        for(int nextNode : graph[start]) {
            if(visited[nextNode])
                continue;
            
            visited[nextNode] = true;
            path.push_back(nextNode);
            
            dfs(nextNode, dst, graph);
            
            visited[nextNode] = false;
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int src = 0, dst = n - 1;
        visited.resize(n);
        for(auto v : visited)
            v = false;
        
        path.push_back(0);
        dfs(src, dst, graph);
        
        return ans;
    }
};

/*
Runtime: 11 ms, faster than 84.21% of C++ online submissions for All Paths From Source to Target.
Memory Usage: 11.8 MB, less than 69.28% of C++ online submissions for All Paths From Source to Target.
*/
