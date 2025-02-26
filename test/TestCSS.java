package Add;

import simtg.simops.base.SimopsException;

public class TestCSS extends BaseTest {

	public static void main(String[] args) {
		new TestCSS().run();
	}

	protected void test() throws SimopsException {
		sim.createObject("Add", "CSS", "o");
		// sim.init();
		// sim.activateMethodCyclically("o.step",1);
		// sim.step();
		
		System.out.println("\n============ Test 1: zero - eclipse START ============");
		// PARAMETERS
		float test[] = { 0, 0, 0 };
		int e = 0;	//0 if satellite in earth shadow...
		sim.writeFloatArray("o.In.u_sun_SC", test);
		sim.writeInt("o.In.e", e);
		sim.timeStep(1.);
		// INPUTS DESC.
		System.out.println("Beginning test with the following inputs: \n" 
				+ "u_sun:\t{ 0, 0, 0 }\n" + "e:\t" + e);
		// TEST CASE
		if(
			sim.checkFloat("o.Out.Current_Y_plus", 0) &&
			sim.checkFloat("o.Out.Current_Y_minus", 0) &&
			sim.checkFloat("o.Out.Current_Z_plus", 0) &&
			sim.checkFloat("o.Out.Current_Z_minus", 0)
				)   
		
		{System.out.println("Success!");} 
		else {System.out.println("Test failed...");}
		System.out.println("============ Test END ============\n");
		
		
		// TEST 2
		System.out.println("\n============ Test 2: real values for u, e = 0 START ============");
		// PARAMETERS
		float test2[] = { 1, 0, 1 };
		sim.writeFloatArray("o.In.u_sun_SC", test2);
		sim.writeInt("o.In.e", e);
		sim.init();
		sim.step();
		sim.timeStep(1.);
		// INPUTS DESC.
		System.out.println("Beginning test with the following inputs: \n" 
				+ "u_sun:\t{ 1, 0, 0 }\n" + "e:\t" + e);
		// TEST CASE
		if(
			sim.checkFloat("o.Out.Current_Y_plus", 0) &&
			sim.checkFloat("o.Out.Current_Y_minus", 0) &&
			sim.checkFloat("o.Out.Current_Z_plus", 0) &&
			sim.checkFloat("o.Out.Current_Z_minus", 0)
				)   
		
		{System.out.println("Success!");} 
		else {System.out.println("Test failed...");}
		System.out.println("============ Test END ============\n");
		
		// TEST 3
		System.out.println("\n============ Test 3: real values for u, e = 1 START ============");
		// PARAMETERS
		int e3 = 1;
		sim.writeFloatArray("o.In.u_sun_SC", test2);
		sim.writeInt("o.In.e", e3);
		sim.init();
		sim.step();
		sim.timeStep(1.);
		// INPUTS DESC.
		System.out.println("Beginning test with the following inputs: \n" 
				+ "u_sun:\t{ 1, 0, 0 }\n" + "e:\t" + e3);
		// TEST CASE
		if(
			sim.checkFloat("o.Out.Current_Y_plus", 0) &&
			sim.checkFloat("o.Out.Current_Y_minus", 0) &&
			sim.checkFloat("o.Out.Current_Z_plus", 0) &&
			sim.checkFloat("o.Out.Current_Z_minus", 0)
				)   
		
		{System.out.println("Success!");} 
		else {System.out.println("Test failed...");}
		System.out.println("============ Test END ============\n");

	}
}
