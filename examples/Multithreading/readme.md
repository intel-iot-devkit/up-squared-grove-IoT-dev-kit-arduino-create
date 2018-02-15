# Multithreading
<table>
	<tr>
		<td>Programming language</td>
		<td>C++ (Arduino)</td>
	</tr>
	<tr>
		<td>Skill level</td>
		<td>Beginner</td>
	</tr>
	<tr>
		<td>Time to complete</td>
		<td>5 minutes</td>
	</tr>
	<tr>
		<td>Hardware needed</td>
		<td>UP Squared Grove IoT Development Kit</td>
	</tr>
	<tr>
		<td>Target Operating System</td>
		<td>Ubuntu 16.04</td>
	</tr>
</table>

This tutorial shows you how to use Multithreading on the Up2 board to perform multiple tasks simultaneously.

## What you'll learn
* How to multithread code to multitask within the Arduino Create environment.

## Gather your materials
* [UP²\* board](http://www.up-board.org/upsquared)

## Setup
No additional setup is required.

## Get the code
This example can be found in the Arduino Create IDE under `Examples > FROM LIBRARIES > UP SQUARED GROVE IOT DEV KIT > Multithreading`.

Before running, open the Monitor in the IDE.

After running should see `Hello from the parent process!` and `"Hello from the child process!` at different intervals.

## How it works
The "fork" function is a system function included in unix-based operating systems. It can be used to spawn a child process, and returns the process id (pid) of the resulting child. The child's pid variable will contain the initial value, which in this case is preset to "0".

[Fork](http://manpages.ubuntu.com/manpages/trusty/man2/fork.2.html)


IMPORTANT NOTICE: This software is sample software. It is not designed or intended for use in any medical, life-saving or life-sustaining systems, transportation systems, nuclear systems, or for any other mission-critical application in which the failure of the system could lead to critical injury or death. The software may not be fully tested and may contain bugs or errors; it may not be intended or suitable for commercial release. No regulatory approvals for the software have been obtained, and therefore software may not be certified for use in certain countries or environments.
