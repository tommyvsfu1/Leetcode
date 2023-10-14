class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        int zeros = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '0')
                zeros +=1;
            else
                ones += 1;
        }
        
        string res;
        res += "1";
        ones--;
        
        while(zeros--)
            res = "0" + res;
        while(ones--)
            res = "1" + res;
        return res;
    }
};