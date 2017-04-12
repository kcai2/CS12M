// $Id: hello.java,v 1.4 2015-01-12 15:02:30-08 - - $
// Author:Kevin Cai, kcai2@ucsc.edu
public class hello {
	public static void main(String[] args) {
		if (args.length == 0) {
			System.out.printf("Hello, World!%n");
			System.exit(0);
		} else {
			System.err.printf("Usage: hello%n");
			System.exit(1);
		}
	}
}
