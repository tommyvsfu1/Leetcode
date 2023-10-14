prefix[i:j] = prefix[j] - prefix[i-1] = goal\
prefix[i-1] = prefix[j] - goal\
所以，我們只要one pass，每次看有多少個prefix[i-1] == prefix[j] - goal 