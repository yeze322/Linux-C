##Use xargs after pipe '|'
1. `... | xargs` --> turn lines into one line
2. `... | xargs -n 3` --> use " "(space) to separate output into lines, each line have 3 words
3. `... | xargs -d char` --> separate by char (only one char!!)
4. you can add several xargs after pipe
5. -d -n can be used together
6. `cat args.txt | xargs -n 1 sh cecho.sh`

7. -I : relpace `cat args.txt | xargs -I {} sh cecho.sh -p {} -print`
8. `xargs -0`: separated by '\0' (because some filename may have space, so we use '\0' to separate)
9. count how many lines you write: `find . -type f -name "*.c" -print0 | xargs -0 wc -l`
( find -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" \) -print0 | xargs -0 wc -l)
10. `cat file.txt | xargs -I {} cat {} ` == `cat filles.txt | ( while read arg; do cat $arg; done )`