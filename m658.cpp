
// 2022.9.29

/*
原本想用 binary search 找到最接近 x 的點之後，往左往右 2-pointer 慢慢變大去找
後來偷看 tag 的確可以這樣做，但也有 heap，於是就換了一個寫法寫寫看
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int &a : arr)
            pq.push({abs(x - a), a});
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
/*
Runtime: 194 ms, faster than 16.05% of C++ online submissions for Find K Closest Elements.
Memory Usage: 37.6 MB, less than 7.40% of C++ online submissions for Find K Closest Elements.
*/
