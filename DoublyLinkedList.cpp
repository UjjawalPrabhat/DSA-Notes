#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void printDLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *convertArr2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node *removeHead(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    Node *newHead = new Node(head->next->data, head->next->next, nullptr);
    head->next = nullptr;
    free(head);
    return newHead;
}

Node *removeTail(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->next == nullptr)
    {
        free(head);
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp2->back = nullptr;
    temp->next = nullptr;
    free(temp2);
    return head;
}

Node *removeKthElement(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;
    if (k == 1)
        return removeHead(head);

    Node *temp = head;
    int count = 0;
    while (temp)
    {
        if (count == k - 1)
            break;
        count++;
        temp = temp->next;
    }
    Node *prev = temp->back;
    prev->next = temp->next;
    if (temp->next != nullptr)
    {
        temp->next->back = prev; // if temp is not the last element
        temp->next = nullptr;
    }
    temp->back = nullptr;
    free(temp);
    return head;
}

// Given that the node to be removed is not the head node
void removeNode(Node *givenNode)
{
    if (givenNode == nullptr)
        return;

    givenNode->back->next = givenNode->next;
    if (givenNode->next != nullptr)
    {
        givenNode->next->back = givenNode->back;
        givenNode->next = nullptr;
    }
    givenNode->back = nullptr;
    free(givenNode);
}

Node *inserBeforeHead(Node *head, int data)
{
    Node *newHead = new Node(data, head, nullptr);
    head->back = newHead;
    return newHead;
}

Node *insertBeforTail(Node *head, int data)
{
    if (head == nullptr)
    {
        return new Node(data);
    }
    if (head->next == nullptr)
    {
        return inserBeforeHead(head, data);
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(data, temp->next, temp);
    temp->next = newNode;
    return head;
}

Node *insertBeforeKthElement(Node *head, int k, int data)
{
    if (k == 1)
        return inserBeforeHead(head, data);

    Node *temp = head;
    int count = 0;
    while (temp->next != nullptr)
    {
        if (count == k - 1)
            break;
        count++;
        temp = temp->next;
    }
    Node *newNode = new Node(data, temp, temp->back);
    temp->back->next = newNode;
    return head;
}

// Given - The givenNode is not the head node
void insertBeforeNode(Node *givenNode, int val)
{
    Node *newNode = new Node(val, givenNode, givenNode->back);
    givenNode->back->next = newNode;
    givenNode->back = newNode;
}

Node *reverseDLL(Node *head)
{
    // Brute
    // Time Complexity - O(n) and takes 2 passes
    // Space Complexity - O(n)
    // stack<int> st;
    // Node *temp = head;
    // while (temp != nullptr)
    // {
    //     st.push(temp->data);
    //     temp = temp->next;
    // }
    // temp = head;
    // while (temp != nullptr)
    // {
    //     temp->data = st.top();
    //     st.pop();
    //     temp = temp->next;
    // }
    // return head;

    // Optimal
    // Time Complexity - O(n) and takes 1 pass
    // Space Complexity - O(1)

    if (head == nullptr || head->next == nullptr)
        return head;
    Node *current = head;
    while (current)

    {
        Node *last = current->back;
        current->back = current->next;
        current->next = last;

        if (current->back == nullptr)
            break;
        current = current->back;
    }
    return current;
}



int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertArr2DLL(arr);
    printDLL(head);
    return 0;
}