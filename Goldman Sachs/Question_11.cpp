// Invalid Transactions

class Solution {
public:
    struct Node{
        string n, c;           //name, city
        int a, t, idx;         //amount, time, index in original vector
        Node(string& _n,string& _c,int _a,int _t, int _idx):n(_n), c(_c), a(_a), t(_t), idx(_idx){}
    };
    
    vector<string> invalidTransactions(vector<string>& tx) {
        vector<bool> iv(tx.size(), false); //mark all transactions as invalid.
        vector<string> res;
        vector<Node> tn;
        string n,c;
        int a, t;
        for(int i = 0; i < tx.size(); i++){
            parseT(tx[i], n,c,t,a);
            tn.push_back(Node(n,c,a,t, i));
        }
        //"{name},{time},{amount},{city}"
        for(int i = 0; i < tx.size(); i++){
            if(tn[i].a > 1000){
                iv[i] = true;
                continue;
            }
            //Use brute force to update the invalid flag vector iv(isInvalid)
            for(int j = 0; j < tx.size(); j++){
                if(i == j) continue;
                if(tn[i].n == tn[j].n){
                    //Is same name, check other conditions
                    if(tn[i].c != tn[j].c && abs(tn[i].t-tn[j].t) <= 60){
                        iv[i] = true;
                        break;  //MArk invalid and break
                    }
                }
            }
        }
        
        for(int i = 0; i < tx.size(); i++){
            if(iv[i]){
                res.push_back(tx[tn[i].idx]);
            }
        }
        return res;
    }
    
    /* A parser for breaking transaction strings into parameters.*/
    void parseT(string&s, string &n, string &c, int &time, int &amount){
        int idx = 0;
        string temp;
        s.push_back(',');
        for(int i = 0; i < s.size(); i++){
            temp.push_back(s[i]);
            if(s[i] == ','){
                temp.pop_back();
                if(idx == 0){
                    n = temp;
                }else if(idx == 1){
                    time  = stoi(temp);
                }else if(idx == 2){
                    amount = stoi(temp);
                }else if(idx == 3){
                    c = temp;
                }
                temp="";
                idx++;
            }
        }
        s.pop_back();
    }
};