經典題，可以直接背起來\
要找LCA，其實可以先想想CA(common ancestor)怎麼找，其實可以用dfs，遇到p或q就用+1，如果dfs回傳值和目前的node總共的count == 2，則代表找到CA了。而LCA則是第一個滿足的(因為dfs是recursion，第一個滿足的反而是越接近leaf的node)