import java.util.Scanner;
import java.util.ArrayList;

class Pair {
	int x;
	int y;

	Pair(int x, int y) {
		this.x = x;// 깊이
		this.y = y;// 좌우
	}

}

public class Main {

	// 시작 번호를 주면 도착점을 알려줌.
	public static int play(int arr[][], int start) {
		Pair cur = new Pair(0, start); // 사다리의 정보를 표현하는 table과 실제 게임이 굴러가는 판을 다르게 보자.
		for (int i = 0; i < arr.length; ++i) {
			cur.x = i;// 한칸 한칸 내려갈 때 마다 cur 갱신.
			if (cur.y <= arr[0].length - 1 && arr[i][cur.y] == 1) {
				++cur.y;
			} else if (cur.y - 1 >= 0 && arr[i][cur.y - 1] == 1) {
				--cur.y;
			}

		}
		return cur.y;
	}

	// i번째가 i에게 가는지 판단. 성공하면 -1을 반환. 실패하면 어떤 녀석이 실패했는지를 반환.
	public static int playAll(int arr[][]) {

		for (int i = 0; i < arr[0].length+1; ++i) {
			if (i != play(arr, i)) {
				return i;
			}
		}
		return -1;

	}

	// 이렇게 작성하는 것 보다 있을 때 바로 false를 반환하는 것이 짧고 편하다.
	public static boolean isLadderOk(int arr[][], int a, int b) {
		boolean left = false, right = false;
		if (arr[a][b] == 1)
			return false;
		if (b - 1 < 0) {
			left = true;// left, right 둘다 true이면 true를 반환.
		} else {
			left = arr[a][b - 1] == 0;
		}

		if (b + 1 >= arr[0].length) {
			right = true;
		} else {
			right = arr[a][b + 1] == 0;
		}
		return left && right;
	}

	// 사다리를 1개 추가했을 때 성공여부를 반환
	public static boolean simul_1(int arr[][]) {
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[0].length; ++j) {
				if (isLadderOk(arr, i, j) == true) { // 사다리를 놓을 수 있다면
					arr[i][j] = 1;
					int key = playAll(arr);
					if (-1 == key) { // 성공했다면 바로 true반환.
						return true;
					} 
					arr[i][j] = 0;
				}
			}
		}
		return false;// 반복문을 다돌았는데도 안되면 실패임.
	}

	// isLadderOk()가 된 자리들을 ArList로 반환한다. 조합을 구하기 위해서는 배열이 필요함.
	public static ArrayList<Pair> getVector(int arr[][]) {
		ArrayList<Pair> res=new ArrayList<>();
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[0].length; ++j) {
				if (isLadderOk(arr, i, j) == true) { // 사다리를 놓을 수 있다면
					res.add(new Pair(i, j));
				}
			}
		}
		return res;
	}

	public static boolean simul_2(int arr[][]) {
		ArrayList<Pair> vec = getVector(arr);
		final int SIZE = vec.size();
		for (int i = 0; i < SIZE; ++i) {
			for (int j = i + 1; j < SIZE; ++j) {
				Pair a = vec.get(i);
				Pair b = vec.get(j);
				arr[a.x][a.y] = 1;
				arr[b.x][b.y] = 1;
				int key = playAll(arr);
				if (-1 == key) { // 성공했다면 바로 true반환.
					return true;
				} 
				arr[a.x][a.y] = 0;
				arr[b.x][b.y] = 0;

			}
		}
		return false;
	}

	public static boolean simul_3(int arr[][]) {
		ArrayList<Pair> vec = getVector(arr);
		final int SIZE = vec.size();
		for (int i = 0; i < SIZE; ++i) {
			for (int j = i + 1; j < SIZE; ++j) {
				for (int k = j + 1; k < SIZE; ++k) {// 3개의 조합이라서 반복문 3개를 사용.
					Pair a = vec.get(i);
					Pair b = vec.get(j);
					Pair c = vec.get(k);
					arr[a.x][a.y] = 1;
					arr[b.x][b.y] = 1;
					arr[c.x][c.y] = 1;
					int key = playAll(arr);
					if (-1 == key) { // 성공했다면 바로 true반환.
						return true;
					} 
//					

					arr[a.x][a.y] = 0;
					arr[b.x][b.y] = 0;
					arr[c.x][c.y] = 0;
				}
			}
		}
		return false;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N, M, H;
		N = sc.nextInt();
		M = sc.nextInt();
		H = sc.nextInt();

		// 연결을 표현하는 표. row = a, col = b를 의미, 0으로 자동 초기화
		int arr[][] = new int[H][N - 1];// 막대기 번호는 0번부터 시작

		// 사다리 생성
		for (int i = 0; i < M; ++i) {
			int a, b;
			a = sc.nextInt() - 1;// 나는 사다리가 0부터 시작.
			b = sc.nextInt() - 1;
			arr[a][b] = 1;
		}
		
		if (-1==playAll(arr)) {
			System.out.print("0");

		}
		else if (simul_1(arr)) {
			System.out.print("1");
		} else if (simul_2(arr)) {
			System.out.print("2");
		} else if (simul_3(arr)) {
			System.out.print("3");
		} else {
			System.out.print("-1");
		}

	}

}
