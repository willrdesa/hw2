# CS 3503 Assignment 1 - Number Base Conversion

## Author
William De Sa

## Description
My implementation of Owl Tech’s number conversion utility for bases 2, 8, and 16 with direct mapping and signed representations.

## Build Instructions
‘‘‘bash
gcc -o convert convert .c main .c
./ convert
‘‘‘

## Test Results
[X/Y tests passed - paste summary here ]
48/51 tests passed - tested basic mapping, edge cases, single and multi-digit numbers, and case sensitivity for direct mapping functions. Meanwhile, tested positive and negative numbers, zero, and large values for signed representation functions.

## Notes
[Any interesting discoveries or challenges ]
Finally understood how numbers and characters work and how to convert them to each other. Also understood better right and left shifting. I struggled with getting all tests to work, because many changes would change which tests were passing and which were failing, and didn't have time to get a few final ones to work.