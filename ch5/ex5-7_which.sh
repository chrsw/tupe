#!/bin/sh
# ex5-7_which:  which cmd in PATH is executed, part of Solution 5-7.
#				look for command as a shell builtin if a matching executable
#				file isn't found.

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
	if test -f $i/$1	# this is /bin/test
	then			# or /usr/bin/test only
		echo $i/$1
		exit 0		# found it
	fi
done

# no executable found. look for command as a shell builtin.
if command -v $1 > /dev/null
then
	echo "$1 builtin"
	exit
fi

exit 1				# not found
