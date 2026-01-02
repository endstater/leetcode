#!/sbin/bash

echo '# Leetcode' > README.md

echo -e '## easy\n|Task|Solution|\n|-|-|' >> README.md

for file in ./tasks/easy/*; do
    [ -f "$file" ] || continue

    filename=$(basename -- "$file")
    extension="${filename##*.}"
    name="${filename%.*}"

    if [ "$name" = "$filename" ]; then
        name="$filename"
        extension=""
    fi
    extension_upper=$(echo "$extension" | tr '[:lower:]' '[:upper:]')

    echo "| [$name](https://leetcode.com/problems/$name) | [$extension_upper](./tasks/easy/$name.$extension) |" >> README.md
done