#include <iostream>
using namespace std;
class node
{
public:
    float coeff;
    int expo;
    node *next;
    node()
    {
        coeff = 0.0;
        expo = 0;
        next = NULL;
    }
};
node *insert(node *&head, float coefficient, int exponent)
{
    node *temp;
    node *NewPoly = new node;
    NewPoly->coeff = coefficient;
    NewPoly->expo = exponent;

    // if there is No node in the list or given exponent is greater than the first node exponent
    if (head == NULL || exponent < head->expo)
    {
        NewPoly->next = head;
        head = NewPoly;
    }
    else
    {
        // && temp->next->expo >= exponent
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            NewPoly->next = temp->next;
            temp->next = NewPoly;
        }
        return head;
    }
}
node *create(node *&head)
{
    int n;
    float coeff;
    int expo;
    cout << "\nEnter The Number of Terms -> ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter The coeefficient of the Term " << i + 1 << " -> ";
        cin >> coeff;
        cout << "\nEnter The Exponent of the Term " << i + 1 << " -> ";
        cin >> expo;
        head = insert(head, coeff, expo);
    }

    return head;
}

void printPoy(node *head)
{
    if (head == NULL)
    {
        cout << "\nNO Polynomial \n";
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->coeff << " X^" << temp->expo;
            temp = temp->next;
            if (temp != NULL)
            {
                cout << " + ";
            }
            else
            {
                cout << "\n";
            }
        }
    }
}

void polyAdd(node *head1, node *head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *head3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {

            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
    cout << "Added Polynomial is -> " << endl;
    printPoy(head3);
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    cout << "Enter The first Polynomial\n";
    head1 = create(head1);
    cout << "Enter The Second Polynomial \n";
    head2 = create(head2);
    printPoy(head1);
    printPoy(head2);

    polyAdd(head1, head2);
    return 0;
}

// Author : Badeom364
// Date 10-03-2023
// 3 3 2 2 1 1 0 3 5 2 -1 1 2 0