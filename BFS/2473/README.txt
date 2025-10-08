Dijkstra問題
重點:
1. 如果要各自node跑一次Dijkstra，在計算Dijkstra時候，不能考慮appleCost (因為appleCost是一次性的花費，如果把appleCost引入Dijkstra，就代表每個node都要買蘋果)
2. 如果想像有個super source連接到所有city，這時候就可以PQ先把所有node加入(weight就是appleCost)，接著跑一次Dijkstra，最後確認最小值，就能得到答案
-> 因為這時候就變成src (super source) -> All cities問題，變成經典Djikstra型式(single source shortest path)
