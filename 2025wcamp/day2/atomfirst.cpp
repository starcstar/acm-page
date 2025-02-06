#include <iostream>
#include <cstring>
using namespace std;

typedef int Status;
#define RET_OK 1
#define RET_FAIL -1

#define ORDER_MAX_LEN 3

typedef struct BiNode
{
    char val;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

typedef struct StackNode
{
    BiTree T;
    int tagIndex; // r, L, R
} StackNode;

typedef struct Stack
{
    int top;
    StackNode data[100];
} Stack;

char gInputStr[100];
int gIndex = 0;
char gTraverseOrder[20]; // rLR, LrR, LRr

void InitStack(Stack &S)
{
    S.top = 0;
}

void Push(Stack &S, BiTree T, int tagIndex)
{
    S.data[S.top].T = T;
    S.data[S.top].tagIndex = tagIndex;
    S.top++;
}

Status Pop(Stack &S, BiTree &T, int &tagIndex)
{
    if (S.top == 0)
        return RET_FAIL;
    S.top--;
    T = S.data[S.top].T;
    tagIndex = S.data[S.top].tagIndex;
    return RET_OK;
}

bool IsEmpty(Stack S)
{
    return S.top == 0;
}
void TraverseBiTree(BiTree T, char order[])
{
    Stack S;
    InitStack(S);
    BiTree p = T;
    int tagIndex;

    Push(S, p, 0);
    while (!IsEmpty(S))
    {
        Pop(S, p, tagIndex);

        if (tagIndex + 1 < ORDER_MAX_LEN)
        {
            Push(S, p, tagIndex + 1);
        }
        switch (order[tagIndex])
        {
        case 'L':
            if (p->lchild)
                Push(S, p->lchild, 0);
            break;
        case 'R':
            if (p->rchild)
                Push(S, p->rchild, 0);
            break;
        case 'r':
            cout << p->val << " ";
            break;
        default:
            cerr << "invaild order!";
            exit(-1);
        }
    }
}

BiTree CreateBiTree()
{
    BiTree T;

    if (gInputStr[gIndex] == '#')
    {
        T = NULL;
        gIndex++;
    }
    else
    {
        T = (BiTree)malloc(sizeof(BiNode));
        T->val = gInputStr[gIndex];
        gIndex++;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }
    return T;
}

void DestroyBiTree(BiTree T)
{
    if (T)
    {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
    }
}

void PreOrder(BiTree T)
{
    if (T)
    {
        cout << T->val << " ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T)
{
    if (T)
    {
        InOrder(T->lchild);
        cout << T->val << " ";
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T)
{
    if (T)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout << T->val << " ";
    }
}

int main()
{
    strcpy(gInputStr, "ABD#G###CE##F##");
    gIndex = 0;
    BiTree T = CreateBiTree();

    cout << "PreOrder: ";
    cout << "\n";
    strcpy(gTraverseOrder, "rLR");
    TraverseBiTree(T, gTraverseOrder);
    cout << "\n";
    PreOrder(T);
    cout << "\n";

    cout << "InOrder: ";
    cout << "\n";
    strcpy(gTraverseOrder, "LrR");
    TraverseBiTree(T, gTraverseOrder);
    cout << "\n";
    InOrder(T);
    cout << "\n";

    cout << "PostOrder: ";
    cout << "\n";
    strcpy(gTraverseOrder, "LRr");
    TraverseBiTree(T, gTraverseOrder);
    cout << "\n";
    PostOrder(T);
    cout << "\n";

    DestroyBiTree(T);

    return 0;
}