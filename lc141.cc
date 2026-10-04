// LC141. Linked List Cycle

/*
    Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer.\
    Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. Note that `pos` is not passed as a parameter.

    Return `true` if there is a cycle in the linked list. Otherwise, return `false`
*/

/*
    Example1:\
    3 -> 2 -> 0 -> 4
         ^         |
         |_________|

    Input: head = [3,2,0,-4], pos = 1\
    Output: true

    Example2:\
    1 -> 2
    ^    |
    |____|
    Input: head = [1,2], pos = 0\
    Output: true

    Example3:\
    1
    Input: head = [1], pos = -1
    Output: false

*/