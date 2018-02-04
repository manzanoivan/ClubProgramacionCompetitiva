import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int N, F, casos = 1;
		while( true ){
			N = sc.nextInt();
			F = sc.nextInt();

			if( N == 0 ) break;

			BigInteger acum = BigInteger.ZERO;
			for( int i = 0; i < N; i++ ){
				acum = acum.add(sc.nextBigInteger());
			}
			out.println( "Bill #" + casos++ + " costs "+ acum +": each friend should pay "+ acum.divide( BigInteger.valueOf( F ) ) +"\n" );
		}
		out.close();
	}

	public static PrintWriter out;
	public static class MyScanner{
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		BigInteger nextBigInteger() {
			return new BigInteger(next());
		}
		String nextLine(){
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	 }
}