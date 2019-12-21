#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
template <class T>
struct binaryTreeNode
{
    T info;
    binaryTreeNode<T> *left;
    binaryTreeNode<T> *right;
};
#endif // BINARYTREENODE_H
