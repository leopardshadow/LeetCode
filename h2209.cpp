
// Biweekly Contest 74 (2022.3.19)

/*
先記錄一下想法，之後再來寫

我的想法是 Carpets 的頭或尾一定會在**黑白的邊緣** (剛好頂在白色，再過去就是黑色了)，如果不是的話，可以移動到符合這項性質，且不影響這塊 Carpets 蓋住的白色區塊

因為限制在黑白邊緣，所以可以放的位置就是限制那幾個，可以計算出優先放哪 (greedy)

當放置 Carpets 後，黑白邊緣會移動，這時候再重複上述步驟

但這我在 contest 中實作不出來，目前也不知道對不對 QQ
*/
