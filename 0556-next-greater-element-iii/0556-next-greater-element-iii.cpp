class Solution {
public:
    int int_to_char(int n,char d[]){
        int i=11;
        while(n!=0){
            int x=n%10;
            n=n/10;
            d[i]='0'+x;
            i--;
        }
        return i;
    }

    int char_to_int(char d[],int max_i){
        long long tmp=0;
        int i=max_i+1;
        while(i<12){
            tmp=tmp*10+d[i]-'0';
            i++;
        }
        if(tmp>INT_MAX)return -1;
        return (int)tmp;
    }

    template <typename T>
    void my_swap(T &a,T &b){
        T c=b;
        b=a;
        a=c;
    }

    void mysort(char d[],int l,int r){
        for(int i=l;i<r;i++){
            for(int j=i+1;j<=r;j++){
                if(d[i]>d[j])my_swap(d[i],d[j]);
            }
        }
    }

    int nextGreaterElement(int n) {
        char d[12];
        int max_i=int_to_char(n,d);
        int b=-1;
        for(int a=10;a>max_i;a--){
            if(d[a]<d[a+1]){
                b=a;
                break;
            }
        }
        if(b==-1)return -1;
        for(int a=11;a>b;a--){
            if(d[a]>d[b]){
                my_swap(d[a],d[b]);
                break;
            }
        }
        mysort(d,b+1,11);
        int re=char_to_int(d,max_i);
        return re;
    }
};