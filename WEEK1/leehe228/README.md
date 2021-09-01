### Stack and Queue

```python
from collections import deque

stack = deque()
stack.append(1) # O(1)
x = stack.pop() # O(1)

queue = deque()
queue.append(1) # O(1)
x = queue.popleft() # O(1)
```

<br>

### Priority Queue
```python
from queue import PriorityQueue

pq = PriorityQueue()

pq.put(1) # O(logN) == height of tree
x = pq.get() # O(logN) == height of tree
```

<br>

### Heap
```python
from heapq import heappush, heappop

hq = []

heappush(hq, 1) # O(logN) == height of tree
x = heappop(hq) # O(logN) == height of tree
```
