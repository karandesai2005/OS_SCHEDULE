#/bin/bash

echo "please enter the file name"
read filename

touch "$filename"
echo "file $filename successufully created"

echo "enter the content in $filename (press ctr + d when done)"
cat > "$filename"

echo "content of $filename"
cat "$filename"

echo "no of line word and char in $filename"
wc "$filename"

echo "sorted $filename"
sort "$filename"

echo "conver to uppercase"
tr '[:lower]' '[:upper]' < "$filename"

echo "enter number of lines to display"
read num_lines
head -n "$num_lines" "$filename"

echo "enter the word you wanna search"
read search_word
grep "$search_word" "$filename"

echo "enter the new file name"
read new_name
mv "$filename"  "$new_name"

echo "enter the filename u wanna delete"
read del_file
rm "$del_file"
echo "file $del_file deleted"
