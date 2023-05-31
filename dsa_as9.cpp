#include<iostream>
#include<string.h>
using namespace std;

class node
{
    node*left,*right;
    char keyword[20],meaning[20];
    public:
    node()
    {
        left=right=NULL;   
    }
    friend class btree;
};

class btree
{
    node*root;
    public:
    
    //void delet(node* &temp, char key[]);

    /*void del()
    {
        char key[20];
        cout<<"\nEnter the keyword: ";
        cin>>key;
        delet(root,key);
    }*/

    node* findMin(node* temp);

    int height(node*temp)
    {
        if(temp==nullptr)
        return 0; 
        int l_height=height(temp->left);
        int r_height=height(temp->right);
        int maxx=max(l_height,r_height);
        int h=maxx+1;
        return h;
    }

    int bf(node*temp)
    {
        int l_height=height(temp->left);
        int r_height=height(temp->right);
        int baf=l_height-r_height;
        return baf;
    }

    node*balancing(node*temp)
    {  
        int balf=bf(temp);
        if(balf>1)
        {
            if(bf(temp->left)>0)
                temp=llrota(temp);
            else  
                temp=lrrota(temp);
        }
        
        else if(balf<-1)
        {
            if(bf(temp->right)>0)
                temp=rlrota(temp);
            else  
                temp=rrrota(temp);
        }
    return temp;
    }
    
    node*rrrota(node*parent)
    {
        cout<<"\nLeft rotation about "<<parent->keyword;
        node*temp=parent->right;
        parent->right=temp->left;
        temp->left=parent;
        return temp;
    }

    node*llrota(node*parent)
    {
        cout<<"\nRight rotation about "<<parent->keyword;
        node*temp=parent->left;
        parent->left=temp->right;
        temp->right=parent;
        return temp;
    }

    node*lrrota(node*parent)
    {
        cout<<"\nLR rotation about "<<parent->keyword;
        node*temp=parent->left;
        parent->left=rrrota(temp);
        return llrota(parent);
    }

    node*rlrota(node*parent)
    {
        cout<<"\nRL rotation about "<<parent->keyword;
        node*temp=parent->right;
        parent->right=llrota(temp);
        return rrrota(parent);
    }
 
    void display(node*);
    void update(node*,char key[]);
    void search(node*,char key []);

    void inorder_a(node*travel)
    {
        if(travel==NULL)
        {
            return;
        }
        else
        {
            inorder_a(travel->left);
            cout<<travel->keyword<<"  :  "<<travel->meaning<<"\n";
            inorder_a(travel->right);

        }
    }

    void inorder_d(node*travel)
    {
        if(travel==NULL)
        {
            return;
        }
        else
        {
            inorder_d(travel->right);
            cout<<travel->keyword<<"  :  "<<travel->meaning<<"\n";
            inorder_d(travel->left);

        }
    }

    node* insert(node*temp,char key[],char mean[])
    {    
        if(temp==NULL)
        {
            
            temp=new node();
            strcpy(temp->keyword,key);
            strcpy(temp->meaning,mean);
            temp->left=nullptr;
            temp->right=nullptr;
            return temp;
        }       
        else if(strcmp(key,temp->keyword)<0)
        {
            temp->left=insert(temp->left,key,mean);
            temp=balancing(temp);
        }
        else if(strcmp(key,temp->keyword)>0)
        {
            temp->right=insert(temp->right,key,mean);
            temp=balancing(temp);
        }
        else if(strcmp(key,temp->keyword)==0)
        {
        cout<<"\nCant add same keyword....";
        }
        return temp;         
    }  
};

/*void btree:: delet(node* &temp, char key[])
{
    if (temp == NULL)
    {
        cout << "\nDictionary is empty.";
        return;
    }
    else if (strcmp(key, temp->keyword) < 0)
    {
        delet(temp->left, key);
        temp = balancing(temp);
    }
    else if (strcmp(key, temp->keyword) > 0)
    {
        delet(temp->right, key);
        temp = balancing(temp);
    }
    else if (strcmp(key, temp->keyword) == 0)
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            delete temp;
            temp = NULL;
            cout << "\nKeyword deleted successfully.";
        }
        else if (temp->left == NULL)
        {
            node* tempNode = temp;
            temp = temp->right;
            delete tempNode;
            cout << "\nKeyword deleted successfully.";
        }
        else if (temp->right == NULL)
        {
            node* tempNode = temp;
            temp = temp->left;
            delete tempNode;
            cout << "\nKeyword deleted successfully.";
        }
        else
        {
            node* minNode = findMin(temp->right);
            strcpy(temp->keyword, minNode->keyword);
            strcpy(temp->meaning, minNode->meaning);
            delet(temp->right, minNode->keyword);
        }
    }
}*/

node* btree:: findMin(node* temp)
{
    if (temp == NULL)
        return NULL;
    else if (temp->left == NULL)
        return temp;
    else
        return findMin(temp->left);
}
  
void btree::search(node*temp,char key[])
{
    int count=0;
     
    if(temp==NULL)
    {
        cout<<"\nfirst craere the dictionaru";
        return;
    }
    else
    {
        while(temp!=nullptr)
        {
            if(strcmp(key,temp->keyword)<0)
                {
                  temp=temp->left;
                  count++;
                }

            else if(strcmp(key,temp->keyword)>0)
            {
                temp=temp->right;
                count++;
            }
            else if(strcmp(key,temp->keyword)==0)
            {
                cout<<"\nKey is found after comparision : "<<count;
                cout<<"\nkey  :  "<<temp->keyword<<"   value  :   "<<temp->meaning;
                break;  
            }
            else
            {
                cout<<"\nKey is not presnt in ht cpntec : ";
                break;
            }
        }     
    }
}

void btree::update(node*temp,char key[])
{
    if(temp==NULL)
    {
        cout<<"\nFirst create the dictionary";
        return;
    }
    else
    {
        while(temp!=nullptr)
        {
            if(strcmp(key,temp->keyword)<0)
                {
                  temp=temp->left;
                }

            else if(strcmp(key,temp->keyword)>0)
            {
                temp=temp->right;
            }
            else if(strcmp(key,temp->keyword)==0)
            {
                cout<<"\nKey is found";
                cout<<"\nKey  :  "<<temp->keyword<<"   Value  :   "<<temp->meaning;
                cout<<"\nEnter its new meaning : ";
                cin>>temp->meaning;
                cout<<"\nUpdated sucesfully....";
                break; 
            }
            else
            {
                cout<<"\nKey is not presnt";
                break;
            }
        }              
    }
}

void btree:: display(node*root)
{
    if(root==NULL)
    {
        cout<<"\nroot is empty...";
        return;
    }
    else
    {
        int c,cc;
        cout<<"\n~~~~~~MENU~~~~~~\n1.ascending\n2.decensinfn\nEnter choice:";
        cin>>c;
        switch(c)
        {
            case 1:inorder_a(root);
            break;
            case 2:inorder_d(root);
            break;         
            default:cout<<"\ninvalid entry";       
            break;     
        }
    }
}
 
int main()
{
    int ch;
    btree b;
    char key[20],mean[20];node*temp=NULL;
    do
    {
        cout<<"\n\n~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~\n1.insert\n2.search\n3.update\n4.delete\n5.display\n6.exit\n\nEnter your choice:";
        cin>>ch;
        switch (ch)
        {
            case 1:
                cout<<"\nEnter the key :";
                cin>>key;
                cout<<"\nEnter the meaning : ";
                cin>>mean;
                temp=b.insert(temp,key,mean);break;
            case 2:
                cout<<"\nEnter the key :";
                cin>>key;
                b.search(temp,key);
            break;
            case 3:
                cout<<"\nEnter the key :";
                cin>>key;
                b.update(temp,key);
                break;
            case 4://b.del();
            break;
            case 5:b.display(temp);
            break;
            case 6:cout<<"\nExiting";
            break;
            default:
            cout<<"\nEnter valid choice";
            break;
        }
   }while(ch!=6); 
   return 0;
}