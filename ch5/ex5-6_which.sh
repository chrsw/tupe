#!/bin/sh
# which cmd:  which cmd in PATH is executed, exercise 5-6

opath=$PATH
PATH=/bin:/usr/bin
all=0
case $# in
	0)	echo 'Usage: which command' 1>&2; exit 2
esac
if test "$1" = -a
then
	all=1
	shift
fi

for i in `echo $opath | sed 's/^:/.:/
			     s/::/:.:/g
			     s/:$/:./
			     s/:/ /g'`
do
	if test -f $i/$1	# this is /bin/test
	then			# or /usr/bin/test only
		echo $i/$1
		if test $all = 0
		then
			exit 0		# quit after first match
		fi
	fi
done
exit 1				# not found

