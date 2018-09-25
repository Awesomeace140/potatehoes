#pragma config(Motor,  port1,           left1,         tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           left2,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           right1,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           right2,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           flyWheel1,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           flyWheel2,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           ballIntake,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           lift1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           lift2,         tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main() {
	while(true) {
		//variable declarations
		char liftDebug = 0;

		//MOtor joystick program
		motor[left1]  = vexRT[Ch3];
		motor[left2]  = vexRT[Ch3];
		motor[right1] = vexRT[Ch2];
		motor[right2] = vexRT[Ch2];

		//lift program press both buttons at same time
		if((vexRT[Btn6D]==1)&&(vexRT[Btn6U]==1)) {
			char liftDebug=1;
			motor[lift1]=0;
			motor[lift2]=0;
		} else {
				char liftDebug=0;
		}

		//LIft program
		while ((vexRT[Btn6D]==1)&&(liftDebug==0)) {
			motor[lift1] = -127;
			motor[lift2] = -127;
		}
		while ((vexRT[Btn6U]==1)&&(liftDebug==0)) {
			motor[lift1] = 127;
			motor[lift2] = 127;
		}

		//flyWheel
		if (vexRT[Btn5D]==1) {
			motor[flyWheel1] = -127;
			motor[flyWheel2] = -127;
		} else if (vexRT[Btn5U]==1) {
				motor[flyWheel1] = 127;
				motor[flyWheel2] = 127;
		} else {
				motor[flyWheel1] = 0;
				motor[flyWheel2] = 0;
		}
	}
}
