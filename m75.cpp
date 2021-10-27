/*
the method shown below seems not to be what it want =w=
*/
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int c[3] = {0, 0, 0,};
//         for(const auto n : nums)
//             c[n]++;
        
//         int i = 0;
//         while(c[0]) {
//             nums[i] = 0;
//             i++;
//             c[0]--;
//         }
//         while(c[1]) {
//             nums[i] = 1;
//             i++;
//             c[1]--;
//         }

//         while(c[2]) {
//             nums[i] = 2;
//             i++;
//             c[2]--;
//         }

//     }
// };
/*
Runtime: 4 ms, faster than 45.19% of C++ online submissions for Sort Colors.
Memory Usage: 8.3 MB, less than 23.69% of C++ online submissions for Sort Colors.
*/

/*
--------------
r         b
2 0 2 1 1 0
i
--------------
r       b
0 0 2 1 1 2
i
--------------
  r     b
0 0 2 1 1 2
  i
--------------
    r b
0 0 1 1 2 2
    i
--------------
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        // r & b stores the information of what place we can put 0/2 respectively
        int r = 0, b = nums.size() - 1, i = 0;
        while(i < nums.size() && i <= b) {
            switch(nums[i]) {
                case 0:  // red
                    swap(nums[r], nums[i]);
                    r++;
                    i++;
                    break;
                case 1:  // white
                    i++;
                    break;
                case 2:  // blue
                    swap(nums[b], nums[i]);
                    b--;
                    break;
            }
        }
    }    
};

/*
Runtime: 4 ms, faster than 45.19% of C++ online submissions for Sort Colors.
Memory Usage: 8.3 MB, less than 69.85% of C++ online submissions for Sort Colors.
*/