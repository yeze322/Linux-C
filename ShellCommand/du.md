1. du -a + dir -> output a dir's space recursively
2. du -h -> auto use KB or M (du -b/k/m)
3. du -c -> add all files, give out a static
4. du -s -> only got one total
5. du -B -> static by a special blockl size
6. du --max-depth 1 / du -d
7. `head` command !! 
du -B 1024 ./ | sort -rnk 1 | head -n 30  //or du -k