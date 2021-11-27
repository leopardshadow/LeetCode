/*
priority_queue 沒特別指定的話是 max heap，大的在上面，所以直接 pop k 個出來，收工
這裡直接放 pair，會先用第一個 element 來比較，所以要把次數放前面
後面拿出來時要記得前面已經調換順序了
*/

/*
heap 那邊啊，如果想用 lambda 的可以這樣寫
```
auto comp = [](pair<int, int> a1, pair<int, int> a2){return a1.first < a2.first;}; 
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
```
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = 0;
            else {
                m[nums[i]]++;
            }
        }
        for(auto n : m) {
            pq.push({n.second, n.first});
        }

        int i;
        for(int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
                    
        return ans;
    }
};


/*
Runtime: 16 ms, faster than 74.68% of C++ online submissions for Top K Frequent Elements.
Memory Usage: 13.6 MB, less than 89.75% of C++ online submissions for Top K Frequent Elements.
*/
