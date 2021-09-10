import sys

input = sys.stdin.readline

N = int(input())
heights = [int(input()) for _ in range(N)]

count = 0
stack = []

for height in heights:
    nowcount = 1
    while stack:
        if height >= stack[-1][0]:
            count += stack[-1][1]

            if height == stack[-1][0]:
                nowcount += stack[-1][1]

            stack.pop()

        else:
            count += 1
            break

    stack.append((height, nowcount))

print(count)