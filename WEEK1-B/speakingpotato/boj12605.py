import sys

N = int(sys.stdin.readline())


for i in range(N):
    originline = sys.stdin.readline().split()
    originline.reverse()
    print("Case #",end = "")
    print((i + 1), end = "")
    print(": ",end = "")
    print(' '.join(originline))
