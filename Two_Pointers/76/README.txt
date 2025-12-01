概念不難，就是找到最短的合法的window，只是實作上有edge case會導致不好寫\
首先就是一般sliding window我會這樣寫
```
int j = 0;
for (int i = 0; i < n; i++) {
    while(j < n && ...) {
        ...
    }
}
```
然後要決定是在括號裡面更新result還是外面，以這題來說因為有可能j==n-1做完才會是合法的，所以要把更新放在外面\
再來，如果while只寫成while(j < n)，然後把break判斷式寫在裡面，一定要確保不會對同個j更新複數次，所以這題我是把break條件寫在最前面


2025/12/2
v2版本也是sliding window，但用比較好懂，也比較模板方式來寫 (缺點是比較慢，但還是可以PASS)