#include <bits/stdc++.h>
using namespace std;

// xor mei same toh zero aur different toh one

// right shift(>>) mei right se bits hat jati hai
// x>>k means x/2^k

// left shift(<<) mei left se bits add ho jati hai
// x<<k means x*2^k

// -ve numbers are stored in 2's complement form with it's left most bit as 1 indicating it's negative

// largest number that can be stored in 32 bit system is 2^31-1

// min number that can be stored in 32 bit system is -2^31

// swap two numbers without using a third variable
// a=a^b;
// b=a^b;
// a=a^b;

// check if the ith bt is set or not
// if(n&(1<<i)) cout<<"Yes\n"; using left shift
// else cout<<"No\n";
// if((n>>i)&1) cout<<"Yes\n"; using right shift
// else cout<<"No\n";

// set the ith bit
// n=n|(1<<i); using left shift

// clear the ith bit
// n=n&(~(1<<i)); using left shift

// toggle the ith bit
// n=n^(1<<i); using left shift

// clear the rightmost set bit
// n=n&(n-1);

// check if the number is power of 2
// if(n&(n-1) == 0) cout<<"Yes\n";

// when you do n&(n-1) , the number of set bits decreases by 1

int countSetBits(int n)
{
    // int count = 0;
    // while (n > 1)
    // {
    //     count += n & 1; // or count+=n%2;  mtlb check kr rha hai ki last bit 1 hai ya nhi...kyuki agr 1 hai toh odd hai
    //     n = n >> 1;     // or n=n/2;
    // }
    // if (n == 1)
    //     count++;
    // return count;

    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

// builtin_popcount(n) is a function in c++ that returns the number of set bits in a number

// xor operator - if it appears even times then 0 otherwise number itself

int divide(int dividend, int divisor)
{
    // Brute
    // Time Complexity - O(dividend)
    // int count, sum = 0;
    // while (sum+divisor <= dividend)
    // {
    //     count++;
    //     sum += divisor;
    // }
    // return count;

    // Optimal

    

}

int main()
{
    cout << divide(6, 2) << "\n";
}
