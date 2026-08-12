#include<iostream>

using namespace std;

#pragma pack(1)
template<class T>
struct node
{
    int data;
    struct node *next;
};

#pragma pack(1)
template<class T>
class SinglyLL
{
    private: 
        struct node<T> * first;
        int iCount;

    public:
        SinglyLL();

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
SinglyLL<T> :: SinglyLL()
{
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void SinglyLL<T> :: Display()
{
    struct node<T> * temp = NULL;
    temp = this->first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL "<<endl;
}

template<class T>
int SinglyLL<T> :: Count()
{
    return this->iCount;
}

template<class T>
void SinglyLL<T> :: InsertFirst(T iNo)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if((this->first) == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;

        this->first = newn;
    }
    
    this->iCount++;                                    // Important
}

template<class T>
void SinglyLL<T> :: InsertLast(T iNo)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if((this->first) == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    
    this->iCount++;                                    // Important


}

template<class T>
void SinglyLL<T> :: InsertAtPos(T iNo, int iPos)
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
void SinglyLL<T> :: DeleteFirst()
{
    struct node<T> * temp = NULL;

    temp = this->first;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;

        delete temp;
    }

    this->iCount--;
}

template<class T>
void SinglyLL<T> :: DeleteLast()
{
    struct node<T> * temp = NULL;

    temp = this->first;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this -> first;

        while((temp->next)->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;

        temp->next = NULL;
    }

    this->iCount--;
}

template<class T>
void SinglyLL<T> :: DeleteAtPos(int iPos)
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
    SinglyLL <int>sobj;

    return 0;
}