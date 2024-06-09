#!/bin/sh
# ex5-3:  Modify `cal` to accept more than one month

for m in $*
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

/usr/bin/cal $m $y		# run the real one
done

