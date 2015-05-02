#ifndef __FUNCTION_H__  
#define __FUNCTION_H__  
#include <iostream>  
  
using namespace std;  
struct tree  
{  
    int nodeValue;  
    tree *left;  
    tree *right;  
};  
  
tree * Build_Recursive(int a[], int *pPrevOrderEnd, int *pInOrderStart, int *pInOrderEnd)  
{  
    //在先序遍历序列中取出第一个元素即为根节点元素  
    int value = a[0];  
    //构造根节点  
    tree *root = new tree;  
    root->nodeValue = value;  
    root->left = root->right = NULL;  
    //递归结束的情况，即只剩一个叶子节点  
    if(a == pPrevOrderEnd)  
    {  
        if(pInOrderStart == pInOrderEnd && *a == *pInOrderStart)  
            return root;  
        else  
            throw std::exception();  
    }  
    //在中序遍历序列中找出根节点的位置  
    int *pInOrderCursor = pInOrderStart;  
    while(pInOrderCursor < pInOrderEnd && *pInOrderCursor != value)  
    {  
        pInOrderCursor++;  
    }  
    if(pInOrderCursor == pInOrderEnd && *pInOrderCursor != value)  
    {  
        throw std::exception();  
    }  
    //取得左子树的长度以及在先序遍历中取得左子树的起始位置  
    int leftTreeLen = pInOrderCursor - pInOrderStart;  
    int *pPrevOrderLeftTreeEnd = a + leftTreeLen;  
    //如果左子树存在，则递归左子树  
    if(leftTreeLen > 0)  
    {  
        root->left = Build_Recursive(a+1, pPrevOrderLeftTreeEnd,  
                                      pInOrderStart, pInOrderCursor-1);  
    }  
    //如果右子树存在，则递归右子树  
    if((pPrevOrderEnd-a) > leftTreeLen)  
    {  
        root->right = Build_Recursive(pPrevOrderLeftTreeEnd+1, pPrevOrderEnd,  
                                       pInOrderCursor+1, pInOrderEnd);  
    }  
  
    return root;  
}  
  
tree * BulidBinaryTree(int *szPrevOrder, int *szInOrder, int nodeNum)  
{  
    if(szPrevOrder == NULL || szInOrder == NULL)  
        return NULL;  
    return Build_Recursive(szPrevOrder, szPrevOrder+nodeNum-1,  
                           szInOrder, szInOrder+nodeNum-1);  
}  
  
/*先序遍历*/  
void PrevOrder(tree *root)  
{  
    if(root == NULL)  
        return;  
    //根  
    cout<<root->nodeValue<<' ';  
    //左子树  
    if(root->left != NULL)  
        PrevOrder(root->left);  
    //右子树  
    if(root->right != NULL)  
        PrevOrder(root->right);  
}  
  
/*中序遍历*/  
void InOrder(tree *root)  
{  
    if(root == NULL)  
        return;  
    //左子树  
    if(root->left != NULL)  
        InOrder(root->left);  
    //根  
    cout<<root->nodeValue<<' ';  
    //右子树  
    if(root->right != NULL)  
        InOrder(root->right);  
}  
  
/*后序遍历*/  
void PostOrder(tree *root)  
{  
    if(root == NULL)  
        return;  
    //左子树  
    if(root->left != NULL)  
        PostOrder(root->left);  
    //右子树  
    if(root->right != NULL)  
        PostOrder(root->right);  
    //根  
    cout<<root->nodeValue<<' ';  
}  
  
#endif  