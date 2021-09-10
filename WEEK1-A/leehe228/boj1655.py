import sys
from heapq import heappop, heappush

input = sys.stdin.readline

N = int(input())

leftpq = []
leftnum = 0
rightpq = []
rightnum = 0

# 첫 값 처리
m = int(input())
print(m)
heappush(leftpq, -m)
leftnum += 1

for i in range(1, N):
    X = int(input())
    
    # 중간값보다 크면 rightpq에 넣음
    if X >= m:
        heappush(rightpq, X)
        rightnum += 1
    # 작으면 leftp1
    else:
        heappush(leftpq, -X)
        leftnum += 1

    # 둘의 길이 차이가 2 이상이라면 옮겨줌
    # leftpq -> rightpq
    if leftnum - rightnum == 2:
        heappush(rightpq, -(heappop(leftpq)))
        leftnum -= 1
        rightnum += 1

    # leftpq <- rightpq
    elif rightnum - leftnum == 2:
        heappush(leftpq, -(heappop(rightpq)))
        leftnum += 1
        rightnum -= 1

    # 짝수개면 무조건 leftpq 루트가 중간값
    if (leftnum + rightnum) % 2 == 0:
        m = -(leftpq[0])
    
    # 홀수개면
    else:
        # leftpq가 더 많다면 leftpq 루트가 중간값
        # [-99, 1, 2] [5, 10]
        if leftnum > rightnum:
            m = -(leftpq[0])

        # rightpq가 더 많다면 rightpq 루트가 중간값
        # [-99, 1, 2] [5, 10, 11, 17]
        else:
            m = rightpq[0]

    #print("-"*10)
    #print(leftpq, ",", m, ",", rightpq)
    print(m)
