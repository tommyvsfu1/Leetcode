這題要先像到，如果不用刪除元素，我們其實就是找\
lefteven + righteven == leftodd + rightodd\
不過因為刪除i-th元素後，包含i-th元素之後的元素的index奇偶性會對調，所以變成\
lefteven[i-1] + rightodd[i+1] == leftodd[i-1] + righteven[i+1]