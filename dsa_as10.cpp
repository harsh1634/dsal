#include<iostream>
using namespace std;

class maxheap
{
    int a[50],limit;
    public:
    maxheap()
    {
        limit = 0;                          //limit acts as a pointer to last element, useful for insertion
    }

    void insert(int data)
    {
        if(limit<50)
        {
            limit = limit +1;
            a[limit] = data;                //inserting at the end
            int i = limit;
            while(a[i/2] < a[i] && i>1)
            {
                int temp = a[i/2];
                a[i/2] = a[i];
                a[i] = temp;
                i = i/2;
            }
        }
        else
        {
            cout<<"\nHeap full!";
        }
    }

    void display_max()
    {
        if(limit != 0)
            cout<<"\nThe maximum marks obtained are: "<<a[1];
        else
            cout<<"\nNo data inserted yet";     //if heap is empty
    }
};

class minheap
{
    int a[50],limit;
    public:
    minheap()
    {
        limit = 0;
    }

    void insert(int data)
    {
        if(limit<50)
        {
            limit = limit +1;
            a[limit] = data;                //inserting at the end
            int i = limit;
            while(a[i/2] > a[i] && i>1)
            {
                int temp = a[i/2];
                a[i/2] = a[i];
                a[i] = temp;
                i = i/2;
            }
        }
        else
        {
            cout<<"\nHeap full!";
        }
    }

    void display_min()
    {
        if(limit != 0)
            cout<<"\nThe minimum marks obtained are: "<<a[1];
        else
            cout<<"\nNo data inserted yet";     //if heap is empty
    }
};

int main()
{
    maxheap maxh;
    minheap minh;
    int ch;
    do
    {
        cout<<"\n\nOperations:";
        cout<<"\n1.Insert\n2.Display\n3.Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: 
            {
                int marks;
                cout<<"\nEnter the marks: ";
                cin>>marks;
                maxh.insert(marks);
                minh.insert(marks);
                break;
            }
            case 2: 
            {
                maxh.display_max();
                cout<<"\n";
                minh.display_min();
            }
            break;
            case 3:
            break;
            default: cout<<"\nInvalid choice!";
            break;
        }
    } while (ch!=3);
    return 0;
}