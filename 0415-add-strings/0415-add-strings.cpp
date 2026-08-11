class Solution {
public:
    string addStrings(string num1, string num2) {
       int carry=0;
       string s;
       
       int i=num1.size()-1;
       int j=num2.size()-1;
       while(i>=0||j>=0||carry>0){
        int a= i>=0?num1[i]-'0':0;
        int b= j>=0?num2[j]-'0':0;
        int cur=a+b+carry;
        carry=cur/10;
        s=char(cur%10+'0')+s;
        i--;j--;
       }
        return s;
    }
};