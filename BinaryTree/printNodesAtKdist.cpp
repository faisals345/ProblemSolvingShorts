#include <bits/stdc++.h>
using namespace std;

struct node
{

    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
//1 2 4 -1  -1 5 7 -1 -1 -1 3 -1 6 -1 -1

node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void printAtdistanceK(node *root, int k)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int t=0;

    while (!q.empty())
    {
        node *temp = q.front();
        

     if(t<k-1){

        
            if (temp == NULL)
            {
                if (q.empty())
                {
                    return;
                }
                t++;
            // cout << endl;
                q.pop();
                q.push(NULL);
            }
            else
            {

                //cout << temp->data << " ";
                q.pop();

                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }

      } 
      else{
          while(temp!=NULL){
              cout<<temp->data<<" ";
              q.pop();
              temp=q.front();
          }
          return;
      }

    }
}

int main()
{

    node *root = buildTree();
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

    printAtdistanceK(root,3);

    return 0;
}