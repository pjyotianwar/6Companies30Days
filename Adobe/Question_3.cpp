// K-th Smallest in Lexicographical Order

class Solution {
public:
int findKthNumber(int n,int k)
{
    if(n<10)return k;
    return stol(find_next(n,k-1,9));
}
string find_next(int n, int k,int b) {
    int next=n;
    long base=1;
    
    while(n/b>=base)
        base=base*10+1;
    
    base/=10;
    n-=base*b;
    vector<int> level;
    level.push_back(0);
    
    for(int i=0;i<b;i++)
        level.push_back(base);
    
    long new_base=base*9+1;
    int i=1;
    while(n>new_base)
    {
        level[i++]+=new_base;
        n-=new_base;
    }
    level[i]+=n;
    
    for(i=1;i<=b;i++)
        level[i]+=level[i-1];
    
    int result=0;
    i=0;
    while(level[i]<k)
        i++;

    if(level[i]==k)
        return to_string(i+10-b);
    if(i>0)k-=level[i-1]+1;
    
    return to_string(i+9-b)+find_next(i>0?level[i]-level[i-1]-1:level[i],k,10);
    
}
};