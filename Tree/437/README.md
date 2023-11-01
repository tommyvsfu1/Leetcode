兩種解法\
1. in-order traversal走訪每個node，然後把每個node當root算num path，用一個全局變數來記錄
2. prefix sum + hash map 的二元樹版本，目前從parent走道目前node的path，要看存在多少的valid path，可以把目前的prefix sum - target，然後看有多少個