很容易想到用three pass (prefix/suffix)，但要想到怎麼算leftMoves和rightMoves需要蠻好的DP概念
簡單來說 leftMoves[i] = leftMoves[i-1] + left[i-1]，也就是說先把balls放到i-1的box需要的動作，加上從i-1 box移到i box所需要的動作\
同理，rightMoves的算法也很像