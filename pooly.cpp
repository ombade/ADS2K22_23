#include <iostream>
using namespace std;

struct node
{
    int coef;
    int exp;
    node *next;
};

node *createnode(int c, int e)
{
    node *t;
    t = new node;
    t->coef = c;
    t->exp = e;
    t->next = NULL;
    return t;
}

node *findlast(node *head)
{
    node *ptr;
    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    return (ptr);
}

node *createpoly()
{
    node *head = NULL, *ptr, *temp;
    int c, e, no, i;
    char p;
    cout << "Enter no.of terms";
    cin >> no;
    for (i = 0; i < no; i++)
    {
        cout << "Enter coefficient & exponential:\n";
        cin >> c >> e;
        temp = createnode(c, e);
        if (head == NULL)
        {
            head = temp;
            temp->next = head;
        }
        else
        {
            ptr = findlast(head);
            ptr->next = temp;
            temp->next = head;
        }
    }
    return head;
}

node *addpoly(node *ptr1, node *ptr2)
{
    node *head = NULL, *temp, *Temp, *ptr, *ptr_1, *ptr_2;
    int p, q;
    ptr_1 = ptr1;
    ptr_2 = ptr2;
    do
    {
        ptr_2 = ptr2;
        do
        {
            cout << "***********\n";
            cout << ptr_1->exp;
            cout << ptr_2->exp;
            cout << "***********\n";

            if (ptr_1->exp == ptr_2->exp)
            {

                p = ptr_1->coef + ptr_2->coef;
                q = ptr_1->exp;
                temp = createnode(p, q);
                cout << "RRRRRRRRRRRRRRRRRRR";
                if (head == NULL)
                {
                    head = temp;
                    temp->next = head;
                    cout << "ooooooooooooooo";
                }
                else
                {
                    ptr = head;
                    ptr->next = temp;
                    temp->next = head;
                    // ptr=ptr->next;
                }
                break;
            }
            ptr_2 = ptr_2->next;

        } while (ptr_2->next != head);

        ptr_1 = ptr_1->next;
        cout << "\nkkkkkkkkkkkkk\n";
    } while (ptr_1->next != head);
    cout << "jjjjjjjjjjj";
    return head;
}

void display(node *head)
{
    node *ptr;
    ptr = head;

    while (ptr->next != head)
    {
        cout << ptr->coef << "x^" << ptr->exp << "+";
        ptr = ptr->next;
    }
    cout << ptr->coef << "x^" << ptr->exp;
}

int main()
{
    node *head, *ptr1, *ptr2, *ptr3;
    ptr1 = createpoly();
    cout << "\n";
    ptr2 = createpoly();
    cout << "Polynomial1:";
    display(ptr1);
    cout << "\n\n";
    cout << "Polynomial2:";
    display(ptr2);
    ptr3 = addpoly(ptr1, ptr2);
    cout << "hello";
    display(ptr3);
}