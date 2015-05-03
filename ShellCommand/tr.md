#basic use of tr command
1. `echo "hello world" | tr 'a-z' 'A-Z' ` -- `echo "hello world" | tr [:lower:] [:uper:]`
2. -d : delete from [set1]
3. `cat 20124.cpp | tr 'a-zA-Z' 'n-za-mN-ZA-M' -> add ` (encrypt)
` cat 20124.cpp | tr 'a-zA-Z' 'n-za-mN-ZA-M' | tr 'n-za-mN-ZA-M' 'a-zA-Z' `
4. cat 20124.cpp | tr ' ' '\b' | tr '\b' ' ' -> '\b' is an exited character!!
##combinations
5. ` find . -maxdepth 1 -type d -print | tr // ! | sed 's/.!//g'  ` -> I want to grep somefile and copy with dir structure
6. ` find ./ -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" \) -print0 | tr // ! | sed 's/.!//' | tr ! // | xargs -0 -I {} cp {} ~/Desktop/ShellScript/Linux-C/OldCode/{} `
7. `-c`-> not in set-A (usually we use `tr -d -c [set]` means not in set)
___
#more use:
1. tr -s ' ' -> only keep one space, delete other spaces
2. do calculations with `tr`: `cat numbers.txt | echo $[ $( tr '\n' '+' ) 0 ] `
(pay attention to the 0 in the tail. we get 1+2+3+4+5+, so we need to add a zero)