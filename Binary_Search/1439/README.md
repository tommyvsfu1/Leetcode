一樣是binary search猜答案    
然後驗證答案時，不需要枚舉所有情況(因為每個row都是sorted)，可以先從最小的開始(每個row都選第一個)，接著從最後一個row開始選第二, 三...試試看，接著換倒數第二個row，以此類推。而以上的思路就會構成DFS的概念  