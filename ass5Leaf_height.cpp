#include <iostream>
#include<stack>
#include <queue>
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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

int leafNode(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    int leftans = leafNode(root->left);
    int right = leafNode(root->right);
    int ans = leftans + right;
    return ans;
}

void MirrorImg(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        Node *temp;

        MirrorImg(root->left);
        MirrorImg(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
int main()
{
    Node *n1 = new Node;
    accept(n1);
    int cnt = 0;
    cout << "The height of the Tree is -> " << height(n1);

    cout << endl
         << "the Number oF leafNode is -> " << leafNode(n1);

    int ch = 0;

    while (ch != 5)
    {
        cout << "\n----------------------------------------------------------------\nMENU \n1)CREATE THE TREE \n2)COUT THE LEAF NODE \n3)HEIGHT OF THE TREEE \n4)MirrorImg OF THE TREE \n5)EXIT\n________________________________________________";
        cout << "\nEnter Your Choice ->  ";
        cin >> ch;
        if (ch == 1)
        {
            accept(n1);
        }
        if (ch == 2)
        {
            cout << endl
                 << "the Number oF leafNode is -> " << leafNode(n1);
            cout << endl;
        }
        if (ch == 3)
        {
            cout << "The height of the Tree is -> " << height(n1);
        }
        if (ch == 4)
        {
            cout << "\nBEFORE MIRROR MIRRORING \n";
            levelOrderTraversal(n1);
            MirrorImg(n1);
            cout << "\n AFTER MIRROR MIRRORING \n";
            levelOrderTraversal(n1);
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