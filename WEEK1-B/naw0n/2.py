import sys

n = int(sys.stdin.readline())

for i in range(1,n+1):
    cut = list(sys.stdin.readline().rstrip().split())
    print('Case #%d: %s' %(i,' '.join(cut[::-1])))
