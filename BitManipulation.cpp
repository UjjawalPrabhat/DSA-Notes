#include <bits/stdc++.h>
using namespace std;

// xor mei same toh zero aur different toh one
// even number of 1's toh 0 aur odd number of 1's toh 1

// right shift(>>) mei right se k bits hat jati hai aur left mei 0 add hota hai
// x>>k means x/2^k

// left shift(<<) mei har bit k times shift hoti hai aur right mei 0 add hota hai
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

// n&1 gives 1 if odd and 0 if even

// __builtin_popcount(n) is a function in c++ that returns the number of set bits in a number

// xor operator - if it appears even times then 0 otherwise number itself

int divide(int dividend, int divisor)
{
    // Brute
    // Time Complexity - O(dividend)
    // Space Complexity - O(1)
    // int count, sum = 0;
    // while (sum+divisor <= dividend)
    // {
    //     count++;
    //     sum += divisor;
    // }
    // return count;

    // Optimal
    // Time Complexity - O(log n * log n)
    // Space Complexity - O(1)
    if (dividend == divisor)
        return 1;
    if (dividend == INT_MIN && divisor == -1) // coz -2^31 can't be stored in int so return INT_MAX
        return INT_MAX;

    long y = abs((long)dividend), x = abs((long)divisor); // coz if dividend is -2^31 then it will overflow the int range
    long q = 0;
    while (x <= y)
    {
        long i = 0;
        while ((x << (i + 1)) <= y)
        {
            i++;
        }
        y -= x << i;
        q += 1 << i;
    }
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        return -q;
    return q;
}

int minBitFlips(int start, int goal)
{
    // Time Complexity - O(log n)
    // Space Complexity - O(1)

    int ans = start ^ goal;
    int count = 0;
    while (ans != 0)
    {
        ans = (ans & (ans - 1));
        count++;
    }
    return count;
}

int singleNumber(vector<int> &nums)
{
    int xor1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xor1 ^= nums[i];
    }
    return xor1;
}

vector<vector<int>> subsets(vector<int> &nums)
{
    // Time Complexity - O(2^n * n) - for each subset we are creating a new vector of size n
    // Space Complexity - O(2^n) - for storing all the subsets

    vector<vector<int>> ans;
    int n = nums.size();
    int numOfSubsets = 1 << n;

    for (int i = 0; i < numOfSubsets; i++) // The outer loop runs for 2^n times...which the represents all the subsets
    {
        vector<int> subsets;
        for (int j = 0; j < n; j++) // The inner loop runs for n times....which represents all the elements and if it's set then we have to take it
        {
            if ((i & (1 << j)) != 0) // For the ith number....check if jth bit is set or not
                subsets.emplace_back(nums[j]);
        }
        ans.emplace_back(subsets);
    }
    return ans;
}

int xor1toN(int n)
{
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    if (n % 4 == 3)
        return 0;
    if (n % 4 == 0)
        return n;
}
int findXOR(int l, int r)
{
    // Brute Force
    // Time Complexity - O(n)
    // Space Complexity - O(1)
    // int ans = 0;
    // for (int i = l; i <= r; i++) {
    //     ans ^= i;
    // }
    // return ans;

    // Optimal
    // for numbers from 0 to n, the xor is as follows:
    // 1 -> n%4 == 1 -> 1
    // 2 -> n%4 == 2 -> n+1
    // 3 -> n%4 == 3 -> 0
    // 4 -> n%4 == 0 -> n
    // Time Complexity - O(1)
    // Space Complexity - O(1)
    return xor1toN(l - 1) ^ xor1toN(r);
}

vector<long long int> twoOddNum(long long int Arr[], long long int N)
{
    // Brute
    // Using hashing store the frequency of each number in a map and then check which two numbers have odd frequency
    // Time Complexity - O(n) with two passes
    // Space Complexity - O(n)

    // Optimal
    // we use the concept of buckets here and we also leverage the fact that if there are two distinct numbers then they'd atleast differ by one bit.
    // Time Complexity - O(n) with two passes
    // Space Complexity - O(1)
    vector<long long int> ans;
    long long int xor1 = 0; // make sure to use long long int to avoid overflow coz you're doing xor1&(xor1-1) later and if xor1 is -2^31 then int can't store -2^31-1
    for (int i = 0; i < N; i++)
    {
        xor1 ^= Arr[i];
    }
    long long int rightIndex = ((xor1 & (xor1 - 1)) ^ xor1); // first we unset the rightmost set bit and then xor it with xor1 to get the rightmost set bit....coz ^ tells us which bit is different.

    long long int b1 = 0, b2 = 0;
    for (int i = 0; i < N; i++)
    {
        if ((Arr[i] & rightIndex) != 0)
            b1 ^= Arr[i];
        else
            b2 ^= Arr[i];
    }
    ans.emplace_back(b1);
    ans.emplace_back(b2);
    return ans;
}


// Advanced Maths

// Using Sieve of Eratosthenes
int countPrimes(int n)
{
    // Brute
    // just go from 2 to n and check if prime or not
    // Time Complexity - O(n*sqrt(n))
    // Space Complexity - O(1)

    // Optimal
    // Time Complexity - O(n * log(log n))  // coz it's a prime harmonic series
    // It's mathematically derived so it'd be difficult to derive so just remember it
    // Space Complexity - O(n)

    // precompute
    vector<int> prime(n + 1, 1);
    prime[0] = 0;
    if (n > 0)
        prime[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j += i)
        {
            prime[j] = 0;
        }
    }

    // check
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i] == 1)
            count++;
    }
    return count;
}

bool isPrime(int n)
{
    int fact = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            fact++;
            if (n / i != i)
                fact++;
        }
    }
    if (fact == 2)
        return true;
    return false;
}
vector<int> AllPrimeFactors(int N)
{
    // Brute
    // Time Complexity - O(n)
    // Space Complexity - O(1)
    // vector<int> ans;
    // for (int i = 1; i*i <= N; i++)
    // {
    //     if (N % i == 0)
    //     {
    //         if (isPrime(i))
    //             ans.emplace_back(i);
    //         if (N / i != i)
    //         {
    //             if (isPrime(N / i))
    //                 ans.emplace_back(N / i);
    //         }
    //     }
    // }
    // return ans;

    // Better
    // For a large number that is not prime, the number of iterations will be very less.
    // eg: For 780 it takes 13 iterations only
    // But It's better and not optimal coz if the number given is itself prime then it'll take O(n)
    // Time Complexity - O(n logn)
    // Space Complexity - O(1)
    // vector<int> ans;
    // for (int i = 2; i <= N; i++)
    // {
    //     if (N % i == 0)
    //         ans.emplace_back(i);
    //     while (N % i == 0)
    //     {
    //         N /= i;
    //     }
    // }
    // return ans;

    // Optimal
    // Time Complexity - O(sqrt(n))
    // Space Complexity - O(1)
    vector<int> ans;
    // here you're running the loop for sqrt(n) times only but still don't have to check for the N/i th number coz if N/i is prime then it won't be further divided and then it would be added in the end
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
            ans.emplace_back(i);
        while (N % i == 0) // runs for atmost log(n) times
        {
            N /= i;
        }
    }
    if (N != 1) // check to ensure that the number is not a power of 2
        ans.emplace_back(N);
    return ans;
}

// Note: 1st question is to find all primes<=n...so it's optimal to use sieve method and
// 2nd one is to find all prime 'factors' of a number
// so you don't use sieve of eratosthenes for the second one coz you don't need to find all primes<=n but only the prime 'factors' of a number

vector<vector<int>> primeFactors(vector<int> &queries)
{
    // Brute
    // Time Complexity - O(q*sqrt(n))
    // Space Complexity - O(1)
    // vector<vector<int>> ans;
    // for (int i = 0; i < queries.size(); i++)
    // {
    //     int n = queries[i];
    //     vector<int> temp;
    //     for (int j = 2; j * j <= n; j++)
    //     {
    //         if (n % j == 0)
    //         {
    //             while (n % j == 0)
    //             {
    //                 temp.emplace_back(j);
    //                 n /= j;
    //             }
    //         }
    //     }
    //     if (n != 1)
    //         temp.emplace_back(n);
    //     ans.emplace_back(temp);
    // }
    // return ans;

    // Optimal
    // If there is only one number given then the above approach is optimal coz fo rjust one number we can find the prime factors in O(sqrt(n)) time
    // but if there are multiple numbers then we can use the sieve of eratosthenes to find all the prime factors of all the numbers in O(n*log(log n)) time and
    // then for each query we can just return the prime factors in O(log(n)) time.
    // So overall Time Complexity - O(n*log(log n) + O(q*log(n)) => O(q*log(n))
    // Space Complexity - O(n)
    const int maxN = 100000;

    vector<int> spf(maxN + 1);
    for (int i = 0; i <= maxN; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i <= maxN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    vector<vector<int>> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        int n = queries[i];
        vector<int> temp;
        while (n != 1)
        {
            temp.emplace_back(spf[n]);
            n /= spf[n];
        }
        ans.emplace_back(temp);
    }
}

double myPow(double x, int n)
{
    // Brute
    // Time Complexity - O(n)
    // Space Complexity - O(1)
    // double ans = 1;
    // for (int i = 0; i < abs(n); i++)
    // {
    //     ans *= x;
    // }
    // if (n < 0)
    //     return 1 / ans;
    // return ans;

    // Optimal
    // Time Complexity - O(log n)
    // Space Complexity - O(1)
    double temp = 1;
    int p = abs(n);
    while (p > 0)
    {
        if ((p & 1) == 0)
        {
            p = p >> 1;
            x *= x;
        }
        else
        {
            p -= 1;
            temp *= x;
        }
    }
    if (n < 0)
        return 1 / temp;
    return temp;
}

int main()
{
    cout << divide(6, 2) << "\n";
}
