class StockSpanner {
    vector<int> arr;
    stack<int> st;
    int i;
public:
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        int res = 0;

        arr.push_back(price);
        if (st.empty() || arr[st.top()] > price) {
            st.push(i);
            res = 1;
        }
        else {
            while(!st.empty() && arr[st.top()] <= price)
                st.pop();
            if(!st.empty()) {
                res = i - st.top();
            }
            else {
                res = i+1;
            }
            st.push(i);
        }
        i++;
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */