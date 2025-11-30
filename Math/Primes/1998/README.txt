由於2 <= nums[i] <= 10^5
對於此區間質數，只要該質數是nums[i]的factor，就進行union find
對於不同nums[i]，跟質數factor做union find

nums = [7,21,3]
2: []
3: [3, 21] 
5: []
7: [7, 21]
...

接著在Union Find過程中[3, 7, 21]會被歸類在同個union中，這個概念代表這些數都可以透過
一次或多次swap operation(3跟7要交換，需透過21)


最後，把sort(nums[i]) 跟 nums[i]進行比較，如果nums[i]跟sort(nums[i])不同，就確認是否在同個union，如果在同個union代表可以swap