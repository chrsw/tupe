awk '   { 
    for (i = 1; i <= NF; i++) {
        if( system("grep -w -i -q " $i " /usr/share/dict/words 2>/dev/null") == 0)
            num[$i]++ 
    }
}
END     { for (word in num) print word, num[word] }
' $*
