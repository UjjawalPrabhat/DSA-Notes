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
        int didSwap=0;
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
        if(didSwap==0)
        break;
    }
}

// Time complexity - O(n^2) for worst and average
// O(n) for best case
void insertionSort(int a[], int n)
{
    for (int i = 0; i <n; i++)
    {
        int j=i;
        while(j>0 && a[j]<a[j-1])
        {
            int temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
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

int main()
{
    int a[] = {13, 46, 24, 52, 20, 9};
    insertionSort(a, 6);
    printArray(a, 6);
}