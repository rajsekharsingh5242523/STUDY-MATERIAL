#=============
# QUEUE - FIFO --> first in first out
#=============

#1. Implementation using list

queue = []
queue.append('a')
queue.append('b')
queue.append('c')
print("Initial queue:", queue)

print("Elements dequeued from queue:")
print(queue.pop(0))
print(queue.pop(0))
print(queue.pop(0))

print("Queue after removing elements:", queue)

#2. Implementation using collections.deque

from collections import deque
q = deque()

q.append('a')
q.append('b')
q.append('c')
print("Initial queue:", q)

print("Elements dequeued from the queue:")
print(q.popleft())
print(q.popleft())
print(q.popleft())

print("Queue after removing elements:", q)


#=============
# STACK - LIFO --> last in first out
#=============


# 1. Using a List

stack = []

# append() function to push element in the stack
stack.append('a')
stack.append('b')
stack.append('c')

print('Initial stack')
print(stack)
# pop() function to pop element from stack in LIFO order
print('\nElements popped from stack:')
print(stack.pop())
print(stack.pop())
print(stack.pop())

print('\nStack after elements are popped:')
print(stack)

# uncommenting print(stack.pop()) will cause an IndexError as the stack is now empty


#2. Using collections.deque


from collections import deque
stack = deque()

# append() function to push element in the stack
stack.append('a')
stack.append('b')
stack.append('c')

print('Initial stack:')
print(stack)

# pop() function to pop element from stack in LIFO order
print('\nElements popped from stack:')
print(stack.pop())
print(stack.pop())
print(stack.pop())

print('\nStack after elements are popped:')
print(stack)

# uncommenting print(stack.pop()) will cause an IndexError as the stack is now empty