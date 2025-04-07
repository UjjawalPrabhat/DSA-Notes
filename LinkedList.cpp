// Why LL?
// 1. Dynamic Size - unlike arrays they're not contiguous
// 2. Easy to insert and delete
// 3. Random Access is not possible
// 4. Memory is allocated at runtime
// 5. No memory wastage
// 6. No memory shortage
// 7. No need to give size at the time of declaration
// 8. No need to give the type of data at the time of declaration

// Starting point of the Linked is called Head of the Linked
// And the head of the Linked is stored at the m1 location
// Ending point of the Linked is called Tail of the Linked

// Used in stack, queue mostly
// In real life it's used in a browser

// Node x=Node(2,nullptr);
// Node* y=&x;

// OR

// Node* y=new Node(2,nullptr); // It automatically stores a pointer to the memory location

// int takes 4 bytes
// pointer takes 4 bytes in 32 bit system and 8 bytes in 64 bit system

#include <bits/stdc++.h>
using namespace std;

// use class instead of struct because we want to use OOPs concepts
class Node
{
public:
    int data;
    Node *next;

public:
    // Constructor - It's a special type of function that is called when an object is created
    // It's used to initialize the object
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// What is a node? - A node is a block of memory that stores data and a pointer to the next node
// What is a Linked? - A Linked is a collection of nodes
// What is a singly Linked? - A Linked in which each node has a pointer to the next node

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]); // head is a pointer that points to the first node
    Node *mover = head;            // mover is a pointer that points to the head and the first node points to null as of now
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]); // temp is a pointer that points to the current node
        mover->next = temp;            // the node which mover points to is made to point to the temp node
        // mover=mover->next; // can use this too same as below
        mover = temp; // mover is made to point to the temp node
    }
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int lengthOfLL(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int checkIfPresent(Node *head, int k)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == k)
        {
            return temp->data;
            break;
        }
        temp = temp->next;
    }
    return -1;
}

Node *removeHead(Node *head)
{
    if (head == NULL)
        return nullptr;
    Node *temp = head;
    head = head->next;
    free(temp); // or delete temp;
    return head;
}

Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL; // But here the one element is not deleted
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    free(temp->next); // But after this shouldn't temp should point to null automatically? No
    temp->next = nullptr;
    return head;
}

Node *removeKthNode(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
        return removeHead(head);

    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (i == k - 2)
        {
            Node *temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
            break;
        }
        i++;
        temp = temp->next;
    }
    return head;
}

Node *removeEL(Node *head, int el)
{
    if (head == NULL)
        return head;
    if (head->data == el)
        return removeHead(head);

    Node *temp = head;
    Node *prev = NULL;
    while (temp != nullptr)
    {
        if (temp->data == el)
        {
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertHead(Node *head, int el)
{
    Node *newHead = new Node(el);
    newHead->next = head;
    return newHead;
}

Node *insertTail(Node *head, int el)
{
    if (head == NULL)
        return new Node(el);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newTail = new Node(el);
    temp->next = newTail;
    return head;
}

Node *insertKthNode(Node *head, int k, int el)
{
    if (head == NULL)
        return new Node(el);
    if (k == 1)
        return insertHead(head, el);
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (i == k - 2)
        {
            Node *temp2 = new Node(el);
            temp2->next = temp->next;
            temp->next = temp2;
            break;
        }
        i++;
        temp = temp->next;
    }
    return head;
}

Node *insertBeforeX(Node *head, int x, int el)
{
    if (head == NULL)
        return new Node(el);
    if (head->data == x)
        return insertHead(head, el);

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            Node *temp2 = new Node(el);
            temp2->next = temp;
            prev->next = temp2;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *middleOfLL(Node *head)
{
    // Brute
    // Time complexity - O(n) with two passes
    // Space complexity - O(1)
    // if (head == nullptr || head->next == nullptr)
    //     return head;
    // Node *temp = head;
    // int count = 0;
    // while (temp)
    // {
    //     count++;
    //     temp = temp->next;
    // }
    // int mid = count / 2 + 1;
    // temp = head, count = 0;
    // while (temp)
    // {
    //     count++;
    //     if (count == mid)
    //         break;
    //     temp = temp->next;
    // }
    // return temp;

    // Optimized
    // Tortoise and Hare Algorithm
    // Time complexity - O(n) with one pass
    // Space complexity - O(1)

    if (head == nullptr || head->next == nullptr)
        return head;
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverseLL(Node *head)
{
    // Brute
    // Using stack same as we did in DLL
    // Time complexity - O(n) with two pass
    // Space complexity - O(n) with extra space for stack

    // Optimal
    // Iterative approach
    // Using 3 pointers - prev, temp, front
    // Time complexity - O(n) with one pass
    // Space complexity - O(1)
    // if (head == nullptr || head->next == nullptr)
    //     return head;
    // Node *prev = nullptr;
    // Node *temp = head;
    // while (temp != nullptr)
    // {
    //     Node *front = temp->next;
    //     temp->next = prev;
    //     prev = temp;
    //     temp = front;
    // }
    // return prev;

    // Recursive approach
    // Time complexity - O(n) with one pass
    // Space complexity - O(n) with extra space for recursion stack

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *newHead = reverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

bool hasLoop(Node *head)
{
    // Brute
    // Time complexity - O(n)
    // Space complexity - O(n) with extra space for hash map
    // unordered_map<Node *, int> mpp;
    // Node *temp = head;
    // while (temp)
    // {
    //     if (mpp.find(temp) != mpp.end())
    //         mpp[temp] = 1;
    //     else
    //         return true;
    //     temp = temp->next;
    // }
    // return false;

    // Optimal
    // Tortoise and Hare Algorithm
    // If there is a loop, then the fast pointer will surely meet the slow pointer coz in every iteration the distance between them will be reduced by 1
    // Time complexity - O(n) with one pass
    // Space complexity - O(1)

    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

Node *startOfLoop(Node *head)
{
    // Brute
    // Time complexity - O(n) with two passes
    // Space complexity - O(n)
    // same as hasLoop function

    // Optimal
    // Tortoise and Hare Algorithm
    // Time complexity - O(n) with one pass
    // Space complexity - O(1)
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast == nullptr || fast->next == nullptr)
        return nullptr; // No loop

    slow = head;
    // the distance between the slow and fast pointer will be equal because??
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // or fast
}

int lengthOfLoop(Node *head)
{
    // Brute
    // Time complexity - O(n) with two passes
    // Space complexity - O(n)
    // unordered_map<Node *, int> mpp;
    // Node *temp = head;
    // int count = 0;
    // while (temp)
    // {
    //     if (mpp.find(temp) != mpp.end())
    //     {
    //         count = count - mpp[temp];
    //         return count;
    //     }
    //     mpp[temp] = count;
    //     count++;
    //     temp = temp->next;
    // }
    // return 0;

    // Optimal
    // Tortoise and Hare Algorithm
    // Time complexity - O(n) with one pass
    // Space complexity - O(1)
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int count = 1;
            slow = slow->next;
            while (slow != fast)
            {
                slow = slow->next;
                count++;
            }
            return count;
        }
    }
    return 0; // No loop
}

bool checkPanlindrome(Node *head)
{
    // Brute
    // Using stack
    // just push the elements in the stack and then pop them and check if they are equal or not
    // Time complexity - O(n) with two passes
    // Space complexity - O(n) with extra space for stack

    // Optimal
    // Time complexity - O(n) with two pass
    // Space complexity - O(1)
    if (head == nullptr || head->next == nullptr)
        return true;

    // Middle Of LL
    Node *slow = head;
    Node *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newHead = reverseLL(slow->next);

    // Check if 1st & 2nd half are equal
    Node *first = head;
    Node *second = newHead;
    while (second)
    {
        if (first->data != second->data)
        {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}

Node *oddEven(Node *head)
{
    // Brute
    // Using array just store even and odd and then overwrite the LL
    // Time complexity - O(n) with two passes
    // Space complexity - O(n) with extra space for array

    // Optimal
    // Time complexity - O(n) with one pass
    // Space complexity - O(1)
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;

    Node *odd = head;
    Node *even = head->next;
    Node *temp = even;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = temp;
    return head;
}

Node *removeNthFromEnd(Node *head, int n)
{
    // Brute
    // Time complexity - O(n) with two passes
    // Space complexity - O(1)
    // if (head->next == nullptr && n == 1)
    //     return nullptr;
    // Node *temp = head;
    // int len = 0;
    // while (temp)
    // {
    //     len++;
    //     temp = temp->next;
    // }
    // if (len == n)
    // {
    //     Node *temp = head;
    //     Node *newHead = head->next;
    //     delete temp;
    //     return newHead;
    // }
    // temp = head;
    // int pos = len - n;
    // while (temp)
    // {
    //     pos--;
    //     if (pos == 0)
    //     {
    //         Node *delNode = temp->next;
    //         if (n == 1)
    //             temp->next = nullptr;
    //         else
    //             temp->next = temp->next->next;
    //         delete delNode;
    //         break;
    //     }
    //     temp = temp->next;
    // }
    // return head;

    // Optimal
    // Time complexity - O(n) with one pass
    // Space complexity - O(1)
    if (head->next == nullptr && n == 1)
        return nullptr;

    Node *fast = head;
    int count = 1;
    while (count != n)
    {
        fast = fast->next;
        count++;
    }

    if (fast->next == nullptr)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    Node *slow = head;
    while (fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *temp = slow->next;
    if (n == 1)
        slow->next = nullptr;
    else
        slow->next = slow->next->next;
    delete temp;

    return head;
}

Node *deleteMiddle(Node *head)
{
    // Brute
    // Find the length of the LL and then find the middle element and delete it
    // Time complexity - O(n) with two passes
    // Space complexity - O(1)

    // Optimal
    // Time complexity - O(n) with one pass
    // Space complexity - O(1)
    if (head->next == nullptr)
        return nullptr;

    Node *fast = head;
    Node *slow = head;
    while (fast->next->next != nullptr && fast->next->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp = slow->next;
    if (slow->next->next == nullptr)
        slow->next = nullptr;
    else
        slow->next = slow->next->next;
    delete temp;

    return head;
}

Node *midOfLL(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *merge(Node *leftHead, Node *rightHead)
{

    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (leftHead != nullptr && rightHead != nullptr)
    {
        if (leftHead->data <= rightHead->data)
        {
            temp->next = leftHead;
            temp = temp->next;
            leftHead = leftHead->next;
        }
        else
        {
            temp->next = rightHead;
            temp = temp->next;
            rightHead = rightHead->next;
        }
    }
    if (leftHead)
        temp->next = leftHead;
    else
        temp->next = rightHead;

    return dummyNode->next;
}
Node *ms(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *mid = midOfLL(head);
    Node *leftHead = head;
    Node *rightHead = mid->next;
    mid->next = nullptr;

    leftHead = ms(leftHead);
    rightHead = ms(rightHead);
    return merge(leftHead, rightHead);
}
Node *sortLL(Node *head)
{
    // Brute
    // Using array just store the elements in the array and then sort the array and then overwrite the LL
    // Time complexity - O(nlogn) with two passes
    // Space complexity - O(n) with extra space for array

    // Optimal
    // Time complexity - O(nlogn)
    // Space complexity - O(1) for extra space but O(log n) for recursion stack
    return ms(head);
}

Node *sortLLwith012(Node *head)
{
    // Brute
    // take three counters for 0, 1 and 2 and then overwrite the LL
    // Time complexity - O(n) with two passes
    // Space complexity - O(1)

    // Optimal
    // Time complexity - O(n) with one pass
    // Space complexity - O(1)
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *zero = new Node(-1);
    Node *temp0 = zero;
    Node *one = new Node(-1);
    Node *temp1 = one;
    Node *two = new Node(-1);
    Node *temp2 = two;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }
    zero->next = (temp1->next != nullptr) ? temp1->next : temp2->next;
    one->next = temp2->next;
    two->next = nullptr;

    delete zero;
    delete one;
    delete two;

    return temp0->next;
}

Node *poi(Node *smaller, Node *grater, int d)
{
    Node *temp1 = smaller;
    Node *temp2 = grater;
    while (d > 0)
    {
        temp2 = temp2->next;
        d--;
    }
    while (temp2)
    {
        if (temp1 == temp2)
            return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return nullptr;
}
Node *getIntersectionNode(Node *headA, Node *headB)
{
    // Brute
    // Using hash map just store the elements of one LL in the hash map and then check if the other LL has any of those elements
    // Time complexity - O(n)
    // Space complexity - O(n) the extra space for hash map

    // Better
    // Time complexity - O(n1+n2) with two passes
    // Space complexity - O(1)
    // Node *tempA = headA;
    // int countA = 0;
    // Node *tempB = headB;
    // int countB = 0;
    // while (tempA)
    // {
    //     countA++;
    //     tempA = tempA->next;
    // }
    // while (tempB)
    // {
    //     countB++;
    //     tempB = tempB->next;
    // }
    // if (countA <= countB)
    //     return poi(headA, headB, countB - countA);
    // else
    //     return poi(headB, headA, countA - countB);

    // Optimal
    // suppose the samller LL is x steps ahead...then when it reaches null, then it comes to the larger LL and covers the x steps and until then the larger LL has also covered x steps and now they are at the same distance from the intersection point
    // Time complexity - O(n1+n2) with one pass
    // Space complexity - O(1)
    Node *temp1 = headA;
    Node *temp2 = headB;
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == temp2)
            return temp1;
        if (temp1 == nullptr)
            temp1 = headB;
        else if (temp2 == nullptr)
            temp2 = headA;
    }
    return temp1;
}

int carryHelper(Node *head)
{
    if (head == nullptr)
        return 1;

    int carry = carryHelper(head->next);
    head->data += carry;

    if (head->data < 10)
        return 0;

    head->data = 0;
    return 1;
}
Node *addOne(Node *head)
{
    // Better
    // Time complexity - O(n) with three passes
    // Space complexity - O(1)
    // Node *revHead = reverseLL(head);
    // Node *temp = revHead;
    // int carry = 1;
    // while (temp)
    // {
    //     if (temp->data + carry == 10)
    //     {
    //         temp->data = 0;
    //         carry = 1;
    //     }
    //     else
    //     {
    //         temp->data += carry;
    //         carry = 0;
    //         break;
    //     }
    //     temp = temp->next;
    // }
    // if(carry == 1)
    // {
    //     Node *newNode = new Node(1);
    //     newNode->next = revHead;
    //     return newNode;
    // }
    // return reverseLL(revHead);

    // Optimal
    // Time complexity - O(n) with one pass
    // Space complexity - O(n) for recursion stack

    int carry = carryHelper(head);

    if (carry == 1)
    {
        Node *newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }

    return head;
}

Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Optimal
    // Time complexity - O(max(n1, n2)) with one pass
    // Space complexity - O(1) for extra space but O(n) for returning the ans
    Node *sumNode = new Node(-1);
    Node *head = sumNode;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr)
    {
        int sum = carry;
        if (l1)
            sum += l1->data;
        if (l2)
            sum += l2->data;

        Node *newNode = new Node(sum % 10);
        carry = sum / 10;

        sumNode->next = newNode;
        sumNode = sumNode->next;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry)
    {
        Node *newNode = new Node(carry);
        sumNode->next = newNode;
        sumNode = sumNode->next;
    }
    return head->next;
}



int main()
{
    vector<int> arr = {4, 5, 6};

    // Node y= Node(arr[0],nullptr); // Simply an object
    // cout<<y.data<<"\n";
    // cout<<y.next<<"\n";

    // Node* y=new Node(arr[0],nullptr); // Pointer to the memory location
    // cout<<y<<"\n";

    Node *head = convertArr2LL(arr);
    // cout<<head->data<<"\n";

    // Node* temp=head;
    // while(temp)
    // {
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }

    // cout<<lengthOfLL(head)<<"\n";

    // cout<<checkIfPresent(head,8)<<"\n";

    printLL(head);
    head = addOne(head);
    printLL(head);
    // cout << addOne(head) << "\n";
}