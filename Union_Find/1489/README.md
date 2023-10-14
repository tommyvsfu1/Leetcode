minimum spanning tree變形題，一般MST問題就是用kruskal演算法
對於critical edge，就是不考慮它做kruskal，MST > minMST  
對於pseudo critical edge，它一定不是critical edge，同時也能讓MST = minMST。為了強迫要求用某個edge，我們可以強迫把它放在sorted edge的第一個 (然後不用把原本sorted edges裡面相同的那個刪掉，因為有union find會自動幫我們過濾)  