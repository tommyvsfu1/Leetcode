path sum本身可以拆解成 拐點, 左邊path和右邊path，這樣我們就可以對每個node算一個max path sum，取最大的即可\
而如何算path sum，其實就dfs就可以了，注意跟543題很像，可以在算LongestPathToLeaf的時候，就同時把path sum算好，可以這樣做的原因是剛好在算LongestPathToLeaf，就有left path , right path的值了