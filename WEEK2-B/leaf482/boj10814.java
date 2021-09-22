import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class boj10814 {
	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		int N = in.nextInt();
		String[][] arr = new String[N][2];

		for (int i = 0; i < N; i++) {
			arr[i][0] = in.next();
			arr[i][1] = in.next();
		}

		Arrays.sort(arr, new Comparator<String[]>() {
			@Override
			public int compare(String[] s1, String[] s2) {
				return Integer.parseInt(s1[0]) - Integer.parseInt(s2[0]);
			}

		});

		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < N; i++) {
			sb.append(arr[i][0]).append(' ').append(arr[i][1]).append('\n');
		}

		System.out.println(sb);

	}

}