//쉬운 스도쿠는 푸는데 어려운 것은 empty stack err난다. -> 백트래킹이 (0,0)까지 진행되어서 풀 수 없다는 결론임.
//모르겠다~

import java.util.Scanner;
import java.util.Stack;


class Triple {
	int x;
	int y;
	int idx;

	Triple(int x, int y, int idx) {
		this.x = x;
		this.y = y;
		this.idx = idx;
	}
}

class Data {
	int num;
	int[] check; // 초기화 하지 않으면 자동 null대입.
//	Data(int num, int [] check){
//		this.num=num;
//		this.check=check;
//	}   

	Data(int num) {
		this.num = num;
	}
}

public class Main {
	public static void printArr(Data arr[][]) {
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[0].length; ++j) {
				System.out.printf("%d ", arr[i][j].num);
			}
			System.out.println();
		}
	}

	

	//전부 0으로 초기화
	public static void resetCheck(int check[]) {
		for (int i=0; i<check.length; ++i) {
			check[i]=0;
		}
	}
	// row, col을 한번에 검사가능.
	public static void checkRowCol(Data arr[][], int row, int col) {
		
		for (int i = 0; i < arr.length; ++i) {
			if (arr[row][i].num != 0) {
				arr[row][col].check[arr[row][i].num] = 1;
			}
		}
		for (int i = 0; i < arr.length; ++i) {
			if (arr[i][col].num != 0) {
				arr[row][col].check[arr[i][col].num] = 1;
			}
		}

	}

	// 자신의 좌표를 전달하면 3*3 box안에서의 남은 수를 반환함.
	public static void checkBox(Data arr[][], int row, int col) {
//		int check[] = new int[10];
		int startRow = row / 3 * 3;// *3해줘야한다.
		int startCol = col / 3 * 3;
		for (int i = startRow; i < startRow + 3; ++i) {
			for (int j = startCol; j < startCol + 3; ++j) {
				arr[row][col].check[arr[i][j].num] = 1; // 이미 사용된 수 라면 1을 대입.
			}
		}
//		return check;
	}

	// 이렇게 몇개의 작은 함수로 나눠 작성하면 보기에는 쉽고 코드 짤 때는 쉬운데 check를 계속 만들고 합치고 해야하니 효율적인 방법은 아닌
	// 듯.
	public static void resetCheckAll(Data arr[][], int row, int col) {
		try {
			resetCheck(arr[row][col].check);
			checkRowCol(arr, row, col);
			checkBox(arr, row, col);
		} catch (Exception e) {
			
		}
		

	}
	public static void addCheckAll(Data arr[][], int row, int col) {
		checkRowCol(arr, row, col);
		checkBox(arr, row, col);
	}

	// 사용가능한 숫자의 개수를 반환. 사용가능한 숫자가 0이라면 뒤로 뒤로 돌아가야함
	public static int getCount(int[] check) {
		int cnt = 0;
		for (int i = 1; i < check.length; ++i) {
			if (check[i] == 0) { // 0일 때 사용가능함
				++cnt;
			}
		}
		return cnt;
	}

	public static void main(String[] args) {

		// 입력부분
		Scanner sc = new Scanner(System.in);
		Data arr[][] = new Data[9][9]; // java에서 내가 만든 객체의 배열은 공간일 뿐이다. 내가 다시 할당해야함. 마치 C++의 포인터 배열과 같음.
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				arr[i][j] = new Data(sc.nextInt());
				arr[i][j].check = new int[10];
			}
		}
		sc.close();
		Stack<Triple> st = new Stack<>();

//check는 인덱스를 사용하기 때문에 크기가 10이지만 Data arr은 크기가 9이다.

		// 스도쿠의 제약사항을 더 빨리 알아채기 위해 Box별로 순회함.
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 3 * i; k < 3 * i + 3;) {
					for (int l = 3 * j; l < 3 * j + 3;) {		
						if (arr[k][l].num == 0) { // 빈칸일 때
							addCheckAll(arr, k, l);
							int cnt = getCount(arr[k][l].check);
							if (cnt == 0) {// 앞에서 잘못되었을 때 stack에서 이전 좌표를 꺼낸다.
								Triple before = st.peek();
								st.pop();
								k = before.x;
								l = before.y;
								arr[k][l].num = 0;// 0으로 만들어줘야함.
								while (getCount(arr[k][l].check) == 0) {
									arr[k][l].check[before.idx] = 0;// check도 다시 설정.
									before=st.peek();
									st.pop();
									
									k=before.x;
									l=before.y;
									arr[k][l].num=0;
									i=k/3;
									j=l/3;
									if (!(l< 3 * j + 3)) {
										--k;
									}
								}
								continue; // 뒤로 가는 것이기 때문에 st.push()없다.
							} else {//cnt != 0일 때
								for (int t = 1; t < arr[k][l].check.length; ++t) {
									if (arr[k][l].check[t] == 0) {
										arr[k][l].num = t;
										arr[k][l].check[t] = 1;// 한번 사용을 했으면 지운다. stack에서 꺼내서 다시 이 좌표로 왔을 때 다음 숫자를 선택해야
																// 하니까
//										System.out.printf("arr[%d][%d] : %d\n", k, l, arr[k][l].num);
//										printArr(arr);
//										System.out.println();
										st.push(new Triple(k, l, t));

										
										
										//다음 위치에 대한 check배열을 갱신.
										
										if (l+1 < 3 * j + 3) {
											resetCheckAll(arr, k, l+1);
										}
										else if (k+1 < 3  * i + 3){
											resetCheckAll(arr, k+1, 3*j);
										}
										else if (j+1 < 3){
											resetCheckAll(arr, 3*i, 3*(j+1));
										}
										else if (3*(i+1)<9 && 3*(j+1)<9){
											resetCheckAll(arr, 3*(i+1), 3*(j+1));
										}
										
										
										break;
									}//if end
								}

							}

							// else end

						}
						else {
							if (l+1 < 3 * j + 3) {
								resetCheckAll(arr, k, l+1);
							}
							else if (k+1 < 3  * i + 3){
								resetCheckAll(arr, k+1, 3*j);
							}
							else if (j+1 < 3){
								resetCheckAll(arr, 3*i, 3*(j+1));
							}
							else if (3*(i+1)<9 && 3*(j+1)<9){
								resetCheckAll(arr, 3*(i+1), 3*(j+1));
							}
						}

						++l;
					} // for_4 end
					++k;
				} // for_3 end
			}
		} // for_1 end
		printArr(arr);
	}// main end
}// class end
