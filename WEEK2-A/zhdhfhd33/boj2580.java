//성공
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

	Data(int num) {
		this.num = num;
	}
}

public class Test {
	public static void printArr(Data arr[][]) {
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[0].length; ++j) {
				System.out.printf("%d ", arr[i][j].num);
			}
			System.out.println();
		}
	}

	// 전부 0으로 초기화
	public static void resetCheck(int check[]) {
		for (int i = 0; i < check.length; ++i) {
			check[i] = 0;
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
		int startRow = row / 3 * 3;// *3해줘야한다.
		int startCol = col / 3 * 3;
		for (int i = startRow; i < startRow + 3; ++i) {
			for (int j = startCol; j < startCol + 3; ++j) {
				arr[row][col].check[arr[i][j].num] = 1; // 이미 사용된 수 라면 1을 대입.
			}
		}
	}

	// arr[row][col].check을 초기화 한 후 현재 상황에서 arr[row][col].num에 넣을 수 있는 수를
	// arr[row][col].check에 저장.
	public static void resetCheckAll(Data arr[][], int row, int col) {
		try {
			resetCheck(arr[row][col].check);
			checkRowCol(arr, row, col);
			checkBox(arr, row, col);
		} catch (Exception e) {

		}
	}

	// arr[row][col].check을 초기화 하지 않고 현재 상황에서 arr[row][col].num에 넣을 수 있는 수를
	// arr[row][col].check에 저장.
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
								resetCheck(arr[k][l].check);// 고생함
								Triple before = st.peek();// 이놈 때문에 고생좀 했다.
								st.pop();
								k = before.x;
								l = before.y;
								arr[k][l].num = 0;// 0으로 만들어줘야함.
								while (getCount(arr[k][l].check) == 0) {// stack에서 꺼낸 좌표도 더이상 선택지가 없을 수 있기 때문에 선택지가 나타날
																		// 때 까지 stack에서 pop()
									resetCheck(arr[k][l].check);// 한번 이상 stack을 꺼낼 때만 resetCheck()해야한다.

									arr[k][l].num = 0;// num도 다시 0으로
									before = st.peek();
									st.pop();
									k = before.x;
									l = before.y;
									i = k / 3;
									j = l / 3;
								}
								arr[k][l].num = 0;// while에서 구한 새로운 k,l에 대해서도 해줘야함. - 마지막에 찾은 허점 ㅎㅎ...

								continue; // 변수 l에 대한 continue. l++안한다. 뒤로 가는 것이기 때문에 st.push()없다.
							} else {// cnt != 0일 때
								for (int t = 1; t < arr[k][l].check.length; ++t) {
									if (arr[k][l].check[t] == 0) {
										arr[k][l].num = t;
										arr[k][l].check[t] = 1;// 한번 사용을 했으면 지운다. stack에서 꺼내서 다시 이 좌표로 왔을 때 다음 숫자를 선택해야
																// 하니까

										// 아래는 디버깅할 때 사용한 출력문.
//										System.out.printf("arr[%d][%d] : %d\n", k, l, arr[k][l].num);
//										printArr(arr);
//										System.out.println();
										st.push(new Triple(k, l, t));
										break;
									} // if end
								}

							}

							// else end

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
