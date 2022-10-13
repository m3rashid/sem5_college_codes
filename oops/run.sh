echo -n "Enter filename: "; read filename

g++ "./$filename.cpp" -o "$filename" && "./$filename"
