[Home](https://assumepositiveintentions.github.io/Final/) | [Photos](https://assumepositiveintentions.github.io/Final/photos) | [Videos](https://assumepositiveintentions.github.io/Final/videos) | [Our Code](https://assumepositiveintentions.github.io/Final/code)

# Line-by-line explanation of the code that was programmed into the Arduino:

## Format:("Line Number. Commentary");

1. import premade EYW library to reduce work;
2. Construct a new "Altimeter" object named 'a';
3. begin setup() method, setup() runs once and returns nothing;
4. Initialize the refresh rate of the Serial connection to the computer
5. output the string "Initializing.....\n" to the Serial monitor
6. output the result of String begin() to the Serial monitor, begin() initializes the altimeter and sets up default ports for I/O;
7. run the calibrate(int i) method, more specifically it takes 10 measurements of barometric air pressure and sets the pressure sensor to 0;
8. runs the pinMode(int pin, mode) method, which initializes pin as a mode, either INPUT or OUTPUT, in this case, it initializes pin 5 as an OUTPUT;
9. declares two boolean values, lifted and dropped, which are used to determine when to begin taking altitude measurements and to determine if the capsule has landed;
10. declares an array of integers, heights[], which has a length of 20, to store height values to allow for data collection;
11. begin loop() method, this method is an infinite loop and will run until the Arduino turns off, it also returns nothing;
12. begin for loop, this iterates through the code inside the loop 10 times, once a second;
13. ouptut the string "Measuring Altitude: " to the serial monitor for human observation;
14. takes 10 measurements of air pressure, converts each to an altitude, and then averages them, putting them into heights at index i, which increments with the for loop;
15. output the value stored in the i-th index of heights to the serial monitor;
16. checks if the value stored in the i-th index of heights is greater than the value stored in the i-1 th index of heights;
17. if the condition in line 16 is true, then set lifted to true;
18. checks if the value stored in the i-1 th index of heights is greater than the value stored in the ith index of heights;
19. if the condition in line 18 is true, then set dropped to true;
20. declare an integer speed which gets twice the sum of the i-3th index and the i-2th index of heights;
21. begin while loop, this only begins if the ith and i-1 th indices of heights are equal and both lifted and dropped are true;
22. begin switch statement to determine what sound is ouputted, the deciding value is speed%10, or the remainder when speed is divided by 10 (for two digit numbers);
23. this case will run if speed%10 is 1;
24. sound the alarm once for 250ms, a dot or dit;
25. wait 10 ms;
26. sound the alarm four times for 500 ms, four dashes or dahs;
27. break out of the switch statement and to the end of the while loop;
28. this case will run if speed%10 is 2;
29. sound the alarm twice for 250ms, two dots or dits;
30. wait for 10 ms;
31. sound the alarm three times for 500 ms, three dashes or dahs;
32. break out of the switch statement and to the end of the while loop;
33. this case will run if speed%10 is 3;
34. 

