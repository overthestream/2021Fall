# <목록>
1. 자료구조란?
2. 스택 (Stack)
3. 큐 (Queue)
4. 덱(Deque)
5. 힙(Heap)
6. 기타(etc.)
7. 결론
<br>
<br>

##  1) 자료구조란?
+ 사용 이유 ? 
	+  **삽입**(Insertion), **삭제**(Deletion), **탐색**(Search) 이 3가지 연산을 효율적이게 하기 위함. 
<br>
+ 특징
	+  우리가 흔하게 사용하는 배열 or 리스트 외에도 연결 리스트, 스택, 큐, 힙, 덱 등의 다양한 자료구조가 존재함.
	+ C++ 같은 경우는 STL로 다양한 자료구조를 제공함
	+ PS에서는 풀이 시간이 중요하기 때문에 직접적인 구현보다는 STL에서 제공되는 함수들의 사용법 위주로 공부함.
<br>

## 2) 스택(Stack)
+ 헤더문
	+ #include <bits/stdc++.h> 와 같은 구문에 대해 스터디 장님이 알려주셔서 이를 사용해도 좋겠지만, 필자가 불가피하게 visual studio를 사용해야해서 간단하게 작성함.
```C++
	#include <stack>
```
<br>

+ 특징
	+ LIFO(Last in First Out) 구조
		+ 가장 마지막에 들어간 원소가 가장 먼저 나옴
		+ 때문에 기본적으로 가장 최근에 들어간 원소만 접근 가능
<br>
--------------------
<br>

+ 생성
```C++
stack<[Data Type]> 변수명;
ex) stack<int> S;
```

+ 삽입
	+ PUSH 함수 : 스택에 주어진 값을 쌓음.
```C++
S.push(1);
S.push(2);
```

+ 삭제
	+ POP 함수 : 스택에 가장 최근에 push된 값을 삭제함.
```C++
S.pop();
```

+ 접근
	+ TOP 함수 : 스택에 가장 최근에 push된 값을 return함.
```C++
S.top();
```
<br>

## 3) 큐(Queue)
+ 헤더문
	+ 대체 왜 스펠링이 이런식으로 구성되는건지 이해할 수 없는 자료구조...
```C++
	#include <queue>
```
<br>

+ 특징
	+ FIFO(First in First Out) 구조
		+ 흔히 말하는 선입선출 구조
		+ 먼저 들어간 원소가 가장 먼저 나옴
		+ 때문에 넣은 순서대로 출력 가능
		+ 즉, 스택과 달리 삽입과 삭제가 다른쪽에서 이루어짐
<br>
--------------------
<br>

+ 생성
```C++
queue<[Data Type]> 변수명;
ex) queue<int> Q;
```

+ 삽입
	+ PUSH 함수 : 큐에 주어진 값을 쌓음.
```C++
Q.push(1);
Q.push(2);
```

+ 삭제
	+ POP 함수 : 큐에 남아있는 값들 중 가장 먼저 push된 값을 삭제함.
```C++
Q.pop();
```

+ 접근
	+ TOP 함수 : 큐에 남아있는 값들 중 가장 먼저 push된 값을 return함.
```C++
Q.top();
```
<br>

## 4) 덱(Deque)
+ 헤더문
	+ 대체 왜 스펠링이 이런식으로 구성되는건지 이해할 수 없는 자료구조22...
```C++
	#include <deque>
```
<br>

+ 특징
	+ Double-Ended-Queue 의 약자
	+ 앞, 뒤로 모두 삽입, 삭제가 가능
<br>
--------------------
<br>

+ 생성
```C++
deque<[Data Type]> 변수명;
ex) deque<int> DQ;
```

+ 삽입
	+ PUSH 함수
		+ push_front() : 덱의 앞쪽에 주어진 값을 삽입함
		+ push_back() : 덱의 뒤쪽에 주어진 값을 삽입함
```C++
DQ.push_front(1);
DQ.push_back(2);
```

+ 삭제
	+ POP 함수
		+ pop_front() : 앞쪽 원소 제거
		+ pop_back() : 뒤쪽 원소 제거
```C++
DQ.pop_front();
DQ.pop_back();
```

+ 접근
	+ TOP 함수
		+ begin() : 앞쪽 원소 return
		+ end() : 뒤쪽 원소 return 
```C++
DQ.begin();
DQ.end();
```

+덱은 index로도 접근이 가능하며 insert 와 같이 중간에 삽입하는 등의 기능을 제공하긴 하지만, 일단 넘어감.
<br>

## 5) 힙(Heap) -> 우선순위 큐(Priority Queue)
+ 특징
	+ 이진 트리 자료구조이다.
	+ Min Heap 과 Max Heap으로 나뉜다.
		+ Min Heap : 부모 노드 보다 자식 노드가 크면 Min 노드 -> root 노드로 가까워 질수록 value 의 크기가 작아짐.
		+ Max Heap : Min Heap 과 반대 구조.
	+ 힙을 사용하기 위한 가장 대표적인 자료구조가 Priority Queue이다. 때문에 실제적으로 PS 에서 사용하기 위해서는 Priority Queue의 사용법을 익힌다.
	
+ 헤더문 : 기본적으로 queue 형태임으로 헤더문이 동일하다.
```C++
	#include <queue>
```
<br>
--------------------
<br>

+ 생성 : 다른 자료구조와 다르게 <>안에 들어가는 요소가 다양한데, 순서대로 
실제 우선순위 큐에 들어가게 될 값, 자료구조에 사용되는 구조(주로 vector), Min/Max 를 결정짓는 요소 
순으로 이루어져있다.
```C++
priority_queue<[Data Type]> 변수명;
ex) priority_queue<int, vector<int>, greater<int>> PQ;
```

+ 삽입, 삭제, 접근의 구조는 Queue와 동일하다.
<br>

## 6) 기타 (etc.)
자료구조와 관련된 문제를 풀다보면 항상 깨닫는 사실이 있다. 
바로 **Pair** 구조와 결합하여 풀어야하는 문제가 많다는 사실!
때문에 Pair 을 확실하게 사용할 수 있도록 공부했다.

기본적으로 Pair을 생성하는 방법은 크게 2가지가 있다.
1. Class 혹은 Struct(구조체)를 사용하여 Pair을 만들어 사용하는 방법.
2. C++에서 제공하는 pair을 사용하는 방법
실제 PS에서는 Pair의 한정적인 기능만 사용해도 되므로 2번째 방법을 공부했다.

+ 생성 : make_pair 라는 함수를 사용하는 방법과 그냥 {}로 감싸는 방법 2가지가 있다.
```C++
make_pair(1,2);
{1,2}
```

+ 접근 : 이때 위의 자료구조들과 다르게 함수로 접근하는 것이 아닌 실제 변수에 접근하는 것이기 때문에 ()를 포함하면 안된다.
	+ first : 첫번째 값을 return
	+ second : 두번째 값을 return
<br>
--------------------
<br>

위 pair구조를 사용하면 다음과 같이 사용이 가능하다.
```C++
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
```
위 코드로 생성된 우선순위 큐는 pair의 first값을 기준으로 정렬되게 된다.
<br>

## 7) 결론
+ 지금까지 수십년간 개발되어 온 자료구조는 셀 수 없이 많다. 실제로 PS가 아니더라도 사용되는 자료구조는 무수히 다양하기 때문에 지금은 PS에서 가장 자주 사용되고, 1주차 과제 문제에서 사용되었던 자료구조 위주로 정리하며 공부했다 :)
