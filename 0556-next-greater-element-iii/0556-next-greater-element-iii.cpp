class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>d;
        int a=n;
        while(a!=0){
            int tmp=a%10;
            a=a/10;
            d.insert(d.begin(),tmp);
        }
        int j=-1;
        for(int i=d.size()-2;i>=0;i--){
            if(d[i]<d[i+1]){
                j=i;
                break;
            }
        }
        if(j==-1)return j;
        for(int i=d.size()-1;i>j;i--){
            if(d[j]<d[i]){
                swap(d[i],d[j]);
                break;
            }
        }
        sort(d.begin()+j+1,d.end());
        string re="";
        for(auto x:d){
            re+=to_string(x); 
        }
        long long r=stoll(re);
        if(r>INT_MAX)return -1;
        return int(r);
    }
};