// 2021.11.24

/*
這題要注意的是範圍，他的區間都是 closed inteval
所以 [1,1] \cap [1,1] 是 [1,1]，在大於小於判斷要小心
(1), (4) 那邊的大於、小於不能是大於等於、小於等於，因為上面這種情況就會被跳掉
但 (2), (5) 那邊的就沒差了，反正結尾一樣的話，先隨便取一個移動，另一個在下一次迴圈就會進 (1) / (4) 移動
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while(i < firstList.size() && j < secondList.size()) {
            //  111111
            //          222... (1)
            //    222          (2)
            //    22222222     (3)
            if(firstList[i][0] < secondList[j][0]) {
                if(firstList[i][1] < secondList[j][0])  // (1)
                    i++;
                else {
                    if(firstList[i][1] > secondList[j][1]) {  // (2)
                        ans.push_back({secondList[j][0], secondList[j][1]});
                        j++;
                    }
                    else {  // (3)
                        ans.push_back({secondList[j][0], firstList[i][1]});
                        i++;
                    }
                }
            }
            //  2222222
            //            111... (4)
            //    111            (5)
            //    111111111     (6)
            else {   //  secondList[j][0] <= firstList[i][0]
                if(secondList[j][1] < firstList[i][0])  // (4)
                    j++;
                else {
                    if(secondList[j][1] > firstList[i][1]) {  // (5)
                        ans.push_back({firstList[i][0], firstList[i][1]});
                        i++;
                    }
                    else {  // (6)
                        ans.push_back({firstList[i][0], secondList[j][1]});
                        j++;
                    }
                }
            }
        }        
        return ans;
    }
};

/*
Runtime: 54 ms, faster than 15.24% of C++ online submissions for Interval List Intersections.
Memory Usage: 18.7 MB, less than 75.13% of C++ online submissions for Interval List Intersections.
*/
