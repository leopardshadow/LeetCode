
// 2022.2.6

/*
像這樣的題目其實可以不必執著走過一次陣列就把答案算出來，如果走兩次：第一次先決定 k，第二次才去移動陣列
上面是我一開始的想法，但其實這題不用這樣，畢竟只有減，沒有變長，不用那麼麻煩
---
我的做法是用兩個 pointer，分別指向讀、寫的位置
讀的迴圈會一直一格一個順序往前讀，並判斷當前重複數字的數量
寫的迴圈會則在有寫東西後往後移動一格
讀的 pointer 永遠在寫的 pointer 前面 (或重疊)
這兩個 pointer 可以把陣列分出三個部分
0 1 2 ............ n-1
==1== w ==2== r ==3==
1: 已經確定沒有重複兩個以上的陣列
2: 不重要的東西 (超過三個的數)，之後寫會重新給值 or 陣列長度根本不到那
3: 尚未處理的部份
如果 r/w pointer 重疊 => 沒有 (2) => 到目前為止沒有遇到重複三個以上的
最後全部跑完，看 write pointer 最後寫到哪裡就可以知道答案陣列 (就是 (1)) 的長度
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int w = 1, prev = nums[0], cnt = 1;
        for(int r = 1; r < nums.size(); r++) {
            if(prev == nums[r]) {
                cnt++;
            }
            else {
                cnt = 1;
                prev = nums[r];
            }
            if(cnt <= 2) {
                swap(nums[r], nums[w]);
                w++;
            }

        }

        return w;
    }
};
