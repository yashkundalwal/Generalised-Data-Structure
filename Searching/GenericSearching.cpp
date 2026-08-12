#include<iostream>

using namespace std;

#pragma pack(1)
template<class T>
class Searching
{
    private:
        T * Arr;
        int iSize;

    public:
        Searching(int iNo);
        ~Searching();

        void Accept();
        void Display();

        bool LinearSearch(T iNo);
        bool BidirectionalSearch(T iNo);

};

template<class T>
Searching<T> :: Searching(int iNo)
{
    this->iSize = iNo;
    this->Arr = new int[iSize];
}

template<class T>
Searching<T> :: ~Searching()
{
    delete []Arr;
}

template<class T>
void Searching<T> :: Accept()
{
    int i = 0;
    cout<<"Enter the Elements: "<<endl;

    for(i = 0 ; i < iSize ; i++)
    {
        cin>> Arr[i];
    }
}

template<class T>
void Searching<T> :: Display()
{
    int i = 0;
    cout<<"Elements of the Array are: "<<endl;

    for(i = 0 ; i < iSize ; i++)
    {
        cout<< Arr[i]<<endl;
    }
}

template<class T>
bool Searching<T> :: LinearSearch(T iNo)
{
    bool bFlag = false;
    int i = 0;

    for(i = 0 ; i < iSize ; i++)
    {
        if(Arr[i] == iNo)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

template<class T>
bool Searching<T> :: BidirectionalSearch(T iNo)
{
    bool bFlag = false;

    int iStart = 0;
    int iEnd = 0;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == iNo || Arr[iEnd] == iNo)
        {
            bFlag = true;
            break;
        }

        iStart++;
        iEnd--;
    }

    return bFlag;
}

int main()
{
    Searching <int>sobj(5);

    return 0;
}