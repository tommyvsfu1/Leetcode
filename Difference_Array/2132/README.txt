目前先用prefix 2D做法，比較直觀，就是快速求出一個區域的prefix sum

另外這題一個重點是:
對於grid[i][j] == 0的地方，其實有兩種stamp擺法，一種是將grid[i][j]作為左上角端點，另一種是將stamps[x][y]作為右下角端點，所以才會看到這種寫法
    int x = min(m-1, i + stampHeight - 1);
    int y = min(n-1, j + stampWidth - 1);
    if (Stamps.query(i, j, x, y) == 0) return false;
因為邊界情況，其實還是可以擺stamps，只是這時候通常的擺法是把stamp作為右下角，而grid[i][j]就不會剛好是左上角端點，但還是有被覆蓋到
