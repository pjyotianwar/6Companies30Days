// Stock Price Fluctuation

class StockPrice {
public:
    map<int, int> mp;
    set<pair<int, int> >s;
    int cur_ts=0;
    int cur_price;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        s.erase({mp[timestamp], timestamp});
        
        mp[timestamp] = price;
        
        s.insert({mp[timestamp], timestamp});
        
        if(timestamp >= cur_ts){
            cur_ts = timestamp;
            cur_price = price;
        }
    }
    
    int current() {
        return cur_price;
    }
    
    int maximum() {
        return (*s.rbegin()).first;
    }
    
    int minimum() {
        return (*s.begin()).first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */