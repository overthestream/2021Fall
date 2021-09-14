import sys
from collections import deque
input = sys.stdin.readline

lst = deque()

total, margin = map(int, input().split())
tmp_list = list(map(int, input().rstrip("\n").split()))
result = [0 for _ in range(total)]

for i in range(total):

    while lst and lst[-1][1] > tmp_list[i]:
        lst.pop() # 오르쫀 control
    
    while lst and  i - lst[0][0] >= margin:
         lst.popleft() # left pop
        
    lst.append((i, tmp_list[i])) # append
    result[i] = lst[0][1] 
for value in result:
    print(value, end=" ")