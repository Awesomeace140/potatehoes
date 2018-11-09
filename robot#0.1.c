#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    leftLiftPotent, sensorPotentiometer)
#pragma config(Sensor, in2,    rightLiftPotent, sensorPotentiometer)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  puncherEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  intakeEncoder,  sensorQuadEncoder)
#pragma config(Motor,  port1,           flipper,       tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           puncher1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           left1,         tmotorVex393HighSpeed_MC29, PIDControl, reversed, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port4,           left2,         tmotorVex393HighSpeed_MC29, PIDControl, reversed, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port5,           left3,         tmotorVex393HighSpeed_MC29, PIDControl, reversed, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port6,           right1,        tmotorVex393HighSpeed_MC29, PIDControl, reversed, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port7,           right2,        tmotorVex393HighSpeed_MC29, PIDControl, reversed, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port8,           right3,        tmotorVex393HighSpeed_MC29, PIDControl, reversed, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port9,           puncher2,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          intake,        tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(DatalogSeries, 0, "leftEncodeDatalog", Sensors, Sensor, dgtl1, 50)
#pragma config(DatalogSeries, 1, "leftErrorP", Motors, PID_ErrorP, port3, 50)
#pragma config(DatalogSeries, 2, "leftErrorI", Motors, PID_kI, port3, 50)
#pragma config(DatalogSeries, 3, "leftErrorD", Motors, PID_ErrorD, port3, 50)
#pragma config(DatalogSeries, 4, "leftKp", Motors, PID_kP, port3, 50)
#pragma config(DatalogSeries, 5, "leftKi", Motors, PID_kI, port3, 50)
#pragma config(DatalogSeries, 6, "leftKd", Motors, PID_kD, port3, 50)
#pragma config(DatalogSeries, 7, "leftDeadband", Motors, PID_Deadband, port3, 50)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//bleebleebloop
//motor left2 = middle
//motor left1 & left3 = sides
//motor right2 = middle
//motor right1 & right 3 = sides

/*--
#pragma config(Motor,  port4,           ballIntake,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           flyWheel1,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           flyWheel2,     tmotorVex393HighSpeed_MC29, openLoop)
--*/
#include "jpearman/SmartMotorLib.c"

#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c" //Main competition background code...do not modify!
#pragma systemFile
#include "variables.c"
#include "functions.c"



/////////////////////////////////////////////////////////////////////////////////////////
//
// Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton(){
// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
bStopTasksBetweenModes = false;

// All activities that occur before the competition starts
// Example: clearing encoders, setting servo positions, ...
//Smart Motor Library-------For more info go to https://renegaderobotics.org/using-jpearmans-smart-motor-library/
//Enable smart motor library
SmartMotorsInit();

//Enable power expander
//SmartMotorsAddPowerExtender(motorA,motorB,motorC,motorD);

//LInk motors together(lift, drive etc.)
//Left Side
SmartMotorLinkMotors(left1, left2);
SmartMotorLinkMotors(left1, left3);

//right Side
SmartMotorLinkMotors(right1, right2);
SmartMotorLinkMotors(right1, right3);

//puncher
SmartMotorLinkMotors(puncher1, puncher2);

//Current or PTC Monitor------------------ I chose Current because it estimates motor speed and current
SmartMotorCurrentMonitorEnable();

//Smart motor start
SmartMotorRun();

clearAll(actOnSensors);
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////



task autonomous() {
	auton();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////



task usercontrol() {
// User control code here, inside the loop

/////////////////////////////////////////////////////////////////////////////////////////
//
// Variable Declarations
//
/////////////////////////////////////////////////////////////////////////////////////////

while (true) {
// This is the main execution loop for the user control program. Each time through the loop
// your program should update motor + servo values based on feedback from the joysticks.

		//drive program
		drive();

		//puncher
		puncher();

		//intake
		intaking();

	}
}
