#!/bin/sh -x
# Code for Chapter 2, Exercise 7

ls
sleep 2
touch junk
ln junk junk2
mv junk junk1
touch junk
cp junk junk1
rm junk
sleep 2
ls
