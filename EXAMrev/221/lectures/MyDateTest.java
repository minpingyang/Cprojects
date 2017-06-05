import static org.junit.Assert.*;

import java.util.Arrays;

import org.junit.Test;


public class MyDateTest {

	@Test
	public void testValid() {
		new MyDate(1,1,1);
		new MyDate(29,2,2012);
	}
	
	@Test
	public void testInvalid() {
		int[][] tests = generateInvalids();
		
		for(int[] test : tests) {
			System.out.println(Arrays.toString(test));
			try {		
				new MyDate(test[0],test[1],test[2]);
				fail("Should have failed (" + Arrays.toString(test) + ")");
			} catch(Exception e) {
				// here
			}
		}
	}

	public static final int NUM_TESTS = 1000;
	
	private int[][] generateInvalids() {
		int[][] tests = new int[NUM_TESTS][];
		for(int i=0;i<NUM_TESTS;++i) {
			tests[i] = generateInvalid();
		}		
		return tests;
	}
	
	public int[] generateInvalid() {
		int day = (int) (100 * Math.random());
		day = -day;
		return new int[]{day,1,1};
	}
}
