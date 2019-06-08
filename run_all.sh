files=$(ls *.c)

for file in $files; do
	echo $file
	rm libs/*.gch; gcc libs/* $file ; ./a.out
	echo -e "\n"
done
