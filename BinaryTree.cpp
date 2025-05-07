// There are 5 types of BT
// 1. Full Binary Tree - every node has 0 or 2 children
// 2. Complete Binary Tree - all levels are completely filled except possibly the last level, which is filled from left to right
// 3. Perfect Binary Tree - all leaf nodes are at the same level
// 4. Balanced Binary Tree - the height of tree can be at most log(n)
// 5. Degenerate Binary Tree (or pathological tree)

// Traversal Techniques - breadth first search(BFS) and depth first search(DFS)

// DFS - Inorder, Preorder, Postorder
// Inorder - left, root, right
// Preorder - root, left, right
// Postorder - left, right, root

// BFS - go line by line / level order traversal - uses queue data structure

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void preOrder(Node *root)
{
    // Time Complexity - O(n)
    // Space Complexity - O(h) - h is the height of the tree, in case of skewed tree it can be O(n) - auxiliary space
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
vector<int> preorderTraversal(Node *root)
{
    // Time Complexity - O(n)
    // Space Complexity - O(n) - auxiliary space
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        ans.emplace_back(temp->data);
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
    return ans;
}

void inOrder(Node *root)
{
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        vector<int> level;
        for (int i = 0; i < s; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            level.emplace_back(node->data);
        }
        ans.emplace_back(level);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    preOrder(root); // Output: 1 2 5 3
}
