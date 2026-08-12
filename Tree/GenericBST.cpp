// Generic(Conver it)

#include<iostream>

using namespace std;


#pragma pack(1)
template<class T>
struct node
{
    T data;
    struct node * lchild;
    struct node * rchild;
};

#pragma pack(1)
template<class T>
class tree
{
    private:
        struct node<T> * first;
        int iCount;
        int iCountLeaf;
        int iCountParent;

    public:
        tree();
        void Insert(T iNo);
        void Inorder();
        void Inorder(struct node<T> * temp);
        void Preorder();
        void Preorder(struct node<T> * temp);
        void Postorder();
        void Postorder(struct node<T> * temp);
        bool Search(T iNo);
        int Count();
        int CountLeaf();
        int CountLeaf(struct node<T> * temp);
        int CountParent();
        int CountParent(struct node<T> * temp);
};

template<class T>
tree<T> :: tree()
{
    this->first = NULL;
    this->iCount = 0;
    this->iCountLeaf = 0;
    this->iCountLeaf = 0;
}

template<class T>
void tree<T> :: Insert(T iNo)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
        iCount++;
    }
    else
    {
        temp = first;

        while(1)
        {
            if(iNo > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    iCount++;
                    break;
                }
                temp = temp->rchild;
            }
            else if(iNo < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    iCount++;
                    break;
                }
                temp = temp->lchild;
            }
            else if(iNo == temp->data)
            {
                printf("Unable to Insert Duplicate Element\n");
                break;
            }
        }
    }

}

template<class T>
void tree<T> :: Inorder()
{
    Inorder(first);
}

template<class T>
void tree<T> :: Inorder(struct node<T> * temp)
{
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        cout<<temp->data<<endl;
        Inorder(temp->rchild);
    }
}

template<class T>
void tree<T> :: Preorder()
{
    Preorder(first);
}

template<class T>
void tree<T> :: Preorder(struct node<T> * temp)
{
    if(temp != NULL)
    {
        cout<<temp->data<<endl;
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

template<class T>
void tree<T> :: Postorder()
{
    Postorder(first);
}

template<class T>
void tree<T> :: Postorder(struct node<T> * temp)
{
    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout<<temp->data<<endl;
    }
}

template<class T>
bool tree<T> :: Search(T iNo)
{
    bool bFlag = false;

    struct node<T> * temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        if(iNo == temp -> data)
        {
            bFlag = true;
            break;
        }
        else if(iNo > temp -> data)
        {
            temp = temp->rchild;
        }
        else if(iNo < temp -> data)
        {
            temp = temp->lchild;
        }
    }

    return bFlag;
}

template<class T>
int tree<T> :: Count()
{
    return iCount;
}

template<class T>
int tree<T> :: CountLeaf()
{
    iCountLeaf = 0;
    CountLeaf(first);

    return iCountLeaf;
}

template<class T>
int tree<T> :: CountLeaf(struct node<T> * temp)
{
    if(temp != NULL)
    {
        if(((temp)->lchild == NULL) && ((temp)->rchild == NULL))
        {
            iCountLeaf++;
        }
        CountLeaf(temp->lchild);
        CountLeaf(temp->rchild);
    }

    return iCountLeaf;
}

template<class T>
int tree<T> :: CountParent()
{
    iCountParent = 0;
    CountParent(first);

    return iCountParent;
}

template<class T>
int tree<T> :: CountParent(struct node<T> * temp)
{
    if(temp != NULL)
    {
        if(((temp)->lchild != NULL) || ((temp)->rchild != NULL))
        {
            iCountParent++;
        }
        CountParent(temp->lchild);
        CountParent(temp->rchild);
    }

    return iCountParent;
}

int main()
{
    tree <int>tobj;

    return 0;
}