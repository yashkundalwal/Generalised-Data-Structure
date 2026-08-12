#include<iostream>

using namespace std;

#pragma pack(1)
template<class T>
struct node
{
    T data;
    struct node * next;
};

#pragma pack(1)
template<class T>
class SinglyCL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int iCount;
    public:
        SinglyCL();
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
SinglyCL<T> :: SinglyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void SinglyCL<T> :: Display()
{
    struct node<T> * temp = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }

    temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;

    }while(last->next != temp);
    cout<<"\n";
}

template<class T>
int SinglyCL<T> :: Count()
{
    return this->iCount;
}

template<class T>
void SinglyCL<T> :: InsertFirst(T iNo)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;

        this->first = newn;
    }

    (this->last)->next = this->first;

    iCount++;
}

template<class T>
void SinglyCL<T> :: InsertLast(T iNo)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        (this->last)->next = newn;
        
        this->last = newn;
    }
    (this->last)->next = this->first;

    iCount++;
}

template<class T>
void SinglyCL<T> :: InsertAtPos(T iNo, int iPos)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    int i = 0;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if((iPos < 1) || (iPos > this->iCount + 1))
    {
        cout<<"Invalid Position"<<endl;
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
        temp = this->first;

        for(i = 1 ; i < iPos - 1 ; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;

        temp->next = newn;

        this->iCount++;
    }
}

template<class T>
void SinglyCL<T> :: DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
    }
    else
    {
        first = first->next;

        delete last->next;

        last->next = first;
    }
    this->iCount--;
}

template<class T>
void SinglyCL<T> :: DeleteLast()
{
    struct node<T> * temp = NULL;

    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
    }
    else
    {
        temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete temp->next;
        
        last = temp;

        last->next = first;
    }

    this->iCount--;
}

template<class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
    struct node<T> * temp = NULL;
    struct node<T> * target = NULL;

    int i = 0;

    if((iPos < 1) || (iPos > this->iCount))
    {
        cout<<"Invalid Position"<<endl;
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
        temp = this->first;

        for(i = 1 ; i < iPos - 1 ; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp -> next = target -> next;

        delete target;

        this->iCount--;
    }
}




int main()
{
    SinglyCL <int>sobj;

    return 0;
}