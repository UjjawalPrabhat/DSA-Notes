#include <bits/stdc++.h>
using namespace std;

int cnt = 1;
void print()
{
    if (cnt == 3)
        return;
    cout << cnt << "\n";
    cnt++;
    print();
}

void printName(int i, int n)
{
    // Time Complexity=O(n)
    // Space Complexity or Stack Space=O(n)
    if (i > n)
        return;
    cout << "Ujjawal" << "\n";
    printName(i + 1, n);
}

void print1ToN(int i, int n)
{
    if (i > n)
        return;
    cout << i << "\n";
    print1ToN(i + 1, n);
}

void printNTo1(int i, int n)
{
    if (i == 0)
        return;
    cout << i << "\n";
    printNTo1(i - 1, n);
}

// using backtracking
void printNTo1usingB(int i, int n)
{
    if (i > n)
        return;
    printNTo1usingB(i + 1, n);
    cout << i << "\n";
}

// using paramterised way
void sumOfNterms(int i, int sum)
{
    if(i<1)
    {
        cout<<sum<<"\n";
        return;
    }
    sumOfNterms(i-1,sum+i);
}

// using functional way
int sumOfNtermsUsingf(int n)
{
    if(n==0) return 0;
    return n+sumOfNtermsUsingf(n-1);
}
int fact(int n)
{
    if(n==1) return 1;
    return n*fact(n-1);
}


// Two pinter approach
void revArray(int l,int r,int arr[])
{
    if(l>=r) return;

    // int temp=arr[l];
    // arr[l]=arr[r];
    // arr[r]=temp;
    // or
    swap(arr[l],arr[r]);
    revArray(l+1,r-1,arr);
}

// using single variable
void revArrayUsingSv(int i,int arr[],int n)
{
    if(i>=n/2) return; // or i>=n-i-1 should also work 
    swap(arr[i],arr[n-i-1]);
    revArrayUsingSv(i+1,arr,n);
}

bool checkPalindrome(int i,string str,int n)
{
    if(i>=n-i-1) return true;
    if(str[i]!=str[n-i-1]) return false;
    return checkPalindrome(i+1,str,n);
}

// Time Complexity - O(2^n) ; using functional way with two recc calls
int fibonacci(int n)
{
    if(n<=1) return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

// Time Complexity - O(n) ; using parametrized way with single recc call
int fib(int n,int a,int b)
{
    if(n==1) return b;
    if(n==0) return a;

    return fib(n-1,b,a+b);
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    // printName(1,5);
    // print1ToN(1,5);
    // printNTo1(5,5);
    // printNTo1usingB(1, 5);
    // sumOfNterms(3,0);
    // cout<<sumOfNtermsUsingf(3)<<"\n";
    // cout<<fact(4)<<"\n";
    // int arr[]={1,2,3,4};
    // int n=sizeof(arr)/sizeof(arr[0]); // or size(arr);
    // printArray(arr,n);
    // revArrayUsingSv(0,arr,n);
    // printArray(arr,n);
    // string str="MadaM";
    // int n=str.size(); // .size() can be used for all stl containers but not for classic c style arrays
    // cout<<checkPalindrome(0,str,n);
    cout<<fibonacci(4)<<"\n";
    // cout<<fib(0,0,1)<<"\n";
}