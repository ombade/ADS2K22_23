#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(char d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};
void insert(Node *&root, Node *&next)
{

    char ch;
    cout << "The Root of  " << root->data << " \nWhere You Wnat TO insert (l 0r R)" << endl;
    cin >> ch;
    if (ch == 'L' || ch == 'l')
    {
        if (root->left == NULL)
        {
            root->left = next;
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
            root->right = next;
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
        cout << "DO YOU want To ADD More data (0 or 1 ) -> ";
        cin >> ch;
        if (ch == 1)
        {
            Node *next = new Node;
            cout << "Enter The data of new Child -> ";
            cin >> data;
            next->data = data;

            insert(root, next);
        }
    }
}
void inOrder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

void preOrder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        curr = curr->right;
    }
}
void postOrder(Node *root)
{

    stack<Node *> s;
    stack<char> ans;
    Node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            ans.push(curr->data);
            s.push(curr);
            curr = curr->right;
        }

        curr = s.top();
        s.pop();

        curr = curr->left;
    }
    while (!ans.empty())
    {
        char ch = ans.top();
        cout << ch << " ";
        ans.pop();
    }
}

int main()
{
    Node *n1 = new Node;
    int ch = 0;
    while (ch != 5)
    {
        cout << "\n----------------------------------------------------------------\nMENU \n1)CREATE THE TREE \n2)INORDERD\n3)PREORDER\n4)POSTORDER\n5)EXIT\n________________________________________________";
        cout << "\nEnter Your Choice ->  ";
        cin >> ch;
        if (ch == 1)
        {
            accept(n1);
        }
        if (ch == 2)
        {
            cout << "\nINORDER TRAVERSAL OF THE TREE ->  ";
            inOrder(n1);
            cout << endl;
        }
        if (ch == 3)
        {
            cout << "\nPREORDER TRAVERSAL OF THE TREE ->  ";
            preOrder(n1);
            cout << endl;
        }
        if (ch == 4)
        {
            cout << "\nPOSTORDER TRAVERSAL OF THE TREE ->  ";
            postOrder(n1);

            cout << endl;
        }
        if (ch == 5)
        {
            cout << "____________________________THANKS FOR USING OUR PROGRAM ____________________________";
            cout << endl;
        }
    }

    return 0;
    // author : Bade Om Ambadas
    // date :11-04-2023
}