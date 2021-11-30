//***************************************************************************//
// 2021.11.30 before G VO


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
                        // dst costs
        vector<vector<pair<int, int>>> graph(n);
        
        vector<int> costs(n, 1000000);
            
        for(auto flight : flights)
            graph[flight[0]].push_back({flight[1], flight[2]});
        
        queue<int> q;
        
        costs[src] = 0;
        
        // direct flight (non-stop, k = 0)
        for (auto flight : graph[src]) {
            q.push(flight.first);
            costs[flight.first] = flight.second;
        }

        for(int i = 0; i < k; i++) {
            
            if(q.empty())
                break;
        
            vector<int> nextR(costs);

            int qs = q.size();
            while(qs) {
                int from = q.front();
                q.pop();
                                
                for(auto adj : graph[from]) {
                    
                    int to = adj.first;
                    int adjCost = adj.second;
                                        
                    if(costs[from] + adjCost < nextR[to]) {
                        nextR[to] = costs[from] + adjCost;
                        q.push(to);
                    }
                }
                qs--;
            }
            costs = nextR;
        }
        
        if(costs[dst] >= 1000000)
            return -1;
        return costs[dst];
    }
};

/*
Runtime: 20 ms, faster than 94.42% of C++ online submissions for Cheapest Flights Within K Stops.
Memory Usage: 13.7 MB, less than 53.71% of C++ online submissions for Cheapest Flights Within K Stops.
*/
