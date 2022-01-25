
// 2022.1.25

/*
我這題是先找到最高點，從最高點的位置往左走、往右走都要是遞減的
這樣的寫法比較簡單，但缺點就是總共走了兩次陣列
---
下面也試了只有一次陣列，前後比較大小的版本!
---
lee215 的解法好酷，他讓兩個人 i, j 分別從兩端開始往上爬，如果是合法的山他們會在最高點相遇 (+ 檢查 i, j 都有移動)
*/

// 先找到最高點
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


// 只有一次陣列，都是前後比較
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() <= 1)  // == 2 is handled below
            return false;
        
        int i = 1;
        while(i < arr.size() && arr[i-1] < arr[i])
            i++;
        
        if(i == 1 || i == arr.size())
            return false;
        
        while(i < arr.size() && arr[i-1] > arr[i])
            i++;
        
        return i == arr.size();
    }
};

/*
Runtime: 77 ms, faster than 5.17% of C++ online submissions for Valid Mountain Array.
Memory Usage: 22.5 MB, less than 48.39% of C++ online submissions for Valid Mountain Array.
*/

