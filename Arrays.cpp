// max array size inside int main is 10^6
// 10^7 globaly
// 10^8 iterations take roughly 1s

#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printVector(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void secondLargest(int a[], int n)
{
    int l = a[0];
    int sL = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > l)
        {
            sL = l;
            l = a[i];
        }
        else if (a[i] != l && a[i] > sL)
            sL = a[i];
    }
    cout << l << endl;
    cout << sL << endl;
}

void checkSorted(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            cout << false;
            return;
        }
    }
    cout << true;
}

void remDuplicates(int a[], int n)
{
    // Given the array to be sorted

    // Brute O(n^2)
    // int nunique=n;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(i!=j)
    //         {
    //             if(a[i]==a[j])
    //             {
    //                 a[j]=0;
    //                 nunique--;
    //             }
    //         }
    //     }
    // }

    // Brute By set O(n log n + n)
    // set<int> st;
    // for(int i=0;i<n;i++) // O(nlogn)
    // {
    //     st.insert(a[i]);
    // }
    // int index=0;
    // for(auto it:st) // O(n)
    // {
    //     a[index]=it;
    //     index++;
    // }

    // Optimal O(n)
    // Two Pointer approach
    int i = 0, j = 1;
    while (j < n)
    {
        if (a[i] != a[j])
        {
            a[i + 1] = a[j];
            i++;
        }
        else
            a[j] = 0;
        j++;
    }
    cout << i + 1 << endl;
}

void rotateArray(int a[], int n, int p, int q)
{
    // Time complexity O(n)
    // Space complexity O(1) - this is the extra space; but space used in algo is O(n)
    int temp = a[p];
    for (int i = p; i < q - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[q - 1] = temp;
}

void revArray(int a[], int n, int p, int q)
{
    // Time complexity O(n)
    // Space complexity O(1)
    q -= 1;
    while (p < q)
    {
        swap(a[p], a[q]);
        p++;
        q--;
    }
}

void rotateArrayByD(int a[], int n, int d)
{
    // Brute
    // Time complexity O(n+d)
    // Space complexity O(d)

    // d%=n;
    // int temp[d];
    // for(int i=0;i<d;i++)
    // {
    //     temp[i]=a[i];
    // }
    // for(int i=0;i<n-d;i++)
    // {
    //     a[i]=a[i+d];
    // }
    // for(int i=n-d;i<n;i++)
    // {
    //     a[i]=temp[i-n+d];
    // }

    // Optimal
    // Time complexity O(n)
    // Space complexity O(1)

    reverse(a, a + n);
    reverse(a, a + n - d);
    reverse(a + n - d, a + n);
    // revArray(a,n,0,n);
    // revArray(a,n,0,n-d);
    // revArray(a,n,n-d,n);
}

void moveZeroes(int a[], int n)
{
    // Brute
    // Time complexity O(n)
    // Space complexity O(n)

    // vector<int> temp;
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] != 0)
    //     {
    //         temp.emplace_back(a[i]);
    //     }
    // }
    // for (int i = 0; i < temp.size(); i++)
    // {
    //     a[i] = temp[i];
    // }
    // for (int i = temp.size(); i < n; i++)
    // {
    //     a[i] = 0;
    // }

    // Optimal
    // Similar to two pointer approach
    // Time complexity O(n)
    // Space complexity O(1)

    // find the first zero
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    for (int i = j + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
}

void unionOfSortedArrays(vector<int> a1, vector<int> a2)
{
    // Brute
    // Time complexity O(n1logn + n2logn)+O(n1+n2)
    // Space complexity O(n1+n2)

    // set<int> st;
    // for (int i = 0; i < n1; i++)
    // {
    //     st.insert(a1[i]);
    // }
    // for (int i = 0; i < n2; i++)
    // {
    //     st.insert(a2[i]);
    // }
    // int arr[st.size()];
    // int i = 0;
    // for (auto it : st)
    // {
    //     arr[i] = it;
    //     i++;
    // }

    // Optimal
    // Time complexity O(n1+n2)
    // Space complexity O(n1+n2) for returning the ans not in my algo

    int n1 = a1.size();
    int n2 = a2.size();
    int i = 0, j = 0;
    vector<int> unionArr;
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
        {
            if (unionArr.size() == 0 || a1[i] != unionArr.back())
                unionArr.emplace_back(a1[i]);
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || a2[j] != unionArr.back())
                unionArr.emplace_back(a2[j]);
            j++;
        }
    }
    while (i < n1)
    {
        if (unionArr.size() == 0 || a1[i] != unionArr.back())
            unionArr.emplace_back(a1[i]);
        i++;
    }
    while (j < n2)
    {
        if (unionArr.size() == 0 || a2[j] != unionArr.back())
            unionArr.emplace_back(a2[j]);
        j++;
    }
    printVector(unionArr);
}

void intersectionOfSortedArrays(vector<int> a1, vector<int> a2)
{
    // Brute
    // Time complexity O(n1*n2)
    // Space complexity O(n2)

    // int n1 = a1.size();
    // int n2 = a2.size();
    // vector<int> intersectionArr;
    // int vis[n2] = {0};
    // for (int i = 0; i < a1.size(); i++)
    // {
    //     for (int j = 0; j < a2.size(); j++)
    //     {
    //         if (a1[i] == a2[j] && vis[j] == 0)
    //         {
    //             intersectionArr.emplace_back(a1[i]);
    //             vis[j] = 1;
    //             break;
    //         }
    //         if (a2[j] > a1[i])
    //             break;
    //     }
    // }

    // Optimal
    // Time complexity O(n1+n2)
    // Space complexity O(n1+n2) but for returning the ans not in my algo

    int n1 = a1.size();
    int n2 = a2.size();
    int i = 0, j = 0;
    vector<int> intersectionArr;
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
            i++;
        else if (a1[i] > a2[j])
            j++;
        else
        {
            intersectionArr.emplace_back(a1[i]);
            i++;
            j++;
        }
    }
    printVector(intersectionArr);
}

void findMissingNumber(int a[], int n)
{
    // Brute
    // Time complexity O(n^2)
    // Space complexity O(1)

    // for(int i=1;i<=n;i++)
    // {
    //     int c=0;
    //     for(int j=0;j<n-1;j++)
    //     {
    //         if(a[j]==i)
    //         {
    //             c=1;
    //             break;
    //         }
    //     }
    //     if(c==0) cout<<i<<endl;
    // }

    // Better
    // Using Hashing
    // Time complexity O(n)
    // Space complexity O(n+1)

    // int hash[n + 1] = {0};
    // for (int i = 0; i < n-1; i++)
    // {
    //     hash[a[i]]++;
    // }
    // for(int i=1;i<=n;i++)
    // {
    //     if(hash[i]==0)
    //     {
    //         cout<<i<<endl;
    //         break;
    //     }
    // }

    // Optimal
    // Time complexity O(n)
    // Space complexity O(1)

    // Sum method

    // int sum1=n*(n+1)/2;
    // int sum2=0;
    // for(int i=0;i<n-1;i++)
    // {
    //     sum2+=a[i];
    // }
    // cout<<sum1-sum2<<endl;

    // XOR method
    // Better than sum method
    // coz max xor can go uptil 10^5

    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xor1 ^= (i + 1);
        xor2 ^= a[i];
    }
    xor1 ^= n;
    cout << (xor1 ^ xor2) << endl;
}

void maxConsOnes(int a[], int n)
{
    // Optimal
    // Time complexity O(n)
    // Space complexity O(1)

    int max1 = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            max1 = max(max1, count);
            count = 0;
        }
        else
            count++;
    }
    max1 = max(max1, count);
    cout << max1 << endl;
}

void appearsOnce(int a[], int n)
{
    // Better
    // Time complexity O(n/2+1) + O(nlogm) [for worst case; m=n/2+1]
    // Space complexity O(n/2+1)

    // unordered_map<int, int> mpp;
    // for (int i = 0; i < n; i++)
    // {
    //     mpp[a[i]]++;
    // }
    // for(int i=0;i<n;i++)
    // {
    //     if(mpp[a[i]]==1)
    //     {
    //         cout<<a[i]<<endl;
    //         break;
    //     }
    // }

    // Optimal
    // Time complexity O(n)
    // Space complexity O(1)

    int xo = 0;
    for (int i = 0; i < n; i++)
    {
        xo ^= a[i];
    }
    cout << xo << endl;
}

void longestSubarray(vector<int> &a, int k)
{
    // Better for arrays with only +ve numbers and zeroes
    // Optimal for arrays with +ve and -ve numbers
    // Time complexity O(n)
    // Space complexity O(n)

    // long long sum = 0;
    // int maxLen = 0;
    // unordered_map<long long, int> mp; // worst case mei O(n) toh overall O(n^2) ho jaega   // also ordered takes O(logn)
    // for (int i = 0; i < a.size(); i++)
    // {
    //     sum += a[i];
    //     if (sum == k)
    //         maxLen = max(maxLen, i + 1);
    //     long long rem = sum - k;
    //     if (mp.find(rem) != mp.end())
    //     {
    //         int len = i - mp[rem];
    //         maxLen = max(maxLen, len);
    //     }
    //     if (mp.find(sum) == mp.end())
    //         mp[sum] = i;
    // }
    // cout << maxLen << endl;

    // Optimal for arrays with non-negative numbers

    int i = 0, j = 0;
    long long sum = a[0];
    int maxLen = 0;
    while (j < a.size())
    {
        while (sum > k)
        {
            sum -= a[i];
            i++;
        }
        if (sum == k)
            maxLen = max(maxLen, j - i + 1);
        j++;
        sum += a[j];
    }
    cout << maxLen << endl;
}

bool twoSum(vector<int> &a, int k)
{
    // Better if you only want to return boolean value
    // But Optimal if you want to return the indexes of both numbers
    // Time Complexity - O(n);
    // Space Complexity - O(n);

    // vector<int> res;
    // unordered_map<int, int> mp;
    // for (int i = 0; i < a.size(); i++)
    // {
    //     int rem = k - a[i];
    //     if (mp.find(rem) != mp.end())
    //     {
    //         res.emplace_back(i);
    //         res.emplace_back(mp[rem]);
    //         break;
    //     }
    //     mp[a[i]] = i;
    // }
    // printVector(res);

    // Optimal to only return boolean value
    sort(a.begin(), a.begin() + a.size());
    int i = 0, j = a.size() - 1;
    while (i < j)
    {
        int sum = a[i] + a[j];
        if (sum == k)
            return true;
        else if (sum < k)
            i++;
        else
            j--;
    }
    return false;
}

void sortArrayWith012(vector<int> &a)
{
    // Brute
    // Time Complexity - O(nlogn)
    // Space Complexity - O(1)
    // In Brute you can simply sort the array using merge or quick sort

    // Better
    // Time Complexity - O(2n)
    // Space Complexity - O(1)
    // In Better you can use 3 counters for 0,1&2 and then overwrite the array...hence 2N

    // Optimal
    // Dutch National Flag Algo
    // (0<->low-1) -> will have only 0's
    // (low<->mid-1) -> will have only 1's
    // (mid<->high) -> this is the unsorted part that we need to deal with
    // (high+1<->n-1) -> will have only 2's
    // Time Complexity - O(n)
    // Space Complexity - O(1)

    int n = a.size();
    int low = 0, mid = 0, high = n - 1;
    while ((high - mid + 1) != 0)
    {
        if (a[mid] == 0)
        {
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else if (a[mid] == 1)
            mid++;
        else
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
}

int maxSubarraySum(vector<int> &a)
{
    // Optimal
    // Kadane's Algo - you just keep iterating and summing and if sum is not +ve then leave it
    // Time Complexity - O(n)
    // Space Complexity - O(1)
    int sum = 0, maxi = INT_MIN;
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (sum == 0)
            startIndex = i;
        sum += a[i];
        if (sum > maxi)
        {
            maxi = sum;
            endIndex = i;
        }
        if (sum < 0)
            sum = 0;
    }
    cout << startIndex << " " << endIndex << "\n";
    return maxi;
}

int majorityElement(vector<int> &a)
{
    // Better
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    // int n = a.size();
    // unordered_map<int, int> mpp;
    // for (int i = 0; i < n; i++)
    // {
    //     mpp[a[i]]++;
    // }
    // for (auto it : mpp)
    // {
    //     if (it.second >= n / 2)
    //         return it.first;
    // }

    // Optimal
    // Moore's Voting Algo
    // so with the help of count we're keeping a track if any element is dominating and if it's 0 we shift to the newer element
    // Time Complexity - O(n)
    // Space Complexity - O(1)

    // Applying Moore's Algo
    int n = a.size();
    int el, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            el = a[i];
        if (a[i] == el)
            count++;
        else
            count--;
    }

    // Verify if the element actually appears more than n/2 times
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (el == a[i])
            count++;
    }
    if (count > n / 2)
        return el;
    else
        return -1;
}

int maxProfit(vector<int> &a)
{
    // Optimal
    // Time Complexity - O(n)
    // Space Complexity - O(1)
    int mini = a[0], profit = 0;
    for (int i = 1; i < a.size(); i++)
    {
        int diff = a[i] - mini;
        profit = max(profit, diff);
        mini = min(mini, a[i]);
    }
    return profit;
}

// Rearrange Array elements by Sign

// Gonna have the same num of +ves and -ves
vector<int> altSignWithEqualNum(vector<int> &a)
{
    // Optimal
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    int n = a.size();
    vector<int> ans(n, 0);
    int pos = 0, neg = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            ans[pos] = a[i];
            pos += 2;
        }
        else
        {
            ans[neg] = a[i];
            neg += 2;
        }
    }
    return ans;
}

// Not guaranteed to have same num of +ves and -ves
void altSign(vector<int> &a)
{
    // Optimal
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    int n = a.size();
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            pos.emplace_back(a[i]);
        else
            neg.emplace_back(a[i]);
    }

    int i = 0, j = 0, k = 0;
    while (i < pos.size() && j < neg.size())
    {
        if (k % 2 == 0)
        {
            a[k] = pos[i];
            i++;
        }
        else
        {
            a[k] = neg[j];
            j++;
        }
        k++;
    }
    while (i < pos.size())
    {
        a[k] = pos[i];
        i++;
        k++;
    }
    while (j < neg.size())
    {
        a[k] = neg[j];
        j++;
        k++;
    }
}

void nextGraterPermutation(vector<int> &nums)
{
    // next_permutation(a.begin(),a.end()); // only available in c++ STL
    int n = nums.size();
    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i - 1] < nums[i])
        {
            for (int j = n - 1; j >= i; j--)
            {
                if (nums[j] > nums[i - 1])
                {
                    swap(nums[j], nums[i - 1]);
                    break;
                }
            }
            reverse(nums.begin() + i, nums.begin() + n);
            return;
        }
    }
    reverse(nums.begin(), nums.begin() + n);
}

vector<int> leadersInArray(vector<int> &a)
{
    int n = a.size();
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= maxi)
        {
            ans.emplace_back(a[i]);
            maxi = a[i];
        }
    }
    return ans;
}

int longestConsecutive(vector<int> &a)
{
    // Better
    // Time Complexity - O(nlogn)
    // Space Complexity - O(1)

    // sort(a.begin(),a.end());
    // int lastSmaller=INT_MIN;
    // int count=0,maxCount=0;
    // for(int i=0;i<a.size();i++)
    // {
    //     if(a[i]==lastSmaller+1)
    //     {
    //         count++;
    //         lastSmaller=a[i];
    //     }
    //     else if(a[i]!=lastSmaller)
    //     {
    //         count=1;
    //         lastSmaller=a[i];
    //     }
    //     maxCount=max(maxCount,count);
    // }
    // return maxCount;

    // Optimal
    // Try to find the start of the sequence and then keep on increasing the count
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    if (a.size() == 0)
        return 0;
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                cnt++;
                x++;
            }
            longest = max(cnt, longest);
        }
    }
    return longest;
}

void setMatrix(vector<vector<int>> &a)
{
    // Better
    // Time Complexity - O(n*m)
    // Space Complexity - O(n+m)
    // int n = a.size();
    // int m = a[0].size();
    // int row[n] = {0};
    // int col[m] = {0};
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (a[i][j] == 0)
    //         {
    //             row[i] = 1;
    //             col[j] = 1;
    //         }
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (row[i] == 1 || col[j] == 1)
    //             a[i][j] = 0;
    //     }
    // }

    // Optimal
    // Time Complexity - O(n*m)
    // Space Complexity - O(1)
    int n = a.size();
    int m = a[0].size();
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                if (j == 0)
                    col0 = 0;
                else
                {
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                if (a[0][j] == 0 || a[i][0] == 0)
                    a[i][j] = 0;
            }
        }
    }

    if (a[0][0] == 0)
    {
        for (int j = 1; j < m; j++)
        {
            a[0][j] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            a[i][0] = 0;
        }
    }
}

void rotateMatrixBy90(vector<vector<int>> &a)
{
    // Brute
    // Time Complexity - O(n^2)
    // Space Complexity - O(n^2)

    // int n = a.size();
    // vector<vector<int>> temp(n, vector<int>(n, 0));
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         temp[j][n-1-i]=a[i][j];
    //     }
    // }
    // printMatrix(temp);

    // Optimal
    // Time Complexity - O(n^2)
    // Space Complexity - O(1)

    int n = a.size();
    // Transpose
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(a[i][j], a[j][i]);
        }
    }
    // Reverse
    for (int i = 0; i < n; i++)
    {
        reverse(a[i].begin(), a[i].end());
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    // Only Optimal Sol
    // Time Complexity - O(n*m)
    // Space Complexity - O(1)
    
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (left <= right && top <= bottom)
    {
        // left-->right
        for (int j = left; j <= right; j++)
        {
            ans.emplace_back(matrix[top][j]);
        }
        top++;

        // top-->bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.emplace_back(matrix[i][right]);
        }
        right--;

        // left-->right
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                ans.emplace_back(matrix[bottom][j]);
            }
            bottom--;
        }

        // bottom-->top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.emplace_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int subarraySum(vector<int> &nums, int k)
{
    // Optimal
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    unordered_map<int, int> mpp;
    mpp[0] = 1; // accounting for  if(sum==k) count++;
    int count = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int rem = sum - k;
        if (mpp.find(rem) != mpp.end())
            count += mpp[rem];
        mpp[sum]++; // we're adding the frequency of the sum coz we need to find all possible subarrays
    }
    return count;
}

int main()
{
    // int a[] = {1, 1, 2, 3, 3, 4, 4};
    // vector<int> a1 = {1, 2, 3, 4, 5};
    // vector<int> a2 = {2, 4, 6, 8};
    // vector<int> a = {1, 2, 3};
    // printVector(a);
    // cout << longestConsecutive(a);
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printMatrix(a);
    rotateMatrixBy90(a);
    printMatrix(a);
    // printVector(a);
    // appearsOnce(a, 7);
    // printArray(a, 7);
}

// most probably think of two pointer in a sorted array or in case of some pattern ques like swaps or subarrays