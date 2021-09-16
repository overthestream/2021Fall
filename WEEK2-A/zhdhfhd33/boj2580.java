//런타임에러

import java.util.Scanner;
import java.util.Stack;

class Pair{
	int x;
	int y;
	Pair(int x, int y){
		this.x=x;
		this.y=y;
	}
	          
}             
class Data{
	int num;
	int[] check; //초기화 하지 않으면 자동 null대입.
 
	Data(int num){
		this.num=num;
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

	// -1을 넣으면 row 또는 col을 고정시킬 수 있다. 둘 다 숫자를 넣으면
	public static int[] checkLine(Data arr[][], int row, int col) {
		int check[] = new int[10]; // 0으로 초기화 되어 있음.

		if (row == -1) {
			for (int i = 0; i < arr.length; ++i) {
				
				check[arr[i][col].num] = 1;// 1이 대입되어 있으면 이미 사용된 애들.
			}
		} else if (col == -1) {
			for (int i = 0; i < arr.length; ++i) {
				check[arr[row][i].num] = 1;// 1이 대입되어 있으면 이미 사용된 애들.
			}
		} else {
			System.out.println("checkLine() 매개변수를 잘못입력함");
		}
		return check;
	}

	// row, col을 한번에 검사가능.
	public static int[] checkRowCol(Data arr[][], int row, int col) {
		int temp1[] = checkLine(arr, -1, col);
		int temp2[] = checkLine(arr, row, -1);
		for (int i = 1; i < temp1.length; ++i) {
			if (temp2[i] == 1) {
				temp1[i] = 1;
			}
		}
		return temp1;
	}

	// 자신의 좌표를 전달하면 3*3 box안에서의 남은 수를 반환함.
	public static int[] checkBox(Data arr[][], int row, int col) {
		int check[] = new int[10];
		int startRow = row / 3 *3;//*3해줘야한다.
		int startCol = col / 3 *3;
		for (int i = startRow; i < startRow + 3; ++i) {
			for (int j = startCol; j < startCol + 3; ++j) {
				check[arr[i][j].num] = 1; // 이미 사용된 수 라면 1을 대입.
			}
		}
		return check;
	}

	// 이렇게 몇개의 작은 함수로 나눠 작성하면 보기에는 쉽고 코드 짤 때는 쉬운데 check를 계속 만들고 합치고 해야하니 효율적인 방법은 아닌
	// 듯.
	public static int[] checkAll(Data arr[][], int row, int col) {
		int temp1[] = checkRowCol(arr, row, col);
		int temp2[] = checkBox(arr, row, col);
		for (int i = 1; i < temp1.length; ++i) {
			if (temp2[i] == 1) {
				temp1[i] = 1;
			}
		}
		return temp1;
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
		Data arr[][] = new Data[9][9]; //java에서 내가 만든 객체의 배열은 공간일 뿐이다. 내가 다시 할당해야함. 마치 C++의 포인터 배열과 같음.
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				arr[i][j] = new Data(sc.nextInt());
			}
		}
		sc.close();

//		for (int i=0; i<10; ++i) {
//			for(int j=0; j<10; ++j) {
//				if (arr[i][j]==0) {
//					int check[]=checkAll(arr, i, j);
//					
//				}
//			}
//		}
		
		Stack<Pair> st =  new Stack<>();
		
//check는 인덱스를 사용하기 때문에 크기가 10이지만 Data arr은 크기가 9이다.
		
		// 스도쿠의 제약사항을 더 빨리 알아채기 위해 Box별로 순회함.
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 3 * i; k < 3 * i + 3; ++k) {
					for (int l = 3 * j; l < 3 * j + 3; ++l) {
						if (arr[k][l].num==0) { //빈칸일 때
							
							arr[k][l].check = checkAll(arr, k, l);
							int cnt = getCount(arr[k][l].check);
							if (cnt==0) {//앞에서 잘못되었을 때 stack에서 이전 좌표를 꺼낸다.
								Pair before = st.peek();
								st.pop();
								k=before.x;//++k은 안되기 때문에 놔둬야함.
								l=before.y-1;//++l되기 때문에 -1해줌.
								continue;
							}
							else {
								for (int t=1; t<arr[k][l].check.length; ++t) {
									if (arr[k][l].check[t]==0) {
										arr[k][l].num=t;
										arr[k][l].check[t]=1;//한번 사용을 했으면 지운다. stack에서 꺼내서 다시 이 좌표로 왔을 때 다음 숫자를 선택해야 하니까
									}
								}
							}//else end
							
							
							st.push(new Pair(k, l));
						}
					}//for_4 end
				}
			}
		}//for_1 end
printArr(arr);
	}//main end
}//class end


