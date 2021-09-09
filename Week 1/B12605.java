import java.util.*;
import java.io.*;

public class B12605 {
	
	public static void main(String[] args) throws IOException {
		
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int t = Integer.parseInt(st.nextToken());
		
		for(int i=1; i <= t; i++) {
			String[] Inputs = br.readLine().split(" ");
			StringBuilder reversed = new StringBuilder();
			
			for(int j=Inputs.length - 1; j > -1; j--) {
				reversed.append(Inputs[j]).append(" ");
			}
			
			sb.append("Case #").append(i).append(": ").append(reversed).append("\n");
		}
		System.out.println(sb.toString());
	}

}
