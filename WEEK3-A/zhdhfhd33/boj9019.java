import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//path는 경로이면서 동시에 명령을 뜻함. path의 가장 마지막 문자는 수행해야하는 명령을 가리킨다.
class Unit{
	String str;
	String path;
	Unit(String str, String path){
		this.str=str;
		this.path=path;
	}
	//정상동작하지 않으면 null반환
	public String doCommand() {
		switch (path.charAt(path.length()-1)) {
		case 'D' : 
			return Main.D(str);
		case 'S' :
			return Main.S(str);
		case 'L' :
			return Main.L(str);
		case 'R' :
			return Main.R(str);
		default :
			return null;
		}
		
	}
	//정상동작하지 않으면 E반환
//	public char nextCommand() {
//		char last = path.charAt(path.length()-1);
//		char command[] = {'D', 'S', 'L', 'R'};
//		for (int i=0; i<command.length; ++i) {
//			if (last==command[i]) return command[(i+1)%4];
//		}
//		return 'E';
//	}
	
	public String toString() {
		return "path : "+path+" str : "+str;
	}
}
public class Main {
	public static String D(String str) {
//		String copy = String.valueOf(str);
		int num = Integer.valueOf(str);
		num = 2 * num % 10000; 
		return Integer.toString(num);
	}

	public static String S(String str) {
//		String copy = String.valueOf(str);
		int num = Integer.valueOf(str);
		num = num - 1 <= -1 ? 9999 : num - 1;
		return Integer.toString(num);
	}

	public static String L(String str) {
		char ch[]=new char[4];
		//0으로 초기화. char배열은 생성하면 ''으로 초기화 되어있음.
		for (int i=0; i<ch.length; ++i) {
			ch[i]='0';
		}
		//str->ch 복사
		for (int i=str.length()-1, idx=ch.length-1; i>=0; --i, --idx) {
			ch[idx]=str.charAt(i);
		}
				
		char tmp=ch[0];
		for(int i=0; i+1<ch.length; ++i) {
			ch[i]=ch[i+1];
		}
		ch[ch.length-1]=tmp;
		return String.valueOf(ch);
	}

	public static String R(String str) {
		char ch[]=str.toCharArray();
		char tmp=ch[str.length()-1];
		for(int i=str.length()-1; i-1>=0; --i) {
			ch[i]=ch[i-1];
		}
		ch[0]=tmp;
		return String.valueOf(ch);
		
	}
//	public static String removeZero(String str) {
//		int start=0, end=str.length()-1;
//		while (str.charAt(start)=='0') {
//			++start;
//		}
//		
//		while (str.charAt(end)=='0') {
//			--end;
//		}
//		return str.substring(start, end+1);
//		
//	}

	//bfs를 이용. 이런 형태를 위해서는 Q를 사용할 수 밖에 없나봄. 반복문으로 될줄 알았는데
	//D=0, S=1, L=2, R=3
	//실패시 null반환
	public static Unit solve(String start, String end) {
		Queue<Unit> q=new LinkedList<>();
		String command[]= {"D", "S", "L", "R"};
		//초기조건
		for (int i=0; i<4; ++i) {
			q.add(new Unit(start, command[i]));
		}
		
		while (!q.isEmpty()) {
			Unit a=q.poll();
			if (Integer.valueOf(a.str).equals(Integer.valueOf(end))) {
//				q.clear();//시간초과나서 시도해봤으나 똑같음.
				return a; //처음부터 같을 수도 있잖아. doCommand()하기전에 검사하자.
			}
			a.str=a.doCommand();
			
			for (int i=0; i<command.length; ++i) {
				q.add(new Unit(a.str, a.path+command[i]));
			}
		}
		return null;
	}

	public static void main(String[] args) {
		int T;
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		while (T-- != 0) {
			String a, b;
			a = sc.next();
			b = sc.next();

			Unit res = solve(a, b);
//			System.out.println(res.str);
			System.out.println(res.path.substring(0, res.path.length()-1));
		}
		sc.close();
	}

}
