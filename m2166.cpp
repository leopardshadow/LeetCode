class Bitset {
    string bs;
    int c1;
    int flips;
public:
    Bitset(int size) : bs(size, '0') {
        c1 = 0;
        flips = 0;
    }
    
    void fix(int idx) {
        if(flips == 0) {
            if(bs[idx] == '0') {
                    bs[idx] = '1';
                    c1++;
            }
        }
        else
    }
    
    void unfix(int idx) {
        if(bs[idx] == '1') {
            bs[idx] = '0';
            c1--;
        }
    }
    
    void flip() {
        flips = (flips + 1) % 2;
        // c1 = bs.length() - c1;
    }
    
    bool all() {
        if(flips == 0)
            return c1 == bs.length();
        else
            return c1 == 0;
    }
    
    bool one() {
        if(flips == 0)
            return c1 > 0;
        else
            return c1 < bs.length();
    }
    
    int count() {
        if(flips == 0)
            return c1;
        else
            return bs.length() - c1;
    }
    
    string toString() {
        if(flips == 0)
            return bs;
        else {
            flips = 0;
            for(int i = 0; i < bs.length(); i++)
                bs[i] = (bs[i] == '1' ? '0' : '1');
        }
        return bs;
    }
};

