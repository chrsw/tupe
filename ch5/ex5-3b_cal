#!/bin/sh
# Exercise 5-3  Modify `cal` to accept a range of moths:
#
# 	$ cal oct - dec
#

# Solution 5-3
# TODO:
# Error handling
# Make shorter

startm=$1
endm=$3

# get the starting month
case $1 in
	jan*|Jan*)	sm=1 ;;
	feb*|Feb*)	sm=2 ;;
	mar*|Mar*)	sm=3 ;;
	apr*|Apr*)	sm=4 ;;
	may*|May*)	sm=5 ;;
	jun*|Jun*)	sm=6 ;;
	jul*|Jul*)	sm=7 ;;
	aug*|Aug*)	sm=8 ;;
	sep*|Sep*)	sm=9 ;;
	oct*|Oct*)	sm=10 ;;
	nov*|Nov*)	sm=11 ;;
	dec*|Dec*)	sm=12 ;;
esac

# get the ending month
case $3 in
	jan*|Jan*)	em=1 ;;
	feb*|Feb*)	em=2 ;;
	mar*|Mar*)	em=3 ;;
	apr*|Apr*)	em=4 ;;
	may*|May*)	em=5 ;;
	jun*|Jun*)	em=6 ;;
	jul*|Jul*)	em=7 ;;
	aug*|Aug*)	em=8 ;;
	sep*|Sep*)	em=9 ;;
	oct*|Oct*)	em=10 ;;
	nov*|Nov*)	em=11 ;;
	dec*|Dec*)	em=12 ;;
esac

for m in `seq $sm $em`
do
case $m in
	jan*|Jan*)	m=1 ;;
	feb*|Feb*)	m=2 ;;
	mar*|Mar*)	m=3 ;;
	apr*|Apr*)	m=4 ;;
	may*|May*)	m=5 ;;
	jun*|Jun*)	m=6 ;;
	jul*|Jul*)	m=7 ;;
	aug*|Aug*)	m=8 ;;
	sep*|Sep*)	m=9 ;;
	oct*|Oct*)	m=10 ;;
	nov*|Nov*)	m=11 ;;
	dec*|Dec*)	m=12 ;;
esac

# get the current year
set `date`; y=$7;

/usr/bin/cal $m $y		# run the real cal
done
