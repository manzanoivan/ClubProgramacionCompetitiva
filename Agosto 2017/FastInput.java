import java.io.*;
import java.util.*;
import java.math.*;
public class FastInput{
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		/*
		int n      = sc.nextInt();        // read input as integer
		long k     = sc.nextLong();       // read input as long
		double d   = sc.nextDouble();     // read input as double
		String str = sc.next();           // read input as String
		String s   = sc.nextLine();       // read whole line as String
		BigInteger b = sc.nextBigInteger(); // read input as BigInteger
		out.println(result);                    // print via PrintWriter
		*/
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