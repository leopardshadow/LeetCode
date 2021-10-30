class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> m;
        int i;
        for(i = 0; i < arr.size(); i++) {
            if(m.find(arr[i]) == m.end())
                m.insert(arr[i], 0);
            else
                m[ arr[i] ] += 1;
        }
        for(i = 0; i < arr.size(); i++) {
            if(m[ arr[i] ] == 0) {
                k--;
                if(k == 0) break;
            }
        }

        // the order is what I thought in the beginning...
        // for(auto a : m) {
        //     if(a.second == 0) {
        //         k--;
        //         if(k == 0) return a.first;
        //     }
        // }
        
        return "";
    }
};


/*
Runtime: 59 ms, faster than 22.22% of C++ online submissions for Kth Distinct String in an Array.
Memory Usage: 14.7 MB, less than 11.11% of C++ online submissions for Kth Distinct String in an Array.
*/


/*
First time attending Leetcode contest,
get 0 points...
2021.10.30
*/










// QQ
// class Solution {
// public:
//     string kthDistinct(vector<string>& arr, int k) {
//         unordered_map<string, int> m;
//         int i = 0;
//         while(i < arr.size()) {
//             // cannot find -> add
//             if(m.find(arr[i]) == m.end()) {
//                 m[ arr[i] ] = i;
//                 i++;
//             }            
//             // remove
//             else {
//                 string temp = arr[i];
//                 arr.erase(arr.begin() + i);
                
//                 if(m[temp] >= 0) {
//                     for(int s = 0; s <= i; s++) {
//                         if(arr[s] == temp) {
//                             arr.erase(arr.begin() + s);
//                             break;
//                         }
//                     }
//                     m[arr[i]] = -1;
//                     i--;
//                 }
//             }
//         }
//         if(k - 1 > arr.size()) {
//             return "";
//         }
//         else
//             return arr[k-1];
//     }
// };
