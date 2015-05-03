1. sort -n -> sort by digit number (if no -n, 11 2 3 will be 11 2 3, if added, 2 3 11)
2. sort -r -> in a backward order. (you can use -nr together or -n -r)
3. random: -R
4. `uniq` command !!
5. sort by key : -k 1/2/3 column
(about -n ,if no -n ,sorted by alpha order or -d)
6. `sort -z file` -> end by '\0' not '\n'

#uniq
1. `sort file | unique -c` -> display lines numbers
2. `-d` -> find the repeated line

#head -n i
#tail -n i