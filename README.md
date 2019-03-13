# Olimpiada-Murciana-Programacion-2018
I will upload here the solutions to the problems in this challenge

# PROBLEM SET INDEX
# A - Following the sequence
Given a sequence of 4 integer numbers, you have to guess the following number in the sequence. The valid sequences will have the    following forms:
  # Add a constant.
  The first number of the sequence is arbitrary. The following number will be the previous number plus a constant value. For example, if the first number is 8, and we add 3, the sequence will be: 8, 11, 14, 17, 20... The increment can also be negative. For example, for increment -1 and starting with 2, we have: 2, 1, 0, -1, -2,...
  # Add more.
  The first number of the sequence is arbitrary. The following number will be the previous number plus an increasing number; this increment is 1 more than the previous increment. For example, if the first number is 1, and we start with an increment of 2, the sequence will be: 1, 3(=1+2), 6(=3+3), 10(=6+4), 15(=10+5)...
  # Multiply by a constant.
  The first number of the sequence is arbitrary. The following number will be the previous number multiplied by a constant. For example, if the first number is 4, and the constant is 3, the sequence will be: 4, 12(=4*3), 36(=12*3), 108(=36*3)... The multiplier is NOT necessarily an integer, but the result should be an integer. For example, we can have the sequence: 10000, 1000, 100, 10, 1.
  # Fibonacci.
  The first and second numbers of the sequence are arbitrary. The following number will be the sum of the two previous numbers. For exaple, if the first numbers are 5 and -1, the sequence will be: 5, -1, 4(=5+-1), 3(=-1+4), 7(=4+3)...
  # The input
  The input contains several test cases. The first line of the input indicates the number of test cases.
  Each test case is described in a line with four integer numbers (from -1000000 to 1000000), separated by blank spaces.
  # The output
  For each case, you have to write an integer number representing the following number in the sequence. If the sequence is not of any of the four types defined above, you have to write: 42.
  
# B - Rolling rope
A rope is wound symmetrically around a circular bar. The rope goes exactly x times around the bar, which has a circumference of 'c' centimeters and a length of 'k' centimeters.
The problem is to calculate the length of the rope.
  # The input
  The first line of the input contains an integer, 't', indicating the number of test cases.
  For each case, the is a line with three natural numbers, separated by a space. The first one, 'c', represents the length of the circumference, 1 <= 'c' <= 100, the second number, 'k', is the length of the bar 1 <= 'k' <= 100, and the third number, 'x', indicates how many turns the rope goes around the circular bar, 1 <= 'x' <= 100.
  # The output
  For each test case, the output should consist of one line showing the length of the rope. If the result is not an integer number, you have to truncate the number.

# C - More Post-its!
In this problem, you have to help Pepito to organize his post-its. You have to order them from top to bottom. The first level should be the post-its (one or more) that don't have any post-it over them. The second levels are the post-its that only have post-its of first level above them. And so on.
Be careful because Pepito likes to play pranks, and sometimes he puts the post-its in a way that there is no solution, in this case, you have to write "No solution".
  # The input
  The first line of the input contains an integer number, N, indicating the number of test cases.
  Each test case is described in several lines. The first line contains two integers, H W, from 1 to 200, indicating the size of the wall. Then, there are H lines, each of them with W characters, representing the map of the wall. Each post-it has an assigned letter(uppercase or lowercase) or a digit(from 0 to 9). Each character indicates the post-it that is visible in that position, or it can contain a point ".", if there is no post-it. For example, we can have the following map:
  9 28
............................
.................ZZZZZZ.....
..OOOOOOOOOOO....ZZZZZZ.....
..OOOOOOOOOOOIIIIIIZZZZ.....
..OOOOOOOOOOOIIIIIIZZZZ.....
..OOOOOOOOOOOIIIIII.........
.........IIIIIIIIII.........
...DDDDDDIIIIIIIIII...AAAA..
...DDDDDDDDD..........AAAA..
  # The output
  For each test case, you have to write a first line with the text "Case X", where X is the number of the current case (starting from 1). If there is no solution, the following line should say "No solution". Otherwise, you have to write aline with the characters of the post-its of the first level, in the following line the post-its of secon level, and so on. The characters have to be written in order of ASCII code and separated with a blank space.

# D - Self-Plagiarism
The goverment has hired you to write a program to detect self-plagiarism in a text. We have a text in one line. You must find the longest sequence of characters that is repeated in the same text.
Observe that the repeated part may contain part of itself. For example, if we have the sequence: "blah, blah, blah", the longest repetition is the fragment "blah, blah".
  # The input
  The first line of the input contains an integer number, N, indicating the number of test cases.
  The following N lines contains the test cases, each case in a line. This line contains an arbitrary ASCII text, between 1 and 1000 characters long.
  # The output
  For each test case, you have to output the longest sequence that is repeated in the text. If there is more than one sequence with the maximun length, you have to output the first one to appear in the text.
  
# E - Plateaus at Bididibus
Bididibus consist of blocks of uniform width and heighth. Bididibusian orography is described by a series of symbols, from left to right, indicating that the land rises one unit (represented by "/"), descends one unit (represented by "\"), or it is flat (represented by "\_").
Your task is to count the number of plateaus in the map. A valid plateau should have: 3 or more consecutive rising units; 1 or more flat units; and 3 or more consecutive descending units.
  # The input
  The first line of the input contains an integer indicating the number of test cases.
  For each test case, there is a line which can contain three possible symbols: "/", "\", "\_". There will be at most 10000 symbols in each line.
  # The output
  For each test case, the output should contain a single integer indicating the number of valid plateaus of the corresponding case.

# F - Go for a Different Road!
We have a two-dimensional square grid of infinite size. There is a departure cell and an arrival cell, located in the same column, at a distance 'd', 1 <= d <= 40. Valid movements are from one cell to another contiguous cell. You have to calculate the number of different minimun paths (that is, those that need the minimum number of steps) to go from the initial cell to the final cell.
  # The input
  The first line of the input contains an integer indicating the number of cases.
  For each test case, there is a line with one number indicating the distance 'd' between the initial cell and the final cell.
  # The output
  For each test case, the output should consist of one line showing the number of different minimum paths between the initial and the final cell.
