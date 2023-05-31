//separate insertion not done yet

#include<iostream>
using namespace std;

class node
{
    node *left;
    char data[20];
    node *right;
    public:
    node()
    {
        left = NULL;
        right = NULL;
    }
    friend class btree;
};

class btree
{
    node *root;
    public:
    btree()
    {
        root = NULL;
    }

    /*void insert()
    {
        node *travel = root;
        node *newn = new node();
        if(travel == NULL)
        {
            cout<<"\nEnter book name: ";
            cin>>newn->data;
            root = newn;
        }
        else
        {
            cout<<"\nEnter the chapter name: ";
            cin>>newn->data;
            if(travel->left == NULL)
            {
                travel->left = newn;
                cout<<"\nNew chapter created!";
            }
        }
    }*/

    void display()
    {
        node *chp = NULL;
        node *secp = NULL;
        node *subsecp = NULL;
        if(root == NULL)
        {
            cout<<"\nBook not created yet!";
        }
        else
        {
            cout<<"\n\nBook name: "<<root->data;
            chp = root->left;
            while(chp!=NULL)
            {
                cout<<"\n\t"<<chp->data;
                secp = chp->left;
                while(secp!=NULL)
                {
                    cout<<"\n\t\t"<<secp->data;
                    subsecp = secp->left;
                    while(subsecp!=NULL)
                    {
                        cout<<"\n\t\t\t"<<subsecp->data;
                        subsecp = subsecp->right;
                    }
                    secp = secp->right;
                }
                chp = chp->right;
            }
        }
    }

    void create()
    {
        int ch_count;
        node *temp = new node();
        cout<<"\nEnter the name of book: ";
        cin>>temp->data;
        root = temp;
        cout<<"\nHow many chapters do you want to create? ";
        cin>>ch_count;
        for(int i=0;i<ch_count;i++)
        {
            ch_ins(temp,i);
        }
    }

    void ch_ins(node *temp,int i)
    {
        int sec_count;
        node *travel = temp->left;
        node *newn = new node();
        cout<<"\nEnter the name of chapter "<<i+1<<" : ";
        cin>>newn->data;
        if(travel == NULL)
        {
            temp->left = newn;
        }
        else
        {
            while(travel->right!=NULL)
                travel=travel->right;
            travel->right = newn;
        }

        cout<<"\nHow many sections do you want in chapter "<<i+1<<" : ";
        cin>>sec_count;
        for(int j=0;j<sec_count;j++)
        {
            sec_ins(newn,j);
        }
    }

    void sec_ins(node *temp, int j)
    {
        node *travel = temp->left;
        int subsec_count;
        node *newn = new node();
        cout<<"\nEnter the name of section "<<j+1<<" : ";
        cin>>newn->data;
        if(travel == NULL)
        {
            temp->left = newn;
        }
        else
        {
            while(travel->right!=NULL)
                travel=travel->right;
            travel->right = newn;
        }

        cout<<"\nHow many sub-sections do you want in section "<<j+1<<" : ";
        cin>>subsec_count;
        for(int k=0;k<subsec_count;k++)
        {
            subsec_ins(newn,k);
        }        
    }

    void subsec_ins(node *temp, int j)
    {
        node *travel = temp->left;
        node *newn = new node();
        cout<<"\nEnter the name of subsection "<<j+1<<" : ";
        cin>>newn->data;
        if(travel == NULL)
        {
            temp->left = newn;
        }
        else
        {
            while(travel->right!=NULL)
                travel=travel->right;
            travel->right = newn;
        }     
    }
};

int main()
{
    btree b;
    int ch;
    do
    {
        cout<<"\n\nOperations";
        cout<<"\n1.Create\n2.Insert\n3.Display\n4.Exit";
        cout<<"\nEnter the choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: b.create();
            break;
            case 2: 
            break;
            case 3: b.display();
            break;
            case 4:
            break;
            default: cout<<"\nInvalid choice!";
            break;
        }
    } while(ch!=4);
    return 0;
}