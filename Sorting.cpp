//  sort(ans.begin(),ans.end(),greater<int>()); use greater<int>() to sort in descending order

#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n^2) for all three best,worst or average
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;
    }
}

// Time complexity - O(n^2) for worst and average
// O(n) for best case
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int didSwap = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                didSwap++;
            }
        }
        if (didSwap == 0)
            break;
    }
}

// Time complexity - O(n^2) for worst and average
// O(n) for best case
void insertionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void merge(vector<int> &arr, int l, int m, int r)
{
    vector<int> temp;
    int left = l;
    int right = m + 1;

    while (left <= m && right <= r)
    {
        if (arr[left] <= arr[right])
        {
            temp.emplace_back(arr[left]);
            left++;
        }
        else
        {
            temp.emplace_back(arr[right]);
            right++;
        }
    }
    while (left <= m)
    {
        temp.emplace_back(arr[left]);
        left++;
    }
    while (right <= r)
    {
        temp.emplace_back(arr[right]);
        right++;
    }
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }
}
void mergeSort(vector<int> &arr, int l, int r)
{
    // Time Complexity - O(nlogn) for all three best,worst or average
    // Space Complexity - O(n)

    if (l == r)
        return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main()
{
    int a[] = {13, 46, 24, 52, 20, 9};
    insertionSort(a, 6);
    printArray(a, 6);
}