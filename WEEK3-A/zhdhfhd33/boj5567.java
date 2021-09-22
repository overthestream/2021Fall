import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

	//문제에서 요구하는 값인 cnt를 반환
  //전체를 순회하지 않고 2번까지만 순회하게 했다.
	public static int bfs(int graph[][]) {
		int cnt=0;
		int isVisited[]=new int[graph[0].length];
		isVisited[0]=1;//자신은 세지 않으므로 미리 방문처리함
		Queue<Integer> q=new LinkedList<Integer>();
		for (int i=0;i<graph[0].length; ++i) {
			if (graph[0][i]==1) {
				q.add(i);
				isVisited[i]=1;
				++cnt;
				//코딩할 때는 행렬보다 리스트배열이 편한 듯.
			}
		}
//		cnt-=q.size()-1;
		while(!q.isEmpty()) {
			int a=q.peek();
			q.remove();
//			if (isVisited[a]!=0) continue; 큐에 넣은 다음 방문처리를 했기 때문에 여기서 isVisted를 검사하면 안된다.
			for (int i=0; i<graph[0].length; ++i) {
				if (graph[a][i]==1 && isVisited[i]==0) {//여기서 검사해야함.
					++cnt;
					isVisited[i]=1;
				}
			}
		}
		return cnt;
	}
	public static void main(String[] args) {
		int n, m;
		Scanner sc = new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();
		
		//graph생성
		int graph[][]=new int[n][n];
		for (int i=0; i<m; ++i) {
			int a, b;
			a=sc.nextInt()-1;
			b=sc.nextInt()-1;
			graph[a][b]=1;
			graph[b][a]=1;
		}
		sc.close();
		int res=bfs(graph);
		System.out.println(res);
	}

}
