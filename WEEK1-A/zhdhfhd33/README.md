#heap<br>
정렬된 상황을 유지해야하는 상황에서 리스트, 배열은 삽입 삭제가 O(N)이 걸리므로 log N이 걸리는 heap을 사용하는 것을 고려할만 하다.<br>
다만 heap구현 시 upheap(push), downheap(pop)의 과정이 구현하기 쉽지는 않은 듯. STL priority queue가 있다고 하니 알아보자.<br>
