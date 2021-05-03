# LeetCode


[121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock)

翻到 [ptt C\_and\_CPP](https://www.ptt.cc/man/C_and_CPP/D7F6/M.1309694493.A.E8A.html) 有這題，後來發現 Leetcode 上有類似題目就來做做看。

想法很直觀，只能一天買入一天賣出，要求最大的獲利，如果暴力解就是把所有可能排列出來，找最大的，這樣是 O(n^2)。

換個想法做，如果今天要買，就是挑今天之後股價最高的一天賣掉，明天要買，就是在後天之後股價最高的一天賣掉。所以從尾到頭找出那天之後股價最高的，扣掉當天股價，在這所有裡面找最大的。

比較有趣的遞迴解 TODO





94 -> try not to use recursive
