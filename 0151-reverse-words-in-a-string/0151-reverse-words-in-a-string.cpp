class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        int write=0,read=0;
        while(read!=n){
            if(s[read]==' '){
                read++;
                continue;
            }
            int start=read;
            while(s[read]!=' '&&read<n){
                read++;
            }
            int end=read-1;
            if(write!=0){
                s[write++]=' ';
            }
            for(int i=start;i!=end+1;i++){
                s[write++]=s[i];
            }
        }
        
        s.resize(write);
        int start=0;
        for(int i=0;i<=write;i++){
            if(s[i]==' '||i==write){
                reverse(s.begin()+start,s.begin()+i);
                start=i+1;
            }
        }
        return s;
    }
};