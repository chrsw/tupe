#!/bin/sh -x

touch junk
ln junk junk2
mv junk junk1
touch junk
cp junk junk1
rm junk
