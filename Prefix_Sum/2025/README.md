這題算是比較複雜的prefix sum + hashmap問題，因為需要好幾次Pass，也需要用到suffix，個人認為也算是Three Pass問題\
首先先將問題拆成兩種情況，一種是不需要change element，另一種是要change one element\
先討論change one element情況，很明顯暴力法就是O(n^2)，如果要更快，很明顯看出要用prefix/suffix。如果change i-th element，其實就是算1,2,...,i-1,i+1,...,n-1作為pivot時，sum(arr[0:pivot-1]) = sum(arr[pivot:]) = new sum / 2的數量，因為change i-th element會改變原本算的prefix/suffix資訊，所以我們可以Pass兩次，每次把change i-th element時，考慮原本prefix和suffix符合條件的數量。\
而對於不需要change element的情況單純用prefix sum 和 total sum 就可以解決了\
