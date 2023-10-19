C - Stacks, Queues - LIFO, FIFO
#1 LIFO and FIFO:
- LIFO: LIFO stands for "Last-In, First-Out." It is a data structure or processing order in which the last item added to a collection is the first one to be removed. Think of it like a stack of plates - you add one on top, and the last one you added is the first one you'll take off.
- FIFO: FIFO stands for "First-In, First-Out." It's a data structure or processing order in which the first item added to a collection is the first one to be removed. Imagine a queue of people waiting in line; the person who joined the line first will be the first to be served.
#2 Stack:
- A stack is a linear data structure that follows the LIFO (Last-In, First-Out) principle. It can be thought of as a collection of elements with two main operations: push (to add an element to the top of the stack) and pop (to remove the top element). Stacks are used in various programming scenarios, such as managing function calls and storing temporary data.
- Use a stack when you need to maintain a temporary or reversible order of items, track function calls, or implement undo/redo functionality.
#3 Queue:
A queue is another linear data structure that follows the FIFO (First-In, First-Out) principle. It's like a line of people waiting for something. Elements are added to the rear (enqueue) and removed from the front (dequeue) of the queue.
Use a queue when you want to manage tasks in an ordered manner, such as scheduling print jobs in a printer queue or handling tasks in a first-come, first-served fashion.
#4 Common Implementations:
- Stacks: Stacks can be implemented using arrays or linked lists. In some programming languages, there are built-in stack data structures.
- Queues: Queues can be implemented using arrays, linked lists, or specialized data structures like a double-ended queue (deque). Some languages also provide built-in support for queues.
#5 Common Use Cases:
- Stacks: Function call management (call stack), expression evaluation, undo/redo functionality in software, and maintaining state in algorithms like depth-first search.
- Queues: Task scheduling, breadth-first search in algorithms, print job management, and managing resources in concurrent systems (like thread or process scheduling).
#6 Proper Use of Global Variables:
Global variables should be used sparingly because they can lead to various issues, such as making code harder to understand and debug. 
Here are some best practices for using global variables:
- Clearly document the purpose of global variables and their intended usage.
- Use all capital letters to name global constants to distinguish them from other variables.
- Minimize the use of global variables by encapsulating data and functionality within functions or classes.
- Avoid modifying global variables from multiple places in your code to prevent unexpected side effects.
- Consider using global variables for truly global settings or configuration data that needs to be accessed across different parts of your program.
It's generally a good practice to limit the use of global variables in favor of passing data between functions or using local variables, as this can make your code more modular and easier to maintain.

TASKS:

0. push, pall
Implement the push and pall opcodes.

The push opcode:

The opcode push pushes an element to the stack.

- Usage: push <int>
where <int> is an integer
- if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number in the file
- You won’t have to deal with overflows. Use the atoi function

The pall opcode:

The opcode pall prints all the values on the stack, starting from the top of the stack.

- Usage pall
- Format: see example
- If the stack is empty, don’t print anything

1. pint
Implement the pint opcode.

The pint opcode

The opcode pint prints the value at the top of the stack, followed by a new line.

- Usage: pint
- If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

2. pop
Implement the pop opcode.

The pop opcode

The opcode pop removes the top element of the stack.

Usage: pop
If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

3. swap
Implement the swap opcode.

The swap opcode

The opcode swap swaps the top two elements of the stack.

Usage: swap
If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE


4. add
Implement the add opcode.

The add opcode

The opcode add adds the top two elements of the stack.

Usage: add
If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter

5. nop
Implement the nop opcode.

The nop opcode

The opcode nop doesn’t do anything.

Usage: nop

