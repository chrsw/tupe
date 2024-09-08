#!/bin/sh
# which cmd:  which cmd in PATH is executed
# Exercise 5-8: check file for exec permissions
#               print an error if no file found

opath=$PATH
PATH=/bin:/usr/bin

case $# in
	0)	echo 'Usage: which command' 1>&2; exit 2
esac
for i in `echo $opath | sed 's/^:/.:/
			     s/::/:.:/g
			     s/:$/:./
			     s/:/ /g'`
do
	if test -x $i/$1	# this is /bin/test
	then			# or /usr/bin/test only
		echo $i/$1
		exit 0		# found it
	fi
done

echo "which: $1 not found or not executable" 1>&2; exit 1

