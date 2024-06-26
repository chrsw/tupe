#!/bin/awk -f
# Exercise 4-7.  How many awk programs can you write that copy input to output
# as cat does? Which is the shortest?
# Part of Exercise 4-7
# To run:
# awk -f copy-1.awk < input_file
{ print $0 }
