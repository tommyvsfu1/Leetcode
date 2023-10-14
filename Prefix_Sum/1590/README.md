我認為divisible 的題目，基本上就是把modulo的運算子想辦法分解，應該就知道怎麼用prefix sum + hash map來解了，目前感覺是對modulo運算的特性沒有很熟
```
Idea: we need to find arr[j:i] s.t (sum(arr) - sum(arr[j:i])) % P == 0
Goal: Find arr[j:i] s.t sum(arr[j:i]) % P == sum(arr) % P == target
So We need to find a smallest subarray arr[j:i] with presum[j:i] % P = target
(presum[i] - presum[j-1]) % P = target
presum[i] % P - presum[j-1] % P = target % P
presum[i] % P - target % P = presum[j-1] % P
(presum[i] - target) % P = presum[j-1] % P
```