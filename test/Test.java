package Add;

import simtg.simops.base.SimopsException;

public class Test extends BaseTest {

	public static void main(String[] args) {
		new Test().run();
	}
	
	protected void test() throws SimopsException {
		
		sim.createObject("Add", "Satellite", "o");
		sim.init();
		float initialSun[] = {1, 1, 1};
		sim.writeFloatArray("o.In.u_sun", initialSun);
		
		for(int i = 0; i < 10; i++)
		{
			sim.step();
			float newSun[] = sim.readFloatArray("o.Out.u_sun_out");
			sim.writeFloatArray("o.In.u_sun", newSun);
			System.out.println(newSun[0] + ", " + newSun[1] + ", " + newSun[2]);
		}
		
		/*
		float I_Y_plus = 100;
		float I_Y_minus = 0;
		float I_Z_plus = 52;
		float I_Z_minus = 0;
		
		float y_angle;
		float z_angle;
		
		sim.createObject("Add", "Controller", "o");
		sim.init();

		sim.writeFloat("o.In.I_Y_plus", I_Y_plus);
		sim.writeFloat("o.In.I_Y_minus", I_Y_minus);
		sim.writeFloat("o.In.I_Z_plus", I_Z_plus);
		sim.writeFloat("o.In.I_Z_minus", I_Z_minus);
		
		sim.activateMethodCyclically("o.step", 1);
		for(int i = 0; i < 300; i++)
		{
			sim.step();
			y_angle = sim.readFloat("o.Out.y_angle");
			z_angle = sim.readFloat("o.Out.z_angle");
			sim.writeFloat("o.In.I_Y_plus", -y_angle);
			sim.writeFloat("o.In.I_Y_minus", 0);
			sim.writeFloat("o.In.I_Z_plus", -z_angle);
			sim.writeFloat("o.In.I_Z_minus", 0);
			
			System.out.println(y_angle + ", " + z_angle);
		}*/
		
		System.out.println("Success!");
	}

}
