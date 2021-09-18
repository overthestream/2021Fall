> # WEEK2-정렬
#### 1. sort
#### 2. stable_sort
#### 3. 벡터 중복원소 제거
</br>

# 1️⃣ sort
* sort() 함수는 C++ STL의 대표적인 정렬 함수
* C++의 algorithm 헤더 파일에 포함되어 있음
* 기본적으로 오름차순 정렬
> **sort(시작 지점, 마지막 지점 + 1)**</br>
> ex 1) sort(arr, arr+10)  // 배열인 경우</br>
> ex 2) sort(arr.begin(), arr.end())  // 벡터인 경우</br>
* 직접 비교함수를 추가해줘야 하는 경우 함수를 정의하고 sort() 함수의 3번째 인자로 추가해주면 됨
> **ex) 내림차순 정렬**</br>
> sort(arr, arr+10, desc)</br>
> bool desc(int a, int b) { return a > b; }  // a > b가 참이면 1, 거짓이면 0을 반환</br>

# 2️⃣ stable_sort
* 여러 값들이 묶여 있고 하나의 요소로 정렬을 했을 때, 원래의 입력 순서를 유지하며 정렬하는 함수
* sort처럼 C++의 algorithm 헤더 파일에 포함되어 있음
* 예측할 수 있는 안정적인 정렬로, stable_sort가 sort보다 빠르며 유용하게 쓰일 때가 있음
> **ex) stable_sort()가 사용되는 경우**</br>
> sort(v.being(), v.end(), compare); // compare 함수에서 첫 번째 원소를 기준으로 정렬</br>
> sort()로 정렬하게 되면 첫번재 원소가 같을 때 문제가 생긴다.</br>
> 1 5</br>
> 3 4</br>
> 2 2</br>
> 1 2</br>
> 이때 stable_sort()를 사용하면, 첫 번째 원소를 기준으로 정렬하고 조건이 같다면 정렬 순서를 유지한다.</br>
> 1 5</br>
> 1 2</br>
> 2 2</br>
> 3 4</br>

# 3️⃣ 벡터 중복원소 제거
## vector란?
* C++ 표준 라이브러리에 있는 컨테이너
* 동적으로 원소를 추가할 수 있고, 크기가 자동으로 늘어남 (크기가 가변적인 배열)
* 속도 측면에서는 배열에 비해 떨어지지만 메모리를 효율적으로 관리할 수 있음

## vector 구조
vector을 생성하면 메모리 heap에 생성되며 동적할당된다.
* **fornt()** : 첫 번째 원소
* **back()** : 마지막 원소
* **begin()** : 첫 번째 위치
* **end()** : 마지막 원소의 다음 위치
* **size()** : 원소의 개수
* **capacity()** : 할당된 공간의 크기

## pair란?
* 2개의 각각 지정한 타입의 값(데이터 "쌍")을 저장함
* 저장한 값은 .first와 .second로 각각 접근 가능
* 2개의 연관된 값을 같이 저장할 수 있어 관리에 용이함
* utility 헤더에 존재함

## 벡터 중복원소 제거 알고리즘
1) 오름차순으로 정렬 : sort
2) 연속된 중복 원소를 vecotr의 제일 뒷부분(쓰레기 값)으로 보내버림 : uniuqe
3) 중복된 원소들이 모여있는 뒷부분(unique 함수의 리턴값 ~ vector의 end)을 제거함 : erase
> sort(v.begin(), v.end());</br>
> v.erase(unique(v.begin(), v.end()), v.end());

