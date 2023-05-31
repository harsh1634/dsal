#include<iostream>
using namespace std;

class node
{
    node *left;
    int data;
    node *right;

    public:
    node()
    {
        left = NULL;
        data = 0;
        right = NULL;
    }
    friend class bst;
};

class bst
{
    node *root;
    
    public:
    bst()
    {
        root = NULL;
    }

    void insert()
    {
        node *travel = root;
        node *newn = new node();
        cout<<"\nEnter the data you want to insert: ";
        cin>>newn->data;
        int inserted = 0;
        if(root == NULL)
        {
            root = newn;
            cout<<"\nRoot created!";
        }
        else
        {
            do
            {
                if(travel->data > newn->data)
                {
                    if(travel->left==NULL)          
                    {
                        travel->left = newn;
                        cout<<"\nNode inserted as left child of "<<travel->data;
                        inserted = 1;
                    }
                    else
                        travel = travel->left;
                }
                else
                {
                    if(travel->right==NULL)
                    {
                        travel->right = newn;
                        cout<<"\nNode inserted as right child of "<<travel->data;
                        inserted = 1;
                    }
                    else
                        travel = travel->right;
                }
            } while (inserted!=1);
        }
    }

    void height()
    {
        if(root == NULL)
            cout<<"\nTree is empty";
        else
        {
            int h = ht(root);
            cout<<"\nHeight of the tree is: "<<h;
        }
    }

    int ht(node *rt)                                //recursive func to calculate height
    {
        if(rt == NULL)
            return 0;
        else
        {
            int height = max(ht(rt->left),ht(rt->right)) + 1;
            return height;
        }
    }

    void minimum()
    {
        node *travel = root;
        if(travel == NULL)
            cout<<"\nTree is empty!";
        else
        {
            while(travel->left!=NULL)               //goto the leftmost node
                travel = travel->left;
            cout<<"\nThe minimum element is: "<<travel->data;
        }
    }

    /* below code is just to print mirrored tree and not logically mirror it
    void mirror_print()
    {
        if(root == NULL)
            cout<<"\nTree is empty!";
        else
            mirror_dummy(root);
    }

    void mirror_dummy(node *rt)
    {
        if(rt!=NULL)
        {
            mirror_dummy(rt->right);
            cout<<rt->data<<" ";
            mirror_dummy(rt->left);
        }
    }*/

    void search()
    {
        int key;
        int cntr = 0;
        node *travel = root;
        if(travel == NULL)
            cout<<"\nTree is empty!";
        else
        {
            cout<<"\nEnter the value which you want to search: ";
            cin>>key;
            do
            {
                if(travel!=NULL)
                {
                    if(travel->data > key)
                        travel = travel->left;
                    else if(travel->data < key)
                        travel = travel->right;
                    else
                    {
                        cout<<"\nNode found!";
                        cntr = 1;
                    }
                }
                else
                {
                    cout<<"\nNode not found!";
                    cntr = 1;
                }
            } while (cntr!=1);
        }
    }

    void mirrorh(node *rt)                          //dummy func for mirror()
    {
        if(rt == NULL)
        {
            return;
        }
        else
        {
            node *temp = rt->left;
            rt->left = rt->right;
            rt->right = temp;
            mirrorh(rt->left);
            mirrorh(rt->right);
        }
    }

    void mirror()                                   //to logically mirror the tree
    {
        if(root == NULL)
        {
            cout<<"\nTree is empty!";
        }
        else
        {
            cout<<"\nBefore Mirroring: ";
            inorder(root);
            mirrorh(root);
            cout<<"\nAfter Mirroring: ";
            inorder(root);
        }
    }

    void inorder(node *rt)
    {
        if(rt!=NULL)
        {
            inorder(rt->left);
            cout<<rt->data<<" ";
            inorder(rt->right);
        }
    }
};

int main()
{
    int ch;
    bst b;
    do
    {
        cout<<"\n\nBST Operations";
        cout<<"\n1.Insert\n2.Height\n3.Minimum\n4.Mirror\n5.Search\n6.Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: b.insert();
            break;
            case 2: b.height();
            break;
            case 3: b.minimum();
            break;
            case 4: b.mirror();
            break;
            case 5: b.search();
            break;
            case 6: 
            break;
            default: cout<<"\nInvalid choice!";
            break;
        }
    } while (ch!=6);
    return 0;
}