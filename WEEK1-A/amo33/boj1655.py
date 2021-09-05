import sys
import heapq
input = sys.stdin.readline

lst_left = list()
lst_right = list()
number = int(input())

for _ in range(number):
    temp = int(input())

    if len(lst_right) == len(lst_left):
        heapq.heappush(lst_left, (-temp, temp))
    else:
        heapq.heappush(lst_right, (temp,temp))

    if len(lst_right) > 0 and lst_left[0][1] > lst_right[0][1]:
        Max_value = heapq.heappop(lst_left)[1]
        Min_value = heapq.heappop(lst_right)[1]
        heapq.heappush(lst_left, (-Min_value, Min_value))
        heapq.heappush(lst_right, (Max_value, Max_value))
       
    print(lst_left[0][1])