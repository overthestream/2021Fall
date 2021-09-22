import sys

height = []
N = int(input.stdin.readlin())
M = after = before = 0
for i in range(N):
    height.append(int(sys.stdin.readline()))
    
for _ in range(N):
    after = height.pop()
    
    if after>before:
        M += 1
        before = after
        
print(M)
