import sys
from collections import deque
input = sys.stdin.readline

deq = deque()

cnt = int(input())

for i in range(1, cnt+1):
    temp_str = input().rstrip("\n")
    deq.extend((map(str, temp_str.split())))
    print("Case #"+str(i)+": ", end="")
    while deq:
        print(deq.pop(), end=" ")
    print()
