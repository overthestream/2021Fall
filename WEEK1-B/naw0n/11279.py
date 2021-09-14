import sys
import heapq

numbers = int(input())
heap = []

for _ in range(numbers):
    input = int(sys.stdin.readline())
    
    if input != 0:
        heapq.heappush(heap, (-input))
    else:
        try:
            print(-1 * heapq.heappop(heap))
        except:
            print(0)
