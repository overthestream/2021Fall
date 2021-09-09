import java.util.Scanner;

public class B17608 {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt();
		int[] arr = new int[N];
		
		for(int i=0; i<arr.length; i++)
			arr[i] = scan.nextInt();
		
		int count = 1;		
		int maxHeight = arr[arr.length-1];
	
		for(int i=arr.length-2; i>=0; i--) {
			if(arr[i] > maxHeight) {
				count ++;
				maxHeight = arr[i];
			}
		}
		
		System.out.println(count);
		scan.close();
	}

}