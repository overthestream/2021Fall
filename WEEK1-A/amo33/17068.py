import sys
input = sys.stdin.readline

N = int(input())

lst = list()

for _ in range(N):
    data = int(input())
    lst.append(data)

count = 0
start = 0

for i in range(1, N+1):
    target = lst[-i] # 반대로 
    if target > start:
        count += 1
        start = target #더 높은거 생각

print(count)