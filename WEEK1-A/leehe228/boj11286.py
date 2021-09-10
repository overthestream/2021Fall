import sys
import heapq

input = sys.stdin.readline

N = int(input())
# Heap
hq = []

for n in range(N):
    x = int(input())

    if x == 0:
        if hq:
            # 자동으로 절댓값이 가장 작은 값이 나온다
            x, i = heapq.heappop(hq)
            # 음수라면 -1이 곱해져 출력된다
            print(str(x * i))
        else:
            # 비어있다면 0 출력
            print('0')

    else:
        # 절댓값과 부호를 힙에 넣음
        if x < 0:
            # 음수
            heapq.heappush(hq, [-x, -1])
        else:
            # 양수
            heapq.heappush(hq, [x, 1])
