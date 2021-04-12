
void reverseString(char* s, int sSize){
    for(int i = 0; i < sSize / 2; i++) {
        char c = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = c;
    }
}


/*
Runtime: 52 ms, faster than 28.66% of C online submissions for Reverse String.
Memory Usage: 12.4 MB, less than 63.36% of C online submissions for Reverse String.
*/