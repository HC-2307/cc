lvl 0:
This code implements a Doubly Linked List (DLL) data structure in C++ without using STL. The DLL supports fundamental operations such as node creation, insertion at the head and tail, and forward and backward traversal.

Node Creation: Creates nodes dynamically.
Insertion:
At Head: Inserts a node at the beginning.
At Tail: Inserts a node at the end.
Traversal:
Forward Traversal: Prints the list from head to tail.
Backward Traversal: Prints the list from tail to head.


lvl 1
This code implements a stack data structure in C++ without using STL <stack> or linked lists. The stack supports basic operations like push(), pop(), top() and also provides getMin() and getMax() functions to retrieve the smallest and largest elements in O(1) time.
Push (push(x)): Inserts an element x onto the stack.
Pop (pop()): Removes the top element from the stack.
Top (top()): Returns the top element without removing it.
Get Minimum (getMin()): Retrieves the smallest element in the stack.
Get Maximum (getMax()): Retrieves the largest element in the stack.
Uses #define max_size 100 for defining stack capacity.
Uses three arrays:
stack[max_size] → Stores elements.
min_stack[max_size] → Tracks the minimum values.
max_stack[max_size] → Tracks the maximum values.
The min_stack and max_stack are updated at every push() operation to ensure O(1) retrieval of min/max values.


