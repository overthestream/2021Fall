n, k = map(int, input().split())
array = [i for i in range(1, n+1)]
answer = []
num = k-1

for i in range(n):
    if len(array) > num:
        answer.append(array.pop(num))
        num += k-1

    elif len(array) < num+1:
        num = num % len(array)
        answer.append(array.pop(num))
        num += k-1

print("<", ', '.join(str(i) for i in answer), ">", sep="") 
