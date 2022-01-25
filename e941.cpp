
// 2022.1.25

/*
這種把陣列走過一次可以知道答案的題目可以想像 FSM 在那邊轉轉轉
---
但我這題是先找到最高點，從最高點的位置往左走、往右走都要是遞減的
這樣的寫法比較簡單，但缺點就是總共走了兩次陣列
*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3)
            return false;
        
        int maxId = 0;
        for(int i = 1; i < arr.size(); i++)
            if(arr[i] > arr[maxId])
                maxId = i;
        
        if(maxId == 0 || maxId == arr.size() - 1)
            return false;
        
        for(int i = 0; i < maxId; i++)
            if(arr[i] >= arr[i+1])
                return false;
        
        for(int i = maxId; i < arr.size() - 1; i++)
            if(arr[i] <= arr[i+1])
                return false;
            
        return true;
    }
};

/*
Runtime: 46 ms, faster than 27.60% of C++ online submissions for Valid Mountain Array.
Memory Usage: 22.3 MB, less than 79.54% of C++ online submissions for Valid Mountain Array.
*/
