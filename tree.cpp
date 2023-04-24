#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *left;
    Node *right;
    // Node(char d)
    // {
    //     data = d;
    //     left = NULL;
    //     right = NULL;
    // }
    Node()
    {
        data = '0';
        left = NULL;
        right = NULL;
    }

    void insert(Node *&root, Node *&next)
    {

        char ch;
        cout << "The Root of  " << root->data << " \nWhere You want TO insert (l 0r R)" << endl;
        cin >> ch;
        if (ch == 'L' || ch == 'l')
        {
            if (root->left == NULL)
            {
                root->left == next;
            }
            else
            {
                insert(root->left, next);
            }
        }
        if (ch == 'r' || ch == 'R')
        {
            if (root->right == NULL)
            {
                root->right == next;
            }
            else
            {
                insert(root->right, next);
            }
        }
    }
    void accept(Node *&root)
    {
        char data;
        cout << "Enter the Root Data ->  ";
        cin >> data;
        int ch = 1;
        root->data = data;

        while (ch == 1)
        {
            cout << "DO YOU want To ADD More data -> ";
            cin >> ch;
            if (ch == 1)
            {
                cout << "Enter The data of new Child -> ";
                cin >> data;
                Node *next = new Node(data);
                insert(root, next);
            }
        }
    }
    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};
int main()
{
    Node *n1;

    n1.accept(n1);
    //  cout << "Enter ";
    n1.inorder(n1);
    return 0;
}