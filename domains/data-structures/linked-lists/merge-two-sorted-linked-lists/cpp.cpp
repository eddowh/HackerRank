/**
 * Merge Two Sorted Linked Lists
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
Node<T>* MergeLists(Node<T>* A, Node<T>* B)
{
    Node<T>* a = A;
    Node<T>* b = B;

    // if any of the lists start out as empty,
    // return the non-empty one
    if (a == NULL) return b;
    if (b == NULL) return a;

    // keep track of the head
    Node<T>* head = A;

    // need 3 cursors:
    // - track A
    // - track A's trail (i.e. element before NULL)
    // - track B
    Node<T>* a_trail = NULL;
    Node<T>* a_cursor = NULL;
    Node<T>* b_cursor = NULL;

    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data) {
            a_cursor = a;
            while (a_cursor != NULL) {
                if (a_cursor->data > b->data) break;
                a_cursor = a_cursor->next;
                a_trail = (a_trail) ? a_trail->next : a;
            }
            // keep track of next element in B
            // because we are about to overwrite B's head's (next)
            b_cursor = b->next;
            b->next = a_cursor;
            a_trail->next = b;
            // increment and reset
            a = a_cursor;
            b = b_cursor;
            a_trail = NULL;
        }
        else {
            b_cursor = b->next;
            b->next = a;
            if (b->data < head->data)
                head = b; // update head
            b = b_cursor;
        }
    }

    if (a == NULL && b != NULL) {
        Node<T>* t = head;
        while (t->next == NULL) // O(n)
            t = t->next;
        t->next = b; // append remnants of B to head
    }

    return head;
}

int main(void)
{
    int N; // number of test cases
    int p,q; // length of linked lists
    int x_i, y_i;

    cin >> N;
    for (int N_i = 0; N_i < N; N_i++) {
        // populate the first linked list
        cin >> p;
        Node<int>* X = NULL;
        Node<int>* x = NULL; // tracker
        for (int i = 0; i < p; i++) {
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

        // populate the 2nd linked list
        cin >> q;
        Node<int>* Y = NULL;
        Node<int>* y = NULL; // tracker
        for (int i = 0; i < q; i++) {
            cin >> y_i;
            if (Y == NULL) {
                Y = new Node<int>(y_i, NULL);
                y = Y;
            }
            else {
                y->next = new Node<int>(y_i, NULL);
                y = y->next;
            }
        }

        cout << MergeLists(X, Y) << endl;
    }

    return 0;
}
