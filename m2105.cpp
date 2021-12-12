// Weekly Contest 271


/*
嗚嗚嗚，居然在 contest 時間內沒寫出來這一題，一個半小時中的前半小時完成 1e1m，後面都卡在這題 ...
---
我對題目的理解有點錯誤，他這裡的澆法是一但發現水不夠就會立馬回去補水

舉例來說，capacity 是 10，現在水壺剩 3，這株植物需要 6，他就會提著那壺 3 去加滿水再來澆 6，最後剩 4
而我一開始的寫法是他會把水壺裡剩下的 3 先倒下去再去補水，所以需要的次數會少很多

好笨的方法，提著水多做好多白工 @@

這也是為什麼題目有限制 max(plants[i]) <= capacityA, capacityB <= 10E9
因為按照他的澆法，補滿水之後一定要能澆，沒有那種來回跑 3 次才澆足夠水的情形

在 contest 時我卡這個測資
[726,739,934,116,643,648,473,984,482,85,850,806,146,764,156,66,186,339,985,237,662,552,800,78,617,933,481,652,796,594,151,82,183,241,525,221,951,732,799,483,368,354,776,175,974,187,913,842]
1439
1207
我還用 python 計算了一下 sum，發現就算是整條除上比較小的 1207 也不到答案的 24，他究竟是怎麼澆的 ...

用他那種澆法的話就不能單純加起來用除的
*/

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        
        int n = plants.size();
        
        int refills = 0;
        int l = 0, r = n - 1;
        int curA = capacityA, curB = capacityB;
        while(l < r) {
                
            curA -= plants[l];
            if(curA < 0) {
                curA = capacityA - plants[l];
                refills++;
            }
            curB -= plants[r];
            if(curB < 0) {
                curB = capacityB - plants[r];
                refills++;
            }            
            l++;
            r--;
        }
        if(l == r) {
            
            if(curA >= curB) {
                curA -= plants[l];
                if(curA < 0) {
                    curA += capacityA;
                    refills++;
                }
            }
            else {
                curB -= plants[r];
                if(curB < 0) {
                    curB += capacityB;
                    refills++;
                }            
            }
        }
        return refills;
    }
};

/*
Runtime: 168 ms, faster than 35.71% of C++ online submissions for Watering Plants II.
Memory Usage: 78.2 MB, less than 50.00% of C++ online submissions for Watering Plants II.
*/


// class Solution {
// public:
//     int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        
//         int refillA = 0, refillB = 0;
//         int n = plants.size();
  
//         int p1 = 0, p2 = 0;
//         for(int i = 0; i < n / 2; i++) {
//             p1 += plants[i];
//             p2 += plants[n - 1 - i];
//         }
        
//         // round up
//         refillA = refillA + (int)(1.0 * p1 / capacityA + 0.999);
//         refillB = refillB + (int)(1.0 * p2 / capacityB + 0.999);
                
//         // how many water left
//         p1 = capacityA * refillA - p1;
//         p2 = capacityB * refillB - p2;
        
//         // the middle point
//         if(n % 2 == 1) {
            
//             int p = plants[n / 2];
            
//             if(p1 >= p2) {
//                 if(p1 >= p) {
                    
//                 }                
//                 else {
//                     p -= p1;
//                     refillA = refillA + (int)(1.0 * p / capacityA + 0.999);
//                 }
//             }
//             else {
//                 if(p2 >= p) {
                    
//                 }
//                 else {
//                     p -= p2;
//                     refillB = refillB + (int)(1.0 * p / capacityB + 0.999);
//                 }
//             }
            
//         }
//         // -2 for the initial water they have
//         return max(0, refillA - 1) + max(0, refillB - 1);
//     }
// };
