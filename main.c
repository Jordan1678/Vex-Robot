// Setup Motor and Ports
#pragma config(Motor,  port2,           RightRear,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           RightFront,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           LeftRear,     tmotorVex393, openLoop)
#pragma config(Motor,  port5,           LeftFront,     tmotorVex393, openLoop)
#pragma config(Motor,  port6,           ArmLift,     tmotorVex393, openLoop)
#pragma config(Motor,  PORT_NUM_HERE,           Elbow,     tmotorVex393, openLoop)
#pragma config(Motor,  port8,           Bucket,     tmotorVex393, openLoop)

// Drive Axis
char DriveX = Ch4;
char DriveY = Ch3;

// Arm Axis
char Arm = Ch2

// Elbow Control Map
char ElbowUP = Btn5U;
char ElbowDOWN = Btn5D;

// Bucket Control Map
char BucketUP = Btn6U;
char BucketDOWN = Btn6D;

task main ()
{

	while(1 == 1)
	{	
		// Drive Control
		motor[RightRear]  = (vexRT[DriveY] + vexRT[DriveX] * -1)/2;
		motor[RightFront] = (vexRT[DriveY] + vexRT[DriveX]] * -1)/2;
		motor[LeftRear] = (vexRT[DriveY] - vexRT[DriveX]] * -1)/2;
		motor[LeftFront] = (vexRT[DriveY] - vexRT[DriveX]] * -1)/2;

		// Lift Arm
		motor[ArmLift] = vexRT[Arm]/2;
		
		// Bend Elbow
		if (vexRT[ElbowUP] == 1) {
			motor[Elbow] = 127;
		
		} else if (vexRT[ElbowDOWN] == 1) {
			motor[Elbow] = -127;
		
		} else {
			motor[Elbow] = 0;
		
		}

		// Rotate Bucket
		if (vexRT[Btn6U] == 1) {       	//If Button 6U is pressed...
			motor[Bucket] = 65;  			//...close the gripper.
			
		} else if (vexRT[Btn6D] == 1) { 	//Else, if button 6D is pressed...
			motor[Bucket] = -65; 			//...open the gripper.
			
		} else {                      	//Else (neither button is pressed)...
			motor[Bucket] = 0;    			//...stop the gripper.
			
		}
		
	} 
	
}
