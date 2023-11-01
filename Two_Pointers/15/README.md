經典題，直接背起來\
這題算是帶出了Two Pointers的核心觀念(雖然這題用到三個pointer)，pointer設定初始點跟移動方向時，必須要能夠one pass來求出答案。\
這題3Sum，首先sort過之後，把k擺在最後往前移(可以確保k往前走的同時，i, j都能夠在k前面找到，並且不會有遺漏的情況)，而i, j為何要擺左右兩邊，也是因為利用sorting後的特性，讓兩者往中間移動，就能夠確保可以找到所有可能的組合(因為i擺左邊，j擺右邊，代表初始就是最大的組合)