2874和2873是幾乎一樣的題目，只差在input size，2873就三層for loop就可以了\
這題要能從j的角度來想，就可以發現要想辦法最大化nums[i] 和 nums[k]，所以就是prefix Max和suffix Max\
所以總共Three Pass就可以解出來