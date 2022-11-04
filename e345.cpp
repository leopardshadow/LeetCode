
#include <stdbool.h>

char * reverseVowels(char * s){
    int i = 0,
        j = strlen(s);
    char c;

    while( i < j ) {
        bool i_v = s[i] == 'a' || s[i] == 'e'  || s[i] == 'i' ||
                                  s[i] == 'o'  || s[i] == 'u' ||
                   s[i] == 'A' || s[i] == 'E'  || s[i] == 'I' ||
                                  s[i] == 'O'  || s[i] == 'U';
        bool j_v = s[j] == 'a' || s[j] == 'e'  || s[j] == 'i' ||
                                  s[j] == 'o'  || s[j] == 'u' ||
                   s[j] == 'A' || s[j] == 'E'  || s[j] == 'I' ||
                                  s[j] == 'O'  || s[j] == 'U';
               
        if (i_v && j_v) {
            c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
            continue;
        }
        if(!i_v) i++;
        if(!j_v) j--;
    }
    return s;
}

/*
Runtime: 4 ms, faster than 68.06% of C online submissions for Reverse Vowels of a String.
Memory Usage: 6.8 MB, less than 41.67% of C online submissions for Reverse Vowels of a String.
*/




// 2022.11.4

/*
原來我之前寫過這題，完全沒印象
*/

class Solution {
    bool isVowel(char c) {
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
        return c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u';
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!isVowel(s[i]))
                i++;
            if (!isVowel(s[j]))
                j--;
            if (isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
/*
Runtime: 20 ms, faster than 32.93% of C++ online submissions for Reverse Vowels of a String.
Memory Usage: 7.7 MB, less than 61.66% of C++ online submissions for Reverse Vowels of a String.
*/
