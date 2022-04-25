
// 2022.4.25

/*
還滿有趣的題目，沒看 Hint 自己寫的
---
除了原本的 next 和 hasNext 之外，要實作一個 peek，回傳當前 iterator 指向的值，但不能往後移動 iterator
---
我的想法是用一個額外的空間去記錄偷看的值 (peekedElement) (這裡我是用 list<int>，但其實 int 就好)
peek 很多次的話，只有第一次會讓 iterator 移動，後面都會直接從 peekedElement 拿
當 peekedElement 有東西又呼叫 next 時，因為此時 iteratir 已經在下一個，所以會回傳 peekedElement 並清掉，再下一次呼叫 next 時才會真的移動 (呼叫 Iterator 的 next)
---
這題還牽扯到繼承時要用 base class 的 method 該如何寫
*/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    list<int> temps;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (temps.empty())
            temps.push_back(next());
        return temps.front();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (!temps.empty()) {
            int ret = temps.front();
            temps.pop_front();
            return ret;
        }
            
        else
            return ((Iterator*)this)->next();
	}
	
	bool hasNext() const {
	    if (!temps.empty())
            return true;
        return ((Iterator*)this)->hasNext();
	}
};
/*
Runtime: 3 ms, faster than 79.17% of C++ online submissions for Peeking Iterator.
Memory Usage: 7.4 MB, less than 88.55% of C++ online submissions for Peeking Iterator.
*/
