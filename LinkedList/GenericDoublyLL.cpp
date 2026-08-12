#include<iostream>
using namespace std;

#pragma pack(1)
template<class T>
struct node
{
    T data;
    struct node * next;
    struct node * prev;
};

#pragma pack(1)
template<class T>
class DoublyLL
{
    private:
        struct node<T> * first;
        int iCount;

    public: 
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template<class T>
DoublyLL<T> :: DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void DoublyLL<T> :: Display()
{
    struct node<T> * temp = NULL;

    temp = first;

    if(temp == NULL)
    {
        return ;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

template<class T>
void DoublyLL<T> :: InsertFirst(T iNo)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL))
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    }

    iCount++;
}

template<class T>
void DoublyLL<T> :: InsertLast(T iNo)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL))
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    
    iCount++;
}

template<class T>
void DoublyLL<T> :: InsertAtPos(T iNo, int iPos)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    int i = 0;

    if((iPos<0) || (iPos > iCount+1))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(iPos == 1)
    {
        this->InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        this->InsertLast(iNo);
    }
    else
    {
        newn = new struct node<T>;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        (temp->next)->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template<class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(first == NULL)
    {
        return ;
    }
    else if((first->next) == NULL)
    {
        delete first;
    }
    else
    {
        first = first->next;

        delete first->prev;

        first->prev = NULL;
    }

    iCount--;
}

template<class T>
void DoublyLL<T> :: DeleteLast()
{
    struct node<T> * temp = NULL;

    if(first == NULL)
    {
        return ;
    }
    else if((first->next) == NULL)
    {
        delete first;
    }
    else
    {
        temp = first;

        while(((temp->next)->next) != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;

        temp->next = NULL;
    }

    iCount--;
}

template<class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    struct node<T> * temp = NULL;

    int i = 0;

    if((iPos<0) || (iPos > iCount))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(iPos == 1)
    {
        this->DeleteFirst();
    }
    else if(iPos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp->next;
        }

        temp->next = (temp->next)->next;

        delete (temp->next)->prev;

        (temp->next)->prev = temp;

        iCount--;
    }
}

int main()
{
    DoublyLL <int>dobj;
    
    return 0;
}