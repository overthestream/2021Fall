import java.util.Scanner;
import java.util.Vector;

class Pair {
	int x;
	int y;

	Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public String toString() {
		String res = "x : " + x + " y : " + y;
		return res;
	}
}

enum Direction {
	UP, DOWN, LEFT, RIGHT;

}

public class Main {
	// 값, idx를 반환 다음 번 숫자가 없으면 null 반환
	public static Pair nextRight(int arr[][], int x, int y) {
		for (int i = y + 1; i < arr.length; ++i) {
			if (arr[x][i] != 0) {
				return new Pair(arr[x][i], i);
			}
		}
		return null;
	}

	public static Pair nextLeft(int arr[][], int x, int y) {
		for (int i = y - 1; i >= 0; --i) {
			if (arr[x][i] != 0) {
				return new Pair(arr[x][i], i);
			}
		}
		return null;
	}

	public static Pair nextDown(int arr[][], int x, int y) {
		for (int i = x + 1; i < arr.length; ++i) {
			if (arr[i][y] != 0) {
				return new Pair(arr[i][y], i);
			}
		}
		return null;
	}

	public static Pair nextUp(int arr[][], int x, int y) {
		for (int i = x - 1; i >= 0; --i) {
			if (arr[i][y] != 0) {
				return new Pair(arr[i][y], i);
			}
		}
		return null;
	}

	// 겹쳐지는 녀석들의 index를 vec으로 반환.(값도 같을 때 벡터에 들어감.) 처음에는 dir 매개변수를 받았는데 생각해보니 방향은
	// 상관없음.
	public static Vector<Integer> getRowVec(int arr[][], int a) {
		Vector<Integer> res = new Vector<>();// res에는 인덱스가 들어간다.
		for (int i = 0; true;) {
//			if (arr[a][i]==0) continue; 없어도 잘 돌아간다. 

			Pair p = nextRight(arr, a, i);
			if (p == null) {// 다음번이 없을 떄
				return res;
			}
			if (p.x == arr[a][i]) {
//				if (res.size() == 0)
				if (!res.isEmpty() ) {
					if (res.lastElement() != i) {
						
						res.add(i);
					}
				}
				
				else {
					res.add(i);
				}
				res.add(p.y);

			}
			i = p.y;
		} // for end
	}

	public static Vector<Integer> getColVec(int arr[][], int a) {
		Vector<Integer> res = new Vector<>();// res에는 인덱스가 들어간다.
		for (int i = 0; true;) {
//			if (arr[a][i]==0) continue; 없어도 잘 돌아간다. 

			Pair p = nextDown(arr, i, a);
			if (p == null) {// 다음번이 없을 떄
				return res;
			}
			if (p.x == arr[i][a]) {
				if (!res.isEmpty()  ) {
					if (res.lastElement() != i) {
						
						res.add(i);
					}
				}
				else {
					res.add(i);
				}

				res.add(p.y);

			}
			i = p.y;
		} // for end
	}

	// 역전시키는 함수
	public static void reverse(Vector<Integer> vec) {
		for (int i = 0, j = vec.size() - 1; i < j; ++i, --j) {
			int temp = vec.get(i);
			vec.set(i, vec.get(j));
			vec.set(j, temp);
		}
	}

	public static void moveLeft(int arr[][]) {
		for (int i = 0; i < arr.length; ++i) {
			Vector<Integer> vec = getRowVec(arr, i);
			final int SIZE = vec.size();
			for (int j = 0; j + 1 < SIZE; j += 2) {// 합쳐지는 녀석들을 겹친다.
				arr[i][vec.get(j)] += arr[i][vec.get(j + 1)];
				arr[i][vec.get(j + 1)] = 0;
			}

			// 이제 왼쪽으로 모두 밀어넣기
			for (int j = 0; j < arr.length; ++j) {
				if (arr[i][j] == 0) {// 비어있을 때만 진행
					Pair p = nextRight(arr, i, j);
					if (p == null) {
						break;
					}
					arr[i][j] = p.x;
					arr[i][p.y] = 0;
				}
			}
		}
	}

	public static void moveRight(int arr[][]) {
		for (int i = 0; i < arr.length; ++i) {
			Vector<Integer> vec = getRowVec(arr, i);
			reverse(vec);

			final int SIZE = vec.size();
			for (int j = 0; j + 1 < SIZE; j += 2) {// 합쳐지는 녀석들을 겹친다.
				arr[i][vec.get(j)] += arr[i][vec.get(j + 1)];
				arr[i][vec.get(j + 1)] = 0;
			}

			// 이제 오른쪽으로 모두 밀어넣기
			for (int j = arr.length - 1; j >= 0; --j) {
				if (arr[i][j] == 0) {// 비어있을 때만 진행
					Pair p = nextLeft(arr, i, j); // right에서는 nextLeft()를 호출해야함.
					if (p == null) {
						break;
					}
					arr[i][j] = p.x;
					arr[i][p.y] = 0;
				}
			}
		}
	}

	public static void moveDown(int arr[][]) {
		for (int i = 0; i < arr.length; ++i) {
			Vector<Integer> vec = getColVec(arr, i);
			reverse(vec);
			final int SIZE = vec.size();
			for (int j = 0; j + 1 < SIZE; j += 2) {// 합쳐지는 녀석들을 겹친다.
				arr[vec.get(j)][i] += arr[vec.get(j + 1)][i];
				arr[vec.get(j + 1)][i] = 0;
			}

			// 이제 아래쪽으로 모두 밀어넣기
			for (int j = arr.length - 1; j >= 0; --j) {
				if (arr[j][i] == 0) {// 비어있을 때만 진행
					Pair p = nextUp(arr, j, i); // right에서는 nextLeft()를 호출해야함.
					if (p == null) {
						break;
					}
					arr[j][i] = p.x;
					arr[p.y][i] = 0;
				}
			}
		}
	}

	public static void moveUp(int arr[][]) {
		for (int i = 0; i < arr.length; ++i) {
			Vector<Integer> vec = getColVec(arr, i);
//			reverse(vec);
			final int SIZE = vec.size();
			for (int j = 0; j + 1 < SIZE; j += 2) {// 합쳐지는 녀석들을 겹친다.
				arr[vec.get(j)][i] += arr[vec.get(j + 1)][i];
				arr[vec.get(j + 1)][i] = 0;
			}

			// 이제 위쪽으로 모두 밀어넣기
			for (int j = 0; j < arr.length; ++j) {
				if (arr[j][i] == 0) {// 비어있을 때만 진행
					Pair p = nextDown(arr, j, i); // right에서는 nextLeft()를 호출해야함.
					if (p == null) {
						break;
					}
					arr[j][i] = p.x;
					arr[p.y][i] = 0;
				}
			}
		}
	}

	public static void printArr(int arr[][]) {
		for (int i = 0; i < arr.length; ++i) {

			for (int j = 0; j < arr.length; ++j) {
				System.out.printf("%d ", arr[i][j]);
			}
			System.out.println();

		}

	}

	public static void move(int arr[][], Direction dir) {
		switch (dir) {
		case UP:
			moveUp(arr);
			break;
		case DOWN:
			moveDown(arr);
			break;
		case LEFT:
			moveLeft(arr);
			break;
		case RIGHT:
			moveRight(arr);
			break;
		default:
			System.out.println("move()의 dir인자가 잘못들어옴");
			break;
		}
	}

	public static int getMax(int arr[][]) {
		int res = 0;
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr.length; ++j) {
				if (arr[i][j] > res) {
					res = arr[i][j];
				}
			}

		}
		return res;
	}

	public static int[][] getClone(int arr[][]) {
		int copy[][] = new int[arr.length][arr[0].length];
		for (int i = 0; i < arr.length; ++i) {
			// 1배열의 이름을 전달하네
			System.arraycopy(arr[i], 0, copy[i], 0, arr[0].length);
		}
		return copy;
	}

	// DP를 가미해서 풀어보자.
	// main에서는 solve(arr, dir, 0, 0)으로 시작하면 됨
	public static int solve(int arr[][], Direction dir[], int cnt) {
		// cnt는 0부터 시작. cnt=5는 6번째 호출을 의미함.
		if (cnt == 5) {
			return getMax(arr);// max는 한번만 계산하면 된다.
		}

		int max = 0;
		for (int i = 0; i < dir.length; ++i) {
			int copy[][] = getClone(arr);
			move(copy, dir[i]);

//			System.out.println(dir[i]);
//			System.out.println("cnt : " + cnt);
//			printArr(copy);
//			System.out.println();

			int temp = solve(copy, dir, cnt + 1);
			max = max < temp ? temp : max;
		}
		return max;

	}

	public static void main(String[] args) {
		int N;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		int arr[][] = new int[N][N]; // 자동 0

		// arr입력
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				arr[i][j] = sc.nextInt();
		sc.close();

		// 4^5의 경우의 수를 모두 탐색해서 가장 큰 값을 가져오면 된다.
		Direction dir[] = new Direction[4];
		dir[0] = Direction.LEFT;
		dir[1] = Direction.RIGHT;
		dir[2] = Direction.UP;
		dir[3] = Direction.DOWN;

		// DP적인 요소를 넣어서 해결하자.
		int max = solve(arr, dir, 0);
		System.out.print(max);
//		
//		moveUp(arr);
//		printArr(arr);
//
//		moveRight(arr);
//		printArr(arr);
//
//		moveRight(arr);
//		printArr(arr);
//
//		moveRight(arr);
//		printArr(arr);
//
//		moveRight(arr);
//		printArr(arr);

	}

}
