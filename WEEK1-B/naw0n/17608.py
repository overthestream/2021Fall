import sys

n = int(sys.stdin.readline())
array = []

for _ in range(n):
    array.append(int(sys.stdin.readline()))

output = array[n-1]
value = 1

for i in range(n):
    if output<array[n-i-2] : value  += 1 ; output = array[n-i-2]

print(value)
