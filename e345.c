
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