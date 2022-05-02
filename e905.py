
# 2022.5.2

"""
用 FP 一點的寫法
---
不知道 Leetcode 什麼時候才會有 Haskell 可以玩
"""

class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        return [n for n in nums if n % 2 == 0] + [n for n in nums if n % 2 == 1]

"""
Runtime: 86 ms, faster than 75.53% of Python3 online submissions for Sort Array By Parity.
Memory Usage: 14.7 MB, less than 17.91% of Python3 online submissions for Sort Array By Parity.
"""
