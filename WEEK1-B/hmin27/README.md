#week01

#boj11279

1. Priority Queue 우선순위 큐
   = queue with priority for pop
    - 최대 우선순위 큐: 가장 높은 우선순위를 가진 원소를 pop
    - 최소 우선순위 큐: 가장 낮은 우선순위를 가진 원소를 pop

    Time Complexity for unordered list
    - O(1) for push, O(n) for pop

2. Heap 힙
    = Specialized tree-baesed data structure that satisfies the heap property
    - 최대 힙: 부모의 key value가 자식 노드의 key value보다 크거나 같은 Complete Binary Tree
    - 최소 힙: 부모의 key value가 자식 노드의 key value보다 작거나 같은 Complete Binary Tree

    최대 힙이나 최소 힙은 부모, 자식 간의 key value에 순서가 정해져 있을 뿐 형제끼리는 값을 비교하지 않음
        -> left < right, left > right의 순서는 보장되지 않음

    Time Complexity
    - O(log n) for push, pop
