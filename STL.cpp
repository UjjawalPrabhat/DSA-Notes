#include <bits/stdc++.h>
using namespace std;

// Container

// // Pairs
void explainPair()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> np = {1, {3, 4}};
    cout << np.first << " " << np.second.first << " " << np.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second << endl;
}

// Vectors
// size is not fixed, can be adjusted as required
void explainVector()
{

    // vector<int> v;

    // v.push_back(1);
    // v.emplace_back(2); // faster than push_back

    // vector<pair<int, int>>vec;

    // vec.push_back({1,2});
    // vec.emplace_back(1,2);

    // vector<int> v(5,100); // creates 5 instances of 100

    // vector<int> v(5); //creates 5 instances of any garbage value

    // vector<int> v1(5,20);
    // vector<int> v2(v1); // creates a copy of v1

    // vector<int> v;
    // v.emplace_back(20);
    // v.emplace_back(10);
    // v.push_back(15);
    // v.push_back(6);
    // v.push_back(7);
    // vector<int>::iterator it=v.begin();
    // it++;
    // cout<<*(it)<<" "; // *means the element at that memory address

    // it=it+2;
    // cout<<*(it)<<" ";

    // vector<int>::iterator it=v.end(); // points to just after last element
    // vector<int>::iterator it=v.rend(); // points to just before 1st element
    // vector<int>::iterator it=v.rbegin();// starts from end and also iterates in the revrse way

    // cout<<v[0]<<" "<<v.at(0);
    // cout<<v.back()<<" "; // points to the last element

    // // print the entire vector
    // for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    // {
    //     cout<<*(it)<<" ";
    // }

    // for(auto it=v.begin;it!=v.end();it++) // auto means automatically assigns the data type according to the data
    // {
    //     cout<<*(it)<<" ";
    // }

    // for(auto it:v)
    // {
    //     cout<<it<<" ";
    // }

    // // deletion
    // v.erase(v.begin()+1); // deletes second element and reshufles the vector
    // v.erase(v.begin()+1,v.begin()+4) // deletes from 2nd to 3rd

    // Insert function

    vector<int> v(2, 100);         // {100,100}
    v.insert(v.begin(), 300);      // {300,100,100}
    v.insert(v.begin() + 1, 2, 10) //{300,10,10,100,100}

        vector<int>
            copy(2, 50);                           // {50,50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50,50,300,10,10,100,100}

    // {10,20}
    cout << v.size(); // 2

    // {10,20}
    v.pop_back(); // {10}; pops the last element

    // v1 -> {10,20}
    // v2 -> {30,40}
    v1.swap(v2); // v1 -> {30,40}, v2 -> {10,20}

    v.clear(); // erases the entire vector

    cout << v.empty(); // returns boolean value based on if any element is present
}

void explainList()
{
    list<int> ls;
    ls.push_back(2);    // {2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5); // {5,2,4} ; much faster than insert func in vector, coz a doubly linked list is maintained for a list while a singly linked list is maintained for a vector

    ls.emplace_front(); // {2,4}

    // rest functions same as vector
    // begin, end, rebegin, rend, clear, insert, size, swap
}

void explainDeque()
{
    deque<int> dq;
    dq.push_back(1);     // {1}
    dq.emplace_back(2);  // {1,2}
    dq.push_front(4);    // {4,1,2}
    dq.emplace_front(3); // {3,4,1,2}

    dq.pop_back();  // {3,4,1}
    dq.pop_front(); // {4,1}

    dq.back();

    dq.front();

    // rest functions same as vector
    // begin, end, rebegin, rend, clear, insert, size, swap
}

// LIFO - Last In First Out
// Time complexity - O(1)
// only three main func - push O(log n), pop O(log n), top O(1)
void explainStack()
{
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2,1}
    st.push(3); // {3,2,1}
    st.push(3); // {3,3,2,1}
    st.emplace(5); // {5,3,3,2,1}

    cout<<st.top(); // prints 5  "** st[2] is invalid **"

    st.pop(); // st looks like {3,3,2,1}

    cout<< st.top(); // 3
    cout<<st.size(); // 4
    cout<<st.empty();

    stack<int>st1, st2;
    st1.swap(st2);

}

// FIFO - First In First Out
// similar to stack
// Time Complexity - O(1)
void explainQueue()
{
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.emplace(4); // {1,2,4}

    q.back()+=5;

    cout<<q.back(); // prints 9

    // Q is {1,2,9}
    cout<<q.front();// prints 1

    q.pop(); // {2,9}

    cout<<q.front(); // prints 2

    // size swap empty same as stack

}

// data is stored in a tree fashion not linear
void explainPQ()
{
    // Max Heap
    priority_queue<int>pq;

    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); // {10,8,5,2}

    cout<<pq.top(); // prints 10

    pq.pop(); // {8,5,2}

    cout<<pq.top(); // prints 8

    // size swap empty function same as others

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8}
    pq.emplace(10); // {2,5,8,10}

    cout<<pq.top();
}

// Set - stores everything in sorted order
// stores unique
// everything happens in O(log n) time complexity
void explainSet()
{
    set<int>st;
    st.insert(1);
    st.emplace(2); // {1}
    st.insert(2); // {1,2}
    st.insert(4); // {1,2}
    st.insert(3); // {1,2,4}
    st.insert(3); // {1,2,3,4}

    // Functionality of insert in vector
    // can be used also, that only increases
    // efficiency

    // begin(), end(), rebegin(), rend(), size(),
    // empty() and swap() are same as those of above

    // {1,2,3,4,5}
    auto it=st.find(3); // points to the memory place of 3

    // {1,2,3,4,5}
    auto it=st.find(6); // if 6 is not present then st.end() is returned

    // {1,4,5}
    st.erase(5); // erases 5 // takes logarithmic time

    int cnt=st.count(1); // if it exists returns 1 otherwise 0

    auto it=st.find(3);
    st.erase(it); // it takes const time

    // {1,2,3,4,5}
    auto it1=st.find(2);
    auto it2=st.find(4);
    st.erase(it1, it2); // after erase {1,4,5} [first,last)

    // lower_bound() and upper_bound() function works in same way
    // as in vector it does.

    // This is the syntax
    auto it = st.lower_bound(2);

    auto it = st.upper_bound(3);

    // Binary Search
    A[] = {1,4,5,8,9}

    bool res=binary_search(a,a+n,3); // false (start,end+1,element)
    bool res=binary_search(a,a+n,4); // true

    // lower_bound - returns the iterator to that element
    // Time complexity-O(log n)
    a[]={1,4,5,6,9,9}

    int ind=lower_bound(a,a+n,4)-a; // 1
    int ind=lower_bound(a,a+n,7)-a; // 4 returns the index of 9 coz 7 is not present so it finds for the element grater just after 7
    int ind=lower_bound(a,a+n,10)-a; // 6 returns the iterator to the end coz there is nothing grater than 10

    // upper_bound - returns the iterator of the element just grater than the entered element
    // Time complexity-O(log n)
    a[]={1,4,5,6,9,9}

    int ind=upper_bound(a,a+n,4)-a; // 2
    int ind=upper_bound(a,a+n,7)-a; // 4
    int ind=upper_bound(a,a+n,10)-a; // 6

}

// everything same as set
// except can store duplicate elements also
void explainMultiSet()
{
    multiset<int>ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    ms.erase(1); // all 1's erased

    int cnt=ms.count(1);

    // only a single one erased
    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(1)+2);

    // rest all function same as set
}

void explainUSet()
{
    unordered_set<int> st;
    // lower_bound and upper_bound does not work
    // rest all functions are same
    // doesn't stores in sorted order
    // but has unique elements
    // most of the cases has time complexity as O(1)

}

// Map - {key,value}
// stores unique keys in sorted order
void explainMap()
{
    map<int, int> mpp;
    mpp[1]=2; // {1,2}
    mpp.emplace({3,1}); // {3,1}
    mpp.insert({2,4}); // {2,4}
    // {
    //     {1,2}
    //     {2,4}
    //     {3,1}
    // }


    map<int, pair<int,int>> mpp;

    map<pair<int,int>,int> mpp;
    mpp[{2,3}]=10;

    for(auto it:map)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }

    cout<<mpp[1]; // 2
    cout<<mpp[5]; // 0 or null if doesn't exists

    auto it=mpp.find(3);
    cout<<*(it).second;

    auto it=mpp.find(5); // points to mpp.end() if it isn't there

    // This is the syntax
    auto it=mpp.lower_bound(2);
    auto it=mpp.upper_bound(3);

    // erase,swap, size, empty are same as above
}

void explainMultiMap()
{
    // everything same as map
    // only it can store duplicate keys
}

void explainUMap()
{
    // same as set and unordered_set difference
    // unique keys but won't be sorted
    // time complexity is O(1) in most cases
}


// Important Algos

// analyse in terms of two pair
bool comp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    // if they are same
    if(p1.first>p2.first) return true;
    return false;
}

void explainExtra()
{
    sort(a,a+n); // for any container except map
    sort(v.begin(), v.end()); // for vector

    // {1,3,5,2}
    sort(a+2,a+4); // {1,3,2,5}

    // for descending order
    sort(a, a+n, greater<int>);

    // my way
    pair<int,int> a[]={{1,2},{2,1},{4,1}};

    // sort it according to increasing second element
    // if 2nd element is same, then
    // sort according to 1st element but in descending

    sort(a, a+n, comp); // for my_way

    int num=7;
    int cnt=_builtin_popcount(); // 3 returns the number of set bits i.e. no. of 1's

    long long num=165786578687;
    int cnt=_builtin_popcountll(); // becomes this if it's long long

    string s="123";
    sort(s.begin(), s.end()); // prints all the permutations of s
    
    do{
        cout<<s<<endl;
    } while(next_permutation(s.begin(), s.end()));

    int maxi=*max_element(a,a+n); // returns the max element
}

int main()
{

    return 0;
}