
# Weekly Contest 295

"""
偷懶用 python 處理字串，用 C++ 寫好麻煩 ><
主要在 float(x) 抓 exception
---
用了比較 FP 的寫法～
"""

class Solution:
    def tr(self, x: str, discount: int):
        if (x[0] == '$'):
            try:
                float(x[1:])
                return x[0] + "{0:.2f}".format(float(x[1:]) * (100 - discount) / 100.)
            except ValueError:
                return x
        else:
            return x
        
    def discountPrices(self, sentence: str, discount: int) -> str:
        xs = sentence.split(" ")
        xs = [self.tr(x, discount) for x in xs]
        return ' '.join(xs)


"""
Runtime: 125 ms, faster than 66.67% of Python3 online submissions for Apply Discount to Prices.
Memory Usage: 16.5 MB, less than 66.67% of Python3 online submissions for Apply Discount to Prices.
"""
