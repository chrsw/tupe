#!/bin/bash
# watchwho:  watch who logs in and out, variable version
# part of Exercise 5-12.

who1=""

while :         # loop forever
do
    who2=`who`
    diff <(echo "$who1") <(echo "$who2")
    who1="$who2"
    sleep 60
done | awk '/>/ { $1 = "in:      "; print }
            /< [a-zA-Z]/ { $1 = "out:     "; print }'
