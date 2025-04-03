#include<bits/stdc++.h>
using namespace std;

void print3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void print4(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
}
void print5(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n-i+1;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
void print6(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
}
void print7(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*i-1;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
void print8(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i-1;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*(n-i)+1;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
void print9(int n){
    print7(n);
    print8(n);
}
void print10(int n){
    for(int i=1;i<=2*n-1;i++)
    {
        int stars =i;
        if(i>n)
        stars=2*n-i;
        for(int j=0;j<stars;j++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
}
void print11(int n){
    int start;
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        start=1;
        else
        start=0;
        for(int j=0;j<i;j++)
        {
            cout<<start;
            start=1-start;
        }
        cout<<endl;
    }
}
void print12(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j;
        }
        for(int j=0;j<2*(n-i);j++)
        {
            cout<<" ";
        }
        for(int j=i;j>0;j--)
        {
            cout<<j;
        }
        cout<<endl;
    }
}
void print13(int n){
    int a=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            a++;
            cout<<a<<" ";
        }
        cout<<endl;
    }
}
void print14(int n){
    for(int i=1;i<=n;i++)
    {
        char ch=65;
        for(int j=0;j<i;j++)
        {
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }
}
void print15(int n){
    for(int i=0;i<n;i++)
    {
        char ch=65;
        for(int j=n;j>i;j--)
        {
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }
}
void print16(int n){
    char ch=65;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<ch;
        }
        ch++;
        cout<<endl;
    }
}
void print17(int n){ 
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<" ";
        }
        for(char ch='A';ch<'A'+i;ch++)
        {
            cout<<ch;
        }
        for(char ch='A'+i-2;ch>='A';ch--)
        {
            cout<<ch;
        }
        cout<<endl;
    }
}
void print18(int n){
    for(int i=0;i<n;i++)
    {
        for(char ch='E'-i;ch<='E';ch++)
        {
            cout<<ch;
        }
        cout<<endl;
    }
}
void print19(int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<2*i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<n-i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<2*(n-i);j++)
        {
            cout<<" ";
        }
        for(int j=0;j<i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
void print20(int n){
    for(int i=1;i<=2*n-1;i++)
    {
        int star=i;
        int space=2*(n-i);
        if(i>5)
        {
            star=2*n-i;
            space=2*(i-n);
        }
        for(int j=0;j<star;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<space;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<star;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
void print21(int n){
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<n;j++)
        {
            if(i==0 || i==n-1 || j==0 || j==n-1)
        cout<<"*";
        else
        cout<<" ";
        }
        cout<<endl;
    }
}
void print22(int n){
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<2*n-1;j++)
        {
            int top=i;
            int bottom=2*n-2-i;
            int left=j;
            int right=2*n-2-j;
            cout<<n-min(min(top,bottom),min(left,right));
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cin>>n;
    print22(n);
}