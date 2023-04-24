#include <iostream>
int cnt1 = 0;
using namespace std;
class emp
{
public:
    int eid;
    string name;
    string designation;
    int mobile;
    float slalay;
    emp *next;

    emp()
    {
        eid = 0;
        name = "null";
        designation = "NULL";
        mobile = 00;
        slalay = 0.0;
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
    cout << "Enter Your Designation -> ";
    cin >> temp->designation;
    cout << "Enter Your MObile Number-> ";
    cin >> temp->mobile;
    cout << "Enter Your Salarly -> ";
    cin >> temp->slalay;
    temp->next = start;
    start = temp;
}

void insertAtend(emp *&head)
{
    if (head == NULL)
    {

        cout << "The List is Empty Try By inserAtFrist /n" << endl;
        return;
    }

    emp *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    emp *temp1 = new emp;
    cout << "Enter Your id -> ";
    cin >> temp1->eid;
    cout << "Enter Your Name -> ";
    cin >> temp1->name;
    cout << "Enter Your Designation -> ";
    cin >> temp1->designation;
    cout << "Enter Your MObile Number-> ";
    cin >> temp1->mobile;
    cout << "Enter Your Salarly -> ";
    cin >> temp1->slalay;
    temp->next = temp1;
}

void insertAtPosition(emp *&end, emp *&start, int position)
{

    if (start == NULL)
    {
        cout << "The list is Empty try to insert at start /n" << endl;
        return;
    }

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
        insertAtend(start);
        return;
    }

    // creating a node for d
    emp *nodeToInsert = new emp;
    cout << "Enter Your id -> ";
    cin >> nodeToInsert->eid;
    cout << "Enter Your Name -> ";
    cin >> nodeToInsert->name;
    cout << "Enter Your Designation -> ";
    cin >> nodeToInsert->designation;
    cout << "Enter Your MObile Number-> ";
    cin >> nodeToInsert->mobile;
    cout << "Enter Your Salarly -> ";
    cin >> nodeToInsert->slalay;
    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}

void deleteNode(int position, emp *&start)
{
    if (start == NULL)
    {
        cout << "The List is Empty No element Can be deleted " << endl;
        return;
    }

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
    else
    {
        emp *temp = new emp;
        temp = start;
        cout << "eid"
             << "\t"
             << "Name"
             << "\t"
             << "designation"
             << "\t"
             << "mobile"
             << "\t"
             << "mobile"
             << "\t"
             << "slalay" << endl;
        cout << "_________________________________________________\n";

        while (temp != NULL)
        {
            cout << temp->eid << "\t" << temp->name << "\t" << temp->designation << "\t" << temp->mobile << "\t" << temp->mobile << "\t" << temp->slalay << endl;

            temp = temp->next;
        }
    }

    cout << "------------------------------------------------------------" << endl;
}

void cnt(emp *&start)
{
    if (start == NULL)
    {
        cout << "The list is empty " << endl;
        return;
    }

    emp *temp = new emp;
    temp = start;
    int cnt = 1;
    while (temp->next != NULL)
    {
        cnt++;

        temp = temp->next;
    }
    cout << "The Number of empoyeee is -> " << cnt;
}

int main()
{

    // emp *e1 = new emp;
    // cout << "Enter Your id -> ";
    // cin >> e1->eid;
    // cout << "Enter Your Name -> ";
    // cin >> e1->name;

    emp *start = NULL;
    emp *end = NULL;
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

            insertAtend(start);
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