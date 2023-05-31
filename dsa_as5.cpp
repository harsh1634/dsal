/*Threaded Binary Tree*/

#include<iostream>
using namespace std;

class node
{
    node *left,*right;
    int data;
    bool lthread,rthread;

    public:
    node()
    {
        left = right = NULL;
        data = 0;
        lthread = rthread = true;
    }
    friend class tbt;
};

class tbt
{
    node *root;

    public:
    tbt()
    {
        root = NULL;
    }

    void insert()
    {
        node *travel = root;
        node *parent = NULL;
        node *newn = new node();
        cout<<"\nEnter the data you want to insert: ";
        cin>>newn->data;

        while(travel!=NULL)
        {
            parent = travel;
            if(newn->data > travel->data)
            {
                if(travel->rthread == false)
                    travel = travel->right;
                else
                    break;
            }
            else
            {
                if(travel->lthread == false)
                    travel = travel->left;
                else
                    break;
            }
        }
        
        if(parent == NULL)
        {
            root = newn;
            cout<<"\nRoot node created!";
        }

        else if(newn->data > parent->data)
        {
            newn->right = parent->right;
            newn->left = parent;
            parent->rthread = false;
            parent->right = newn;
            cout<<"\nNode inserted as right child of "<<parent->data;
        }

        else
        {
            newn->right = parent;
            newn->left = parent->left;
            parent->lthread = false;
            parent->left = newn;
            cout<<"\nNode inserted as left child of "<<parent->data;            
        }
    }

    node *inorder_succ(node *rt)
    {
        if(rt->rthread == true)
            return rt->right;
        
        rt = rt->right;
        while(rt->lthread == false)
            rt = rt->left;
        return rt;
    }

    void inorder()
    {
        if(root == NULL)
            cout<<"\nTree is empty!";
        else
        {
            node *travel = root;
            while(travel->lthread == false)
                travel = travel->left;
            while(travel!=NULL)
            {
                cout<<travel->data<<" ";
                travel = inorder_succ(travel);
            }
        }
    }
};

int main()
{
    int ch;
    tbt t;
    do
    {
        cout<<"\n\nTBT Operations";
        cout<<"\n1.Inser\n2.Display (inorder)\n3.Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: t.insert();
            break;
            case 2: t.inorder();
            break;
            case 3:
            break;
            default: cout<<"\nInvalid Choice!";
            break;
        }
    } while (ch!=3);
    return 0;
}
