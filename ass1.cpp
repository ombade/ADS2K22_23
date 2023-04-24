#include <iostream>
using namespace std;

class emp
{
public:
    int eid;
    string name;
    emp *next;
    void accept();
    void display();

} *start, *temp;

void emp ::accept()
{
    emp *temp = new emp;

    int id;
    cout << "Enter the id -> ";
    cin >> id;
    cout << "Enter the name -> ";
    cin >> temp->name;
    temp->eid = id;
    temp->next = start;
    start = temp;
}

void emp ::display()
{
    emp *temp = new emp;
    temp = start;
    while (temp != NULL)
    {
        cout << temp->eid << "\t" << temp->name << endl;
        ;
        temp = temp->next;
    }
}

int main()
{
    emp e;
    int n;
    cout << " Enter the Number of Empoye -> ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        e.accept();
    }
    e.display();
}