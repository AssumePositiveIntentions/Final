# Final
## Format of this file:("Line Number: Commentary");
1: import premade EYW library to reduce work;
2: Construct a new "Altimeter" object named 'a';
3: begin setup() method, setup() runs once and returns nothing;
4: Initialize the refresh rate of the Serial connection to the computer
5: output the string "Initializing.....\n" to the Serial monitor
6: output the result of String begin() to the Serial monitor, begin() initializes the altimeter and sets up default ports for I/O;
7: run the calibrate(int i) method, more specifically it takes 10 measurements of barometric air pressure and sets the pressure sensor to 0;
8: runs the pinMode(int pin, mode) method, which initializes pin as a mode, either INPUT or OUTPUT, in this case, it initializes pin 5 as an OUTPUT;
10: declares two boolean values, lifted and dropped, which are used to determine when to begin taking altitude measurements and to determine if the capsule has landed;
11: declares an array of integers, heights[], which has a length of 20, to store height values to allow for data collection;
12: begin loop() method, this method is an infinite loop and will run until the Arduino turns off, it also returns nothing;
13: begin for loop, this iterates through the code inside the loop 10 times, once a second;
14: ouptut the string "Measuring Altitude: " to the serial monitor for human observation;
15: takes 10 measurements of air pressure, converts each to an altitude, and then averages them, putting them into heights at index i, which increments with the for loop;
16: 
