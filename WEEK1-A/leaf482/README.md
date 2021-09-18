# leaf482
 
## PriorityQueue 우선순위 큐

* 높은 우선순위의 요소를 먼저 깨내서 처리함
* JAVA의 경우, Integer에서는 숫자가 작을수록 우선순위가 높음
* boj11286에서 o1과 o2 의 절대 값이 같다면 실제 숫자를 기준으로 오름차순, 아니라면 절대값을 기준으로 오름차순 정렬
* 이에 따른 return 값이 -1이면 우선순위를 높이고, 1이면 우선순위를 낮춤

## Max heap, Min heap

* Max heap(최대 힙)은 최댓값이 우선적으로 빠져나오는 큐, Min Heap(최소 힙)은 최솟값이 우선적으로 빠져나오는 큐
* boj1655에서, Max heap과 Min heap에 하나씩 숫자를 넣었다고 가정, (Max heap의 최댓값 < Min heap의 최솟값)이 충족한다면,
* Max heap의 최댓값이 항상 중간값을 가짐

# 연산속도에 관하여

* 항상 Scanner를 사용하여 값을 받았는데, 이보다 readLine() 의 연산속도가 더 빠름
* BufferedReader 는 버퍼를 이용해서 읽고 쓰는 함수인데, 입출력의 효율이 좋음 -> 시간단축에 용이

* StringBuilder VS StringBuffer
* 문자열을 한 번 만들고 연산이 필요할 때 마다 크기를 변경해가며 문자열을 변경
* StringBuilder는 StringBuffer와 다르게 동기화를 보장하지 않기에, 속도가 빠름