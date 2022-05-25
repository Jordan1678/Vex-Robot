#pragma config(Motor,  port2,           RightRear,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           RightFront,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           LeftRear,     tmotorVex393, openLoop)
#pragma config(Motor,  port5,           LeftFront,     tmotorVex393, openLoop)
#pragma config(Motor,  port6,           ArmLift,     tmotorVex393, openLoop)
#pragma config(Motor,  port8,           Bucket,     tmotorVex393, openLoop)


// Arm Control Map
char ArmUP = Btn5U;
char ArmDown = Btn5D;

// Bucket Control Map

task main ()
{

	while(1 == 1)
	{
		motor[RightRear]  = (vexRT[Ch2] + vexRT[Ch1] * -1)/2;  // (y + x)/2
		motor[RightFront] = (vexRT[Ch2] + vexRT[Ch1] * -1)/2;  // (y - x)/2
		motor[LeftRear] = (vexRT[Ch2] - vexRT[Ch1] * -1)/2;
		motor[LeftFront] = (vexRT[Ch2] - vexRT[Ch1] * -1)/2;

		// Lift Arm
		if(vexRT[ArmUP] == 1)       			//If button is pressed...
		{
			motor[ArmLift] = 32;    				//...raise the arm.
			
		} else if(vexRT[ArmDown] == 1) { 	//Else, if button is pressed...
			motor[ArmLift] = -32;   				//...lower the arm.
			
		} else {                  				//Else (neither button is pressed)...
			motor[ArmLift] = 0;      				//...stop the arm.
			
		}

// Open, close or do not more claw
		if(vexRT[Btn6U] == 1) {       	//If Button 6U is pressed...
			motor[Bucket] = 65;  			//...close the gripper.
			
		} else if(vexRT[Btn6D] == 1) { 	//Else, if button 6D is pressed...
			motor[Bucket] = -65; 			//...open the gripper.
			
		} else {                      	//Else (neither button is pressed)...
			motor[Bucket] = 0;    			//...stop the gripper.
			
		}
		
	} 
	
}
