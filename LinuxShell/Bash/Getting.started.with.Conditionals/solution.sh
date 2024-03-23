read value;
if [[ "$value" == "y" || "$value" == "Y" ]]; then
    echo "YES"
else 
    echo "NO"
fi