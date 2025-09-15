兩種想法:

想法一:
house[0] 不搶 : House Robber 1 on rob[1:n-1]
house[n-1]不搶: Hose Robber 1 on rob[0:n-2]
兩者比大小，因為兩個集合無交集，並且聯集為總集合

想法二:
house[0] 搶 : House Robber 1 on rob[2:n-2] + house[0]
house[n-1] 搶: House Robber 1 on rob[1:n-3] + house[n-1]
house[0],house[n-1]都不搶: House Robber 1 on rob[1:n-2]
三個比大小，因為三個集合無交集，並且連集為總集合

