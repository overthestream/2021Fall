import sys
import heapq
input = sys.stdin.readline

lst = list()
lst_negative = list()
total = int(input())

for _ in range(total):
    num = int(input())

    if num == 0:
        if len(lst_negative)== 0 and len(lst) == 0:
            print(0)
        elif len(lst) == 0 and len(lst_negative) > 0:
            print(-heapq.heappop(lst_negative))
        elif len(lst_negative) == 0 and len(lst) > 0:
            print(heapq.heappop(lst))
        elif lst[0] > lst_negative[0]:
            print(-heapq.heappop(lst_negative))
        elif lst[0] < lst_negative[0]:
            print(heapq.heappop(lst))
        elif lst[0] == lst_negative[0]:
            print(-heapq.heappop(lst_negative))

    if num <0:
        heapq.heappush(lst_negative, -num)
    elif num > 0:
        heapq.heappush(lst, num)

