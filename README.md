# Final
## Format of this file:("Line Number: Commentary");
1: import premade EYW library to reduce work;\n
2: Construct a new "Altimeter" object named 'a';\n
3: begin setup() method, setup() runs once and returns nothing;\n
4: Initialize the refresh rate of the Serial connection to the computer;\n
5: output the string "Initializing.....\n" to the Serial monitor;\n
6: output the result of String begin() to the Serial monitor, begin() initializes the altimeter and sets up default ports for I/O;\n
7: run the calibrate(int i) method, more specifically it takes 10 measurements of barometric air pressure and sets the pressure sensor to 0;\n
8: runs the pinMode(int pin, mode) method, which initializes pin as a mode, either INPUT or OUTPUT, in this case, it initializes pin 5 as an OUTPUT;\n
9: declares two boolean values, lifted and dropped, which are used to determine when to begin taking altitude measurements and to determine if the capsule has landed;\n
10: declares an array of integers, heights[], which has a length of 20, to store height values to allow for data collection;\n
11: begin loop() method, this method is an infinite loop and will run until the Arduino turns off, it also returns nothing;\n
12: begin for loop, this iterates through the code inside the loop 10 times, once a second;\n
13: ouptut the string "Measuring Altitude: " to the serial monitor for human observation;\n
14: takes 10 measurements of air pressure, converts each to an altitude, and then averages them, putting them into heights at index i, which increments with the for loop;\n
15: output the value stored in the i-th index of heights to the serial monitor;\n
16: checks if the value stored in the i-th index of heights is greater than the value stored in the i-1 th index of heights;\n
17: if the condition in line 16 is true, then set lifted to true;\n
18: checks if the value stored in the i-1 th index of heights is greater than the value stored in the ith index of heights;\n
19: if the condition in line 18 is true, then set dropped to true;\n
20: declare an integer speed which gets twice the sum of the i-3th index and the i-2th index of heights;\n
21: begin while loop, this only begins if the ith and i-1 th indices of heights are equal and both lifted and dropped are true;\n
22: begin switch statement to determine what sound is ouputted, the deciding value is speed%10, or the remainder when speed is divided by 10 (for two digit numbers);\n
23: this case will run if speed%10 is 1;\n
24: sound the alarm once for 250ms, a dot or dit;\n
25: wait 10 ms;\n
26: sound the alarm four times for 500 ms, four dashes or dahs;\n
27: break out of the switch statement and to the end of the while loop;\n
28-69: repeat for every digit from 2-9 and 0;\n
70: this case is the default case and will only run if there is an error in the code/altimeter failure;\n
71: wait 1500 msec between numbers;\n
72: check to see if current height is greater than the last height before beginning beeping;\n
73: set boolean lifted to false;\n
74: reset heights[] to zero;\n
75: set i to zero and reset the for loop;\n
77: wait 500 msec between loops of the for loop;\n
