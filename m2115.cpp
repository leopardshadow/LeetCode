// Biweekly Contest 68
// Dec 25, 2021

/*
就 ... 題目很長的 topological sort 0w0
(Kahn’s algorithm)
*/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        map<string, pair<int, vector<string>>> nodes;
        set<string> p;
        
        for(int i = 0; i < recipes.size(); i++) {
            for(auto ingre : ingredients[i]) {
                nodes[ingre].second.push_back(recipes[i]);
                nodes[recipes[i]].first++;
            }
        }
        vector<string> ans;

        queue<string> q;
        for(auto sup : supplies) {
            q.push(sup);
        }
        
        while(!q.empty()) {
            
            auto x = q.front();
            q.pop();
            
            for(auto nxt : nodes[x].second) {
                nodes[nxt].first--;
                if(nodes[nxt].first == 0) {
                    q.push(nxt);
                    ans.push_back(nxt);
                }
            }
        }
        
        return ans;
        
    }
};

/*
Runtime: 628 ms, faster than 15.38% of C++ online submissions for Find All Possible Recipes from Given Supplies.
Memory Usage: 158 MB, less than 7.69% of C++ online submissions for Find All Possible Recipes from Given Supplies.
*/
