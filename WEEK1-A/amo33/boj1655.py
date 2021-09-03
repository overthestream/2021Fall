import sys
from queue import PriorityQueue

input = sys.stdin.readline

lst_one = PriorityQueue()
lst_two = PriorityQueue()

number = int(input())
flag = 0 # lst 0 1 중 어떤 리스트 사용?
mid = 0

for i in range(1, number+1):
    if flag == 0:
        lst_one.put(int(input()))
        mid = i // 2
        if i % 2 == 0:
            mid -=1
        for j in range(i):
            if mid == j:
                temp = lst_one.get()
                print(temp)
                lst_two.put(temp)
                continue
            lst_two.put(lst_one.get())    
        flag = 1
        continue

    elif flag == 1:
        lst_two.put(int(input()))
        mid = i // 2
        if i % 2 == 0:
            mid -=1
        for j in range(i):
            if mid == j:
                temp = lst_two.get()
                print(temp)
                lst_one.put(temp)
                continue
            lst_one.put(lst_two.get())  
        flag = 0
        continue