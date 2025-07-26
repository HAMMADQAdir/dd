#include <bits/stdc++.h>
using namespace std;

class linkedList
{
public:
    int data;
    linkedList *next;
    linkedList(int val)
    {
        this->data = val;
        next = NULL;
    }
};

int main()
{
    linkedList *head1 = NULL, *head2 = NULL;

    int n1, n2;
    cout << "enter number of digits in 1 :";
    cin >> n1;
    cout << "enter number of digits in 2 :";
    cin >> n2;
    cout << "Enter first number ";
    while (n1-- > 0)
    {
        int x;
        cin >> x;
        linkedList *temp = new linkedList(x);
        temp->next = head1;
        if (head1 == NULL)
            head1 = temp;
        else
        {
            temp->next = head1;
            head1 = temp;
        }
    }
    cout << "Enter second number ";
    while (n2-- > 0)
    {
        int x;
        cin >> x;
        linkedList *temp = new linkedList(x);

        if (head2 == NULL)
            head2 = temp;
        else
        {
            temp->next = head2;
            head2 = temp;
        }
    }

    cout << "The first number is: ";
    linkedList *temp = head1;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "The second number is: ";
    temp = head2;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    temp = head1;
    linkedList *temp2 = head2, *start = NULL;
    int carry = 0;
    while (temp != NULL || temp2 != NULL || carry != 0)
    {
        int d1 = temp != NULL ? temp->data : 0;
        int d2 = temp2 != NULL ? temp2->data : 0;
        int sum = d1 + d2 + carry;

        carry = sum / 10;
        int digit = sum % 10;
        if (start == NULL)
        {
            start = new linkedList(digit);
            cout << "start " << start->data;
        }
        else
        {
            linkedList *temp = new linkedList(digit);
            temp->next = start;
            start = temp;
        }
        if (temp != NULL)
        {
            temp = temp->next;
        }
        if (temp2 != NULL)
        {
            temp2 = temp2->next;
        }
    }

    cout << "The sum is: ";
    temp = start;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}