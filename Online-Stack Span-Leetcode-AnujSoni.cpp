class StockSpanner {
public:
    stack<int> s;
    int i;
    vector<int> res;
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        int ans;
        res.push_back(price);
        while(!s.empty() && res[i] >= res[s.top()])
            s.pop();
        if(s.empty())
            ans = i+1;
        if(!s.empty())
            ans = i-s.top();
        s.push(i++);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
