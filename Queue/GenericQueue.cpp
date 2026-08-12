// Generic Queue

#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
};

template<class T>
class Queue
{
    private:
        struct node<T> *first;
        int iCount;

    public:
        Queue();
        void Enqueue(T iNo);         //Insert Last
        T Dequeue();                 //DeleteFirst
        void Display();
        int Count();        
};

template<class T>
Queue<T> :: Queue()
{
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void Queue<T> :: Enqueue(T iNo)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new struct node<T>();

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL)
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
    }

    iCount++;
}

template<class T>
T Queue<T> :: Dequeue()  
{
    T iValue = 0;

    struct node<T> * temp = NULL;

    if(first == NULL)
    {
        cout<<"Queue is Empty \n";
        return -1;
    }
    else
    {
        iValue = first->data;

        temp = first;

        first = first->next;

        delete temp;

        iCount--;

        return iValue;
    }

    return 0;
}               
 
template<class T>
void Queue<T> :: Display()
{
    struct node<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <- ";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int Queue<T> :: Count()
{
    return iCount;
}

int main()
{   
    Queue <int>sobj;
    int iRet = 0;

    sobj.Enqueue(11);
    sobj.Enqueue(21);
    sobj.Enqueue(51);
    sobj.Enqueue(101);
    
    sobj.Display();

    iRet = sobj.Count();

    cout<<"Elements of the Queue are: "<<iRet<<endl;

    iRet = sobj.Dequeue();

    cout<<"Removed Element is : "<<iRet<<"\n";

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Elements of the Queue are: "<<iRet<<endl;

    return 0;
}