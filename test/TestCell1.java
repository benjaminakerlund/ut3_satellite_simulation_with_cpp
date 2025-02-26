package Add;

import simtg.simops.base.SimopsException;

public class TestCell1 extends BaseTest {

	public static void main(String[] args) {
		new TestCell1().run();
	}

	protected void test() throws SimopsException {
		sim.createObject("Add", "Cell", "o");
		// sim.activateMethodCyclically("o.step",1);
		// sim.step();
		
		System.out.println("\n============ Test 1: zero all START ============");
		// PARAMETERS
		float test[] = { 0.0f, 0.0f, 0.0f };
		float k[] = {0.0f, 0.0f, 0.0f, 0.0f};
		int e = 0;	//0 if satellite in earth shadow...
		sim.writeFloatArray("o.In.u_sun", test);
		sim.writeFloatArray("o.In.k", k);
		sim.writeInt("o.In.e", e);
		sim.writeInt("o.In.axis", 0);
		//sim.timeStep(1.);
		// INPUTS DESC.
		sim.init();
		sim.step();
		System.out.println("Beginning test with the following inputs: \n" 
				+ "u_sun:\t{ 0, 0, 0 }\n" + "k:\t{0, 0, 0, 0}" + "\n" + "e:\t" + e);
		// TEST CASE
		if(sim.checkFloat("o.Out.I_cell", 0)) {System.out.println("Success!");} 
		else {System.out.println("Test failed...");}
		System.out.println("============ Test END ============\n");
		
		
		System.out.println("\n============ Test 2: real values for u, k and e = 0 START ============");
		// PARAMETERS
		float test2[] = { 1.0f, 0.0f, 0.0f };
		sim.writeFloatArray("o.In.u_sun", test2);
		sim.writeFloatArray("o.In.k", k);
		sim.writeInt("o.In.e", e);
		sim.writeInt("o.In.axis", 0);
		// INPUTS DESC.
		sim.init();
		sim.step();
		System.out.println("Beginning test with the following inputs: \n" 
				+ "u_sun:\t{ 1, 0, 0 }\n" + "k:\t{0, 0, 0, 0}" + "\n" + "e:\t" + e);
		// TEST CASE
		if(sim.checkFloat("o.Out.I_cell", 0)) {System.out.println("Success!");} 
		else {
			System.out.println("Test failed...");
			System.out.println(sim.readFloat("o.Out.I_cell"));
		}
		System.out.println("============ Test END ============\n");

		
		System.out.println("\n============ Test 3: real values for u and k, e = 0 START ============");
		// PARAMETERS
		float k3[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		sim.writeFloatArray("o.In.u_sun", test2);
		sim.writeFloatArray("o.In.k", k3);
		sim.writeInt("o.In.e", e);
		sim.writeInt("o.In.axis", 0);
		sim.init();
		sim.step();
		sim.timeStep(1.);
		// INPUTS DESC.
		System.out.println("Beginning test with the following inputs: \n" 
				+ "u_sun:\t{ 1, 0, 0 }\n" + "k:\t{1, 1, 1, 1}" + "\n" + "e:\t" + e);
		// TEST CASE
		if(sim.checkFloat("o.Out.I_cell", 0)) {System.out.println("Success!");} 
		else {System.out.println("Test failed...");}
		System.out.println("============ Test END ============\n");
		
		System.out.println("\n============ Test 4: real and specific values for all START ============");
		// PARAMETERS
		int e4 = 1;
		sim.writeFloatArray("o.In.u_sun", test2);
		sim.writeFloatArray("o.In.k", k3);
		sim.writeInt("o.In.e", e4);
		sim.writeInt("o.In.axis", 0);
		sim.init();
		sim.step();
		sim.timeStep(1.);
		// INPUTS DESC.
		System.out.println("Beginning test with the following inputs: \n" 
				+ "u_sun:\t{ 1, 0, 0 }\n" + "k:\t{1, 1, 1, 1}" + "\n" + "e:\t" + e4);
		// TEST CASE
		if(sim.checkFloat("o.Out.I_cell", 0.010825224571338f)) {System.out.println("Success!");} 
		else {System.out.println("Test failed...");}
		System.out.println("============ Test END ============\n");
		
		
		System.out.println("\n============ Test 5: specific values for all START ============");
		// PARAMETERS
		float test5[] = {0.0f, 1.0f, 1.0f};
		sim.writeFloatArray("o.In.u_sun", test5);
		sim.writeFloatArray("o.In.k", k3);
		sim.writeInt("o.In.e", e4);
		sim.writeInt("o.In.axis", 0);
		sim.init();
		sim.step();
		sim.timeStep(1.);
		// INPUTS DESC.
		System.out.println("Beginning test with the following inputs: \n" 
				+ "u_sun:\t{ 0, 1, 1 }\n" + "k:\t{1, 1, 1, 1}" + "\n" + "e:\t" + e4);
		// TEST CASE
		if(sim.checkFloat("o.Out.I_cell", 0.028742661027327f)) {System.out.println("Success!");} 
		else {System.out.println("Test failed...");}
		System.out.println("============ Test END ============\n");
	}
}
