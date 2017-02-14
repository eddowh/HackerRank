"""
 Merge two linked lists
 head could be None as well for empty list

 Author: Eddo W. Hintoso
 E-mail: eddo.hintoso+github@gmail.com
"""

# -*- coding: utf-8 -*-


class Node(object):

    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next = next_node

    def __str__(self):
        res = ""
        head = self
        while (head is not None):
            res += str(head.data) + " "
            head = head.next
        return res


def MergeLists(A, B):
    """
    :param A: head of first linked list
    :param B: head of second linked list
    :return: head of merged list
    :rtype: Node
    """
    a = A
    b = B

    # if any of the lists start out as empty,
    # return the non-empty one
    if a is None:
        return b
    if b is None:
        return a

    # keep track of head
    head = A

    # 3 cursors are needed:
    # - track A
    # - track A's tail (i.e. element before None)
    # - track B
    a_trail = None
    a_cursor = None
    b_cursor = None

    while (a is not None and b is not None):
        if a.data <= b.data:
            a_cursor = a
            while a_cursor is not None:
                if a_cursor.data > b.data:
                    break
                a_cursor = a_cursor.next
                a_trail = a_trail.next if a_trail is not None else a
            # keep track of next element in B
            # because we are about to overwrite B's head's (next)
            b_cursor = b.next
            b.next = a_cursor
            a_trail.next = b
            # increment and reset
            a = a_cursor
            b = b_cursor
            a_trail = None
        else:
            b_cursor = b.next
            b.next = a
            if b.data < head.data:
                head = b  # update head
            b = b_cursor

    if (a is None and b is not None):
        t = head
        while t.next is not None:
            t = t.next
        t.next = b  # append elements of B to head

    return head


def main():
    N = int(input().strip())

    for _ in range(N):
        p = int(input().strip())  # discard

        X = None
        x = None

        if p != 0:
            for i in [str(k) for k in input().strip().split()]:
                if X is None:
                    X = Node(i, None)
                    x = X
                else:
                    x.next = Node(i, None)
                    x = x.next

        q = int(input().strip())

        Y = None
        y = None

        if q != 0:
            for i in [str(k) for k in input().strip().split()]:
                if Y is None:
                    Y = Node(i, None)
                    y = Y
                else:
                    y.next = Node(i, None)
                    y = y.next

        print(MergeLists(X, Y))


if __name__ == '__main__':
    main()
