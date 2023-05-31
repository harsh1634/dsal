/*You have a business with several offices; you want to lease phone lines to connect them up with each other;
and the phone company charges different amounts of money to connect different pairs of cities. You want a
set of lines that connects all your offices with a minimum total cost. Solve the problem by suggesting
appropriate data structures.*/

#include<iostream>
using namespace std;

class graph
{
    int adj_matrix[5][5] = {0};
    bool visited[5] = {false};
    string cities[5];

    public:

    void create()
    {
        cout<<"\nEnter the names of 5 cities ";
        for(int i=0; i<5; i++)
        {
            cout<<"\nEnter name of city "<<i<<" : ";
            cin>>cities[i];
        }
        for(int i=0; i<5; i++)
        {
            for(int j=i+1; j<5; j++)
            {
                cout<<"\nEnter the cost between "<<cities[i]<<" and "<<cities[j]<<" : ";
                cin>>adj_matrix[i][j];
                adj_matrix[j][i] = adj_matrix[i][j];
            }
        }
    }

    void prims_MST()
    {
        int created_MST[5];
        int key[5];
        for(int i=0; i<5; i++)
        {
            key[i] = 999;
            visited[i] = false;
        }
        key[0] = 0;
        created_MST[0] = -1;
        for(int count=0; count<4; count++)
        {
            int u = min_key(key);
            visited[u] = true;
            for(int v=0;v<5;v++)
            {
                if(adj_matrix[u][v] && visited[v] == false && adj_matrix[u][v]<key[v])
                    created_MST[v] = u, key[v] = adj_matrix[u][v];
            }
        }
        print_MST(created_MST);
    }

    int min_key(int key[])
    {
        int min_val = 999;
        int min_index;
        for(int i=0; i<5; i++)
        {
            if(visited[i] == false && key[i] < min_val)
            {
                min_val = key[i];
                min_index = i;
            }
        }
        return min_index;
    }

    void print_MST(int created_MST[])
    {
	    cout << "Edge \t\t\tCost\n";
	    for (int i = 1; i < 5; i++)
		    cout <<cities[created_MST[i]]<<" - "<<cities[i]<<"\t"<<adj_matrix[i][created_MST[i]]<<" \n";
    }
};

int main()
{
    int ch;
    graph G;
    do
    {
        cout<<"\n\nOperations";
        cout<<"\n1.Create\n2.Generate MST\n3.Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: G.create();
            break;
            case 2: G.prims_MST();
            break;
            case 3:
            break;
            default: cout<<"\nInvalid Choice";
            break;
        }
    } while (ch!=3);
    return 0;
}