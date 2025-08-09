#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
        // 1
        // 3 5
        // 6 7 8 9
    }
};

node *buildTree(node *root)
{
    int d;
    cout << "Ente data :- " << endl;
    cin >> d;
    root = new node(d);

    if (d == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << d << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << d << endl;
    root->right = buildTree(root->right);
    cout << endl;
    return root;
}


    int val = -1;
    bool isUnivalTree(node* root) {
          if(!root) return true;
          if(val < 0) val = root->data;
          return root->data == val && isUnivalTree(root->left) && isUnivalTree(root->right);
    }
int main()
{
    node *root = NULL;
    root = buildTree(root);
    if (isUnivalTree(root)) {
        cout << "The tree is a unival tree." << endl;
    } else {
        cout << "The tree is not a unival tree." << endl;
    }
    return 0;
}