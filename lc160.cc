// LC160. Intersection of Two Linked Lists

/*
   Given the heads of two singly linked-lists `headA` and `headB`, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return `null`.

   For example, the following two linked lists begin to intersect at node `c1`:

   A:     a1->a2
                \
                c1->c2->c3
                /
   B: b1->b2->b3

   The test cases are generated such that there are no cycles anywhere in the entire linked structure.

   Note that the linked lists must retain their original structure after the function returns.

   Custom Judge:

   The inputs to the judge are given as follows (your program is not given these inputs):

   - `intersectVal` - The value of the node where the intersection occurs. This is `0` if there is no intersected node.
   - `listA` - The first linked list.
   - `listB` - The second linked list
   - `skipA` - The number of nodes to skip ahead in `listA`(starting from the head) to get to the intersected node.
   - `skipB` - The number of nodes to skip ahead in `listB`(starting from the head) to get to the intersected node.

   The judge will then create the linked structure based on these inputs and pass the two heads, `headA` and `headB` to your program. If you correctly return the intersected node, then your solution will be accepted.
*/

/*
   Example1:\
   A:     4->1
              \
               8->4->5
              /
   B:  5->6->1

   Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3\
   Output: intersected at '8'\

   Example2:\
   A: 1->9->1
             \
              2->4
             /
   B:       3

   Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1\
   Output: intersected at '2'

   Example3:\
   A: 2->6->4

   B: 1->5

   Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2\
   Output: No Intersection
*/
