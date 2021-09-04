import sys

from bisect import bisect_left, bisect_right
input = sys.stdin.readline

lst_for_print = list()
number = int(input())
mid = 0
for i in range(1, number + 1): # 현재 시간 복잡도 : O(n^2 log n) --> PQ를 사용할 수 있는 방법이 뭐가 있을까?
    temp_value = int(input())
    lst_for_print.insert(bisect_left(lst_for_print, temp_value), temp_value)
    print(lst_for_print[mid])
    if i % 2 == 0:
        mid += 1