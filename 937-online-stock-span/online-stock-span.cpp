class StockSpanner {
public:
    stack<pair<int,int>> st;
    int count;
    StockSpanner() {
        count = 0;
    }
    
    int next(int price) {
        count++;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int prev = st.empty() ? 0 : st.top().second;
        if (count == 1) {
            st.push(make_pair(price, count));
            return 1;
        }
        else {
            st.push(make_pair(price, count));
            return count - prev;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */