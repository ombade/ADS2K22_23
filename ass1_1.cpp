#include <iostream>
int cnt1 = 0;
using namespace std;
class emp
{
public:
    int eid;
    string name;
    emp *next;

    emp()
    {
        eid = 0;
        name = "null";
        next = NULL;
    }
};

void insertAtHead(emp *&start)
{

    // new node create
    emp *temp = new emp;
    cout << "Enter Your id -> ";
    cin >> temp->eid;
    cout << "Enter Your Name -> ";
    cin >> temp->name;
    temp->next = start;
    start = temp;
}

void insertAtend(emp *&end)
{

    // else
    // {
    emp *temp = new emp;
    cout << "Enter Your id -> ";
    cin >> temp->eid;
    cout << "Enter Your Name -> ";
    cin >> temp->name;
    end->next = temp;
    end = temp;
    // }
}

void insertAtPosition(emp *&end, emp *&start, int position)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(start);
        return;
    }

    emp *temp = start;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtend(end);
        return;
    }

    // creating a node for d
    emp *nodeToInsert = new emp;
    cout << "Enter Your id -> ";
    cin >> nodeToInsert->eid;
    cout << "Enter Your Name -> ";
    cin >> nodeToInsert->name;
    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}

void deleteNode(int position, emp *&start)
{

    // deleting first or start node
    if (position == 1)
    {
        emp *temp = start;
        start = start->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        emp *curr = start;
        emp *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void display(emp *&start)
{
    if (start == NULL)
    {
        cout << "The list is Empty \n";
    }

    emp *temp = new emp;
    temp = start;
    while (temp != NULL)
    {
        cout << temp->eid << "\t" << temp->name << endl;

        temp = temp->next;
    }
    cout << "------------------------------------------------------------" << endl;
}

void cnt(emp *&start)
{
    emp *temp = new emp;
    temp = start;
    int cnt = 0;
    while (temp->next != NULL)
    {
        cnt++;

        temp = temp->next;
    }
    cout << "The Number of empoyeee is -> " << cnt;
}

int main()
{

    emp *e1 = new emp;
    cout << "Enter Your id -> ";
    cin >> e1->eid;
    cout << "Enter Your Name -> ";
    cin >> e1->name;
    cnt1++;
    emp *start = e1;
    emp *end = e1;
    int n;

    int ch = 0;
    while (ch != 7)
    {
        cout << endl
             << "-------------------------------------" << endl;
        cout << "Menu \n1)Insert At head \n2)Insert At end \n3)Insert at postion \n4)Delete the data \n 5)count the employee \n6)display \n 7)exit" << endl;
        cin >> ch;
        cout << endl
             << "-------------------------------------" << endl;
        if (ch == 1)
        {
            insertAtHead(start);
        }
        if (ch == 2)
        {

            // end = end->next;

            insertAtend(end);
        }
        if (ch == 3)
        {
            int pos;
            cout << "Enter the Postion to be enterd -> ";
            cin >> pos;
            insertAtPosition(end, start, pos);
        }
        if (ch == 4)
        {
            int pos;
            cout << "Enter the Postion to be deleted -> ";
            cin >> pos;
            deleteNode(pos, start);
        }
        if (ch == 5)
        {
            cnt(start);
        }
        if (ch == 6)
        {

            display(start);
        }

        if (ch == 7)
        {
            cout << "Thankyou  For Using program \n";
        }
    }
}