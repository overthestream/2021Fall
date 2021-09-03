# heapq algorithm

<pre>
<code>
lst = list()
lst_negative = list()
</code>
</pre>

이 문제같은 겨우 heapq의 pop이 익숙하여 사용했다. 
heapq는 pop이 될때 가장 작은 값을 pop 시켜주기 때문이다.   
그리고 문제를 접근하는 방법은 음수와 양수 따로 저장해주는 list를 만들어주고 값을 비교하여 더 작은 값을 pop 시켜준다.

# priority queue algorithm 

<pre>
<code>
from queue import PriorityQueue # import 

que = PriorityQueue() # 생성 parameter : maxsize// or else que: infinite
</code>
</pre>
- 현재 이 문제를 풀지 못한 상태인데 시간초과 면에서 조언해주실 수 있으신 분 있을까요?
알고리즘 설명 : priority queue 이기 때문에 get 한 값을 똑같은 queue에 넣으면 똑같이 get 한 함수가 나오기 때문에 2개의 PQ를 사용하려고 코드를 짰다
               이전에 비해서 코드가 돌아가지만 실제로 시간초과가 나서 어디서 내 코드를 뜯어고쳐야할지 고민중
Priority Queue의 put(), get() : O(log n)

