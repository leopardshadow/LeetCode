// 2021.11.20 Daily
/*
天啊，這類型變形也太多
如果不限制 time complexity，全部直接走過一次，花 O(n) 收工
但是這題要求要 O(log n)，難怪被歸類在 Medium
看到找東西、sorted，又要求 O(log n)，一副就很 binary search 的樣子
有點腦筋急轉彎的感覺，解法滿酷的，因為只有一個出現一次的元素，其他都是出現兩次
陣列又是排序過的，所以切開來一邊是奇數，一邊是偶數，就往奇數那邊找
關鍵是 "sorted"，之前遇到這種沒有這個性質可以用，要好好運用所有可以用的東西
這題要回傳「值」，而不是 index，一開始還弄錯 @@
*/

/*
1. 看了一下討論區，發現很多人在 m = (l + r) / 2; 那邊都會寫成 l + (r - l) / 2，怕它炸掉
2. 我是用新插入東西來處理 corner case，看到也有人是進 binary search 先用 if 檢查，感覺這樣執行時間會快一點點，畢竟他沒進 while 迴圈繞
*/

/*
X X 1 2 3 4 5 X
    l   m 1 r 
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        nums.insert(nums.begin(), -1);
        nums.insert(nums.begin(), -1);
        nums.push_back(10000000);
        nums.push_back(10000000);
        int l = 0, r = nums.size() - 1, m;
        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] == nums[m+1]) {
                if((m - l) % 2 == 0)
                    l = m + 2;
                else
                    r = m - 1;
            }
            else if(nums[m] == nums[m-1]) {
                if((r - m) % 2 == 0)
                    r = m - 2;
                else
                    l = m + 1;
            }
            else
                return nums[m];
        }
        return - 1; // never returns this
    }
};
