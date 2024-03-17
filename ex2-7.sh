#!/bin/sh -x

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
