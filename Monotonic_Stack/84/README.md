經典題目，比較好想的方法是Three Pass，把目前index的height當作最高點，然後找next smaller和prev smaller，來算最大的面積  

但其實因為對於next smaller 的monotonic stack來說，stack top()的previous smaller就是top()後面一個元素，所以根本不用用到prev smaller，所以只需要one pass
>然後為了要讓算next smaller 和 previous smaller時都有值，所以前後要insert一個很小很小的值