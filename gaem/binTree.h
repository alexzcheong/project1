#include <iostream>
using namespace std;

class treeNode {
public:
    int data;
    treeNode* left;
    treeNode* right;
};

treeNode* newNode(int data);
treeNode* sortedArrBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    treeNode* root = newNode(arr[mid]);
    root->left = sortedArrBST(arr, start, mid - 1);
    root->right = sortedArrBST(arr, mid + 1, end);
    return root;
}

treeNode* newNode(int data)
{
    treeNode* node = new treeNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inOrder(treeNode* node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}