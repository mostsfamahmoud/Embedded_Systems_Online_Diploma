#!/bin/bash

# Capture the start time in nanoseconds
start_time=`date +%s%N`

# Place your process or commands here that you want to measure
echo "Enter the first number:"
#read num1
num1=1

echo "Enter the second number:"
#read num2
num2=2

sum=`expr $num1 + $num2`

echo "The sum of the two values : $sum"

# Capture the end time in nanoseconds
end_time=`date +%s%N`

# Calculate the time difference in nanoseconds
time_diff_ns=$((end_time - start_time))

# Convert nanoseconds to seconds with decimals (divide by 1 billion)
time_in_seconds=$(bc <<< "scale=3; $time_diff_ns / 1000000000")

echo "Execution Time: ${time_in_seconds} seconds"