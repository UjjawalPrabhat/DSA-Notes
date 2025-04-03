#include<bits/stdc++.h>
using namespace std;

// inside main the max array size for int is 10^6
// while globaly it's 10^7

// Array hashing

// hashing in numbers
// int main()
// {
//     int arrSize;
//     cin>>arrSize;

//     int arr[arrSize];
//     for(int i=0;i<arrSize;i++)
//     {
//         cin>>arr[i];
//     }

//     // precompute
//     int hash[100000]={0};
//     for(int i=0;i<arrSize;i++)
//     {
//         hash[arr[i]]+=1;
//     }

//     int numOfQuer;
//     cin>>numOfQuer;
//     while(numOfQuer--)
//     {
//         int quer;
//         cin>>quer;

//         // fetch
//         cout<<hash[quer]<<" ";
//     }

// }

// hashing in string
// int main()
// {
//     string s;
//     cin>>s;

//     // precompute
//     int hash[256]={0};
//     for(int i=0;i<s.size();i++)
//     {
//         hash[s[i]]++;
//     }
//     int q;
//     cin>>q;
//     while(q--)
//     {
//         char c;
//         cin>>c;
//         // fetch
//         cout<<hash[c]<<" ";
//     }
// }


// Using Map
// Time complexity of Map 
// for storing and fetching is O(log n) 
// for all three cases(best/worst/avg)
// also map can take anything

// for unordered_map
// it takes O(1) for best and avg
// and O(n) for worst case
// overall it becomes O(n^2)
// but still we should prefer unorderd_map coz it very rarely happens
// but unordered_map is limited...like it can't take pair or vector,etc...only individual data types

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    // pre-compute
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }

    // // iterate in the map
    // for(auto it:mpp)
    // {
    //     cout<<it.first<<"-->"<<it.second<<"\n";
    // }

    int q;
    cin>>q;
    while(q--)
    {
        int number;
        cin>>number;
        // fetch
        cout<<mpp[number]<<" ";
    }
}

// Division Method - this is for array hashing not map
// like if there's a limitation on array size then we can do it by this method
// multiple elements ending with same number are stored using linear chaining
// collision - and if every element went to the same hash place then collision happens...but it's very rare

