+ boj 11286
크게 어렵지 않았음

+ boj 1655
brute force로 하면 n번에 sort(최소 nlogn)이므로 시간초과 뜸
입력 받을 때마다 가운데값 뽑아내야하므로 heap 사용
중앙값 기준으로 작은 수는 maxheap / 큰 수는 minheap에 저장

+ boj 3015
이 문제랑 관점이 비슷하나 더 쉬운 백준 문제가 있음 (참고: https://www.acmicpc.net/problem/17608)
스택을 사용하면 됨 -> 결국 왼쪽오른쪽 중 하나만 잡고 보면 되기 때문