#include<iostream>
#include<string.h>
using namespace std;


void reverse_str(char s[]){
    for(int i=0; i<strlen(s)/2; i++){
        int len=strlen(s);
        char temp=s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=temp;
    }
}

void Multiply(char s1[], char s2[], int n2){
    char ans[n2][100] = {""};
    int m=0;
    for(int j=strlen(s2)-1; j>=0; j--){
            int rem=0,l=0;
            char pro[99]="";
            int flg=0;
        for(int i=strlen(s1)-1;i>=0;i--){
            for(int k=strlen(s2)-1-j;k>0 && flg==0;k--){
                pro[l++] = '0';
            }
            flg=1;
            int mult = (int(s2[j])-48) * (int(s1[i])-48) + rem;
            pro[l++] = char((mult%10)+48);
            rem=mult/10;
        }
        pro[l] = char(rem+48);
        reverse_str(pro);
        strcpy(ans[m++],pro);
    }
    int i,j,rem=0,p=0;
    char sum[100]="";
    int k=99;
    for(int j=0;j<m;j++)
        reverse_str(ans[j]);
    for(int i=0;i<strlen(ans[m-1]);i++){
        int add=0;
        for(int j=0;j<m;j++){
            if(i>=strlen(ans[j]))
                continue;
            add+=int(ans[j][i])-48;
        }
        add+=rem;
        sum[p++]=char((add%10)+48);
        rem=add/10;
    }
    reverse_str(sum);
    cout << "\nProduct: ";
    for(int i=0;i<p; i++)
        cout << sum[i];
}


int main(){
    char s1[51], s2[51];
    int n1, n2;
    cout << "Enter the number of digits (max: 30): ";
    cin >> n1 >>  n2;
    cout << "Enter Two digits: ";
    cin >> s1 >> s2;
    Multiply(s1, s2, n2);
    return 0;
}
