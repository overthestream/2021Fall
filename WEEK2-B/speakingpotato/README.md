#2752&2759
선택 정렬 이용
가장 작은 값부터 앞으로 당겨 옴

#15814
선택 정렬을 이용하여 N번째 까지만 정렬

#10814
정렬할 때 stable 해야 함
나이-이름 페어로 저장할 방법?
리스트 두 개를 sort하는 것은 효율적이지 못함.
1) pair 이용?

->pair 이용
https://blockdmask.tistory.com/64
pair 개념 참고
https://blockdmask.tistory.com/70
vector 개념 참고

2) 구조체 이용 + stable_sort (algorithm 헤더파일)
bool comp 작성
int, string 구별받아 입력하는 문제는 cin으로 해결
반복자 이용해서 출력 -> 쉽지 않다..

*compare 함수에서 비교연산자를 <= 으로 쓸 경우 stable 하게 유지되지 않았다
*iterator 이용시 iter 은 포인터이므로 구조체의 속성에 접근할 때 . 대신 -> 를 사용하여야 한다

*cin/cout 사용하니 시간초과가 떴다.
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
을 이용하여 해결했고, 



#10867
가장 도움이 된 곳
https://blockdmask.tistory.com/79

set의 기본적 개념 참고


set 헤더 파일에 들어있음
set < [ Data Type ] > [변수 이름];
중복이 허용되지 않는 원소(key) 의 집합. 
Insert 멤버 함수에 의해 삽입되면 원소는 자동으로 정렬됨 (기본 오름차순)
반복자 이용할 경우
set < [Data Type] >::iterator iter_name

S.begin()// 반복자를 리턴
S.end() // 맨 마지막 원소의 다음을 가리키는, 원소의 끝부분. 반복자를 리턴
S. insert()

