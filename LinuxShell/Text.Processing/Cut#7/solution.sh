while read -r line; do
    echo "$line" | cut -d " " -f4
done;