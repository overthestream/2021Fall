import sys
from collections import deque

input = sys.stdin.readline

N, L = map(int, input().split())
A = [0] + list(map(int, input().split()))

dq = deque()

for i in range(1, N + 1):
    # pop bigger values than Ai
    while dq:
        if dq[-1][0] > A[i]:
            dq.pop()
        else:
            break
    
    # print("-"*10)
    # print(dq)
    # popleft past values
    while dq:
        if abs(i - dq[0][1]) >= L:
            dq.popleft()
        else:
            break
    
    # print(dq)
    dq.append([A[i], i])
    print(dq[0][0], end=' ')
