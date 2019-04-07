/*
* @Author: WanFeng
* @Date:   2019-04-07 23:39:31
* @Last Modified by:   WanFeng
* @Last Modified time: 2019-04-08 00:09:15
*/
//二叉树的链式实现
#include <stdio.h>
#include <stdlib.h>
typedef struct BTNode
{
    char data;
    struct BTNode *pLchild;//左子树
    struct BTNode *pRchild;//右子树
} BTNODE, *PBTNODE;

PBTNODE createBTree(void);
void preTraverseBTree(PBTNODE);
void inTraverseBTree(PBTNODE);
void postTraverseBTree(PBTNODE);
int main(int argc, char const *argv[])
{
    PBTNODE pT = createBTree();
    printf("先序遍历：\n");
    preTraverseBTree(pT);
    printf("\n中序遍历：\n");
    inTraverseBTree(pT);
    printf("\n后序遍历：\n");
    postTraverseBTree(pT);
    return 0;
}

PBTNODE createBTree(void)
{
    PBTNODE pT = (PBTNODE)malloc(sizeof(BTNODE));
    PBTNODE pL = (PBTNODE)malloc(sizeof(BTNODE));
    PBTNODE pR = (PBTNODE)malloc(sizeof(BTNODE));

    pT->data = 'A';
    pL->data = 'B';
    pR->data = 'C';
    pT->pLchild = pL;
    pT->pRchild = pR;

    pL->pLchild = NULL;
    pL->pRchild = NULL;
    pR->pLchild = NULL;
    pR->pRchild = NULL;
    return	pT;
}

//先序遍历
void preTraverseBTree(PBTNODE pT)
{
    if(pT != NULL)
    {
        printf("%c ", pT->data);
        if(pT != NULL)
        {
            preTraverseBTree(pT->pLchild);
        }
        if(pT != NULL)
        {
            preTraverseBTree(pT->pRchild);
        }
    }

}

//中序遍历
void inTraverseBTree(PBTNODE pT)
{
    if(pT != NULL)
    {
        if(pT != NULL)
        {
            inTraverseBTree(pT->pLchild);
        }
        printf("%c ", pT->data);
        if(pT != NULL)
        {
            inTraverseBTree(pT->pRchild);
        }
    }
}

//后序遍历
void postTraverseBTree(PBTNODE pT)
{
    if(pT != NULL)
    {
        if(pT != NULL)
        {
            postTraverseBTree(pT->pLchild);
        }
        if(pT != NULL)
        {
            postTraverseBTree(pT->pRchild);
        }
        printf("%c ", pT->data);
    }
}
