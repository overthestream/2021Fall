### Stack and Queue

```python
from collections import deque

stack = deque()
stack.append(1)
x = stack.pop()

queue = deque()
queue.append(1)
x = queue.popleft()
```

<br>

### Priority Queue
```python
from queue import PriorityQueue

pq = PriorityQueue()

pq.put(1)
x = pq.get()
```

<br>

### Heap
```python
from heapq import heappush, heappop

hq = []

heappush(hq, 1)
x = heappop(hq)
```
