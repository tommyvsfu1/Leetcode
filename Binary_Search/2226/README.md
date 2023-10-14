會用二分搜索的原因: number of candies跟 k本身的關係是monotonic的
> number of candies 越大，能分配給越少的child
> number of candies 越小，能分配給越多的child
> 所以如果隨便猜一個number of candidies，是可以知道接下來要往上還往下猜