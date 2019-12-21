#include <iostream>
#include "binaryTreeNode.h"

using namespace std;

int height(binaryTreeNode<char> *tree)
{
    if (tree == NULL)
        return 0;
    else
        return 1 + max(height(tree->left), height(tree->right));
}

void addNode(binaryTreeNode<char> *root, bool left, char value)
{
    if (left)
    {
        root->left = new binaryTreeNode<char>;
        root->left->info = value;
        root->left->left = NULL;
        root->left->right = NULL;
    }
    else
    {
        root->right = new binaryTreeNode<char>;
        root->right->info = value;
        root->right->left = NULL;
        root->right->right = NULL;
    }
}

void inorder(binaryTreeNode<char> *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->info << " ";
        inorder(root->right);
    }
}

void preorder(binaryTreeNode<char> *root)
{
    if (root != NULL)
    {
        cout << root->info << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(binaryTreeNode<char> *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->info << " ";
    }
}

int main()
{
    binaryTreeNode<char> *root = new binaryTreeNode<char>;

    root->info = 'A';
    addNode(root, true, 'B');
    addNode(root, false, 'F');
    addNode(root->left, true, 'C');
    addNode(root->left, false, 'E');
    addNode(root->left->left, true, 'D');
    addNode(root->right, false, 'G');

    cout << "Height = " << height(root) << endl;
    cout << "Inorder = ";
    inorder(root);
    cout << "\nPreorder = ";
    preorder(root);
    cout << "\nPostorder = ";
    postorder(root);

    return 0;
}
