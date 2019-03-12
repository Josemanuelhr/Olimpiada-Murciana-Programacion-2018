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
