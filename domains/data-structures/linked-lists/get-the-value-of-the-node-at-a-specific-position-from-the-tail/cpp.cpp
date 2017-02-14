/**
 * Get Nth element from the end in a linked list of integers
 * Number of elements in the list will always be greater than N.
 *
 * Author: Eddo W. Hintoso
 * E-mail: eddo.hintoso+github@gmail.com
 */

#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T data;
    struct Node<T> *next;

    Node () {};
    Node (T data, struct Node<T>* next) : data(data), next(next) {};

    friend ostream& operator<< (ostream& out, Node<T>* X)
    {
        Node<T>* x = X;
        while (x != NULL) {
            out << x->data << " ";
            x = x->next;
        }

        return out;
    }
};

template<typename T>
T GetNode(Node<T>* head, int positionFromTail)
{
    Node<T>* cursor = head;

    Node<T>* cursor_tail = head;
    int i = positionFromTail + 1;
    while (i--)
        cursor_tail = cursor_tail->next;

    while (cursor_tail) {
        cursor_tail = cursor_tail->next;
        cursor = cursor->next;
    }

    return cursor->data;
}

int main(void)
{
    int N; // number of test cases
    int l; // length of linked lists
    int p; // position from tail
    int x_i; // value of node element

    cin >> N;
    for (int N_i = 0; N_i < N; N_i++) {
        // populate the first linked list
        cin >> l;
        Node<int>* X = NULL;
        Node<int>* x = NULL; // tracker
        for (int i = 0; i < l; i++) {
            cin >> x_i;
            if (X == NULL) {
                X = new Node<int>(x_i, NULL);
                x = X;
            }
            else {
                x->next = new Node<int>(x_i, NULL);
                x = x->next;
            }
        }

        cin >> p;

        cout << GetNode(X, p) << endl;
    }

    return 0;
}
