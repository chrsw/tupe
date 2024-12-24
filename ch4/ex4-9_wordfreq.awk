# Code for Exercise 4-9. Solution parts 1 & 2.
#
# Starting with wordfreq AWK script from section 4.4, get rid of non-words like
# .CW, which is a roff macro formatting command.
# The strategy is to only count words that have an entry in the system dictionary,
# in this case /usr/share/dict/words. The dictionary location may need to be modified
# for other systems.
# Example usage:
# cat ../extra/the_knights_tale.txt | ./ex4-9_wordfreq.awk
#
# Part 2 of Exercise 4-9: How would you use 'tr' to make wordfreq work properly
# regardless the case of its input?
# The solution for this second part is to use the tolower() built-in AWK function.

awk ' { 
    for (i = 1; i <= NF; i++)
        if ( !system("grep -w -i -q " $i " /usr/share/dict/words 2>/dev/null"))
            num[tolower($i)]++ 
}
END { 
    for (word in num)
        print word, num[word] 
}
' $*


# 'grep' command breakdown:
# -w search using word boundaries (find exact word matches).
#    dictionary file is one word on each line
# -i case insensitive. don't care if the word is capitalized or not.
# -q quiet search. only return true/false if a word is not found or found.
#    this is a little counter-intuitive. grep -q returns 0 if a word is found
#    and 1 if a word is not found.
