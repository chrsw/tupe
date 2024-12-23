# Starting with wordfreq AWK script from section 4.4, get rid of non-words like
# .CW, which is a roff macro formatting command.
# The strategy is to only count words that have an entry in the system dictionary,
# in this case /usr/share/dict/words. The dictionary location may need to be modified
# for other systems.
# Example usage:
# cat ../extra/the_knights_tale.txt | ./ex4-9_wordfreq.awk

awk '   { 
    for (i = 1; i <= NF; i++)
        if( system("grep -w -i -q " $i " /usr/share/dict/words 2>/dev/null") == 0)
            num[$i]++ 
}
END     { for (word in num) print word, num[word] }
' $*
