#SORTING
---
##Decrease and Conquer Technique

* 주어진 인스턴스에 대한 솔루션과 더 작게 축소한 인스턴스의 솔루션 사이의 관계성 파악
* Top down : implement recursively
* Bottom up : implement iteratively

###INSERTION SORT

* Constant variation으로 인스턴스를 축소
* 이미 정렬된 리스트에 원소 하나씩 추가하는 방법
* 대부분 bottom up(iteratively)으로 구현됨

----

##Divide and Conquer Technique

* The best-known algorithm design technique
* 문제를 동등한 사이즈의 많은 subproblem으로 나눔
* 분할 정복 방식은 "Parallel computation"일 때 적절하게 사용됨

###MERGE SORT

* Sort 방법 
    1. 주어진 배열을 절반으로 나누어 각각을 recursively하게 sort함
    2. 두 개의 정렬된 작은 배열을 하나의 배열로 합치기
        1. 두 포인터가 각 배열의 첫 주소를 가리키고 있음
        2. 두 포인터가 가리키는 요소들의 값을 비교하여 더 작은 값을 새로운 배열에 복사하고 다음 칸으로 이동
        3. 하나의 배열이 모두 소진되면 다른 한 배열의 남은 값을 그대로 복사

* MERGE SORT의 특징
    - Stable
    - Bottom-up방식으로 구현 가능(without recursion)
    - 2개의 parts 이상으로 나눌 수 있음(multiway mergesort)

###QUICK SORT

* Mergesort는 배열 내에서 element의 위치에 따라서 element가 나뉘지만 Quicksort에서는 값에 따라 나뉨
* 하나의 pivot을 정해서 왼쪽에는 pivot의 값보다 작거나 같은 요소, 오른쪽에는 크거나 같은 요소들을 배치
* 1. Best case: 중간에서 split되었을 때
  2. Worst case: 이미 정렬된 배열일 경우(=pivot값이 max 또는 min 값일 경우)