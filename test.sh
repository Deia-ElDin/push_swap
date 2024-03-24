MIN_RANGE=-250
MAX_RANGE=250
THRESHOLD=5500
NUM_CASES=10
all_cases=()
count=0
max_operations=0
run_first_portion=true

echo  "\033[0;32m\nChecker:\n\033[0m"

for ((i=0; i<$NUM_CASES; i++)); do
    ARG=$(ruby -e "puts (-250..249).to_a.shuffle.join(' ')")
    result=$(./push_swap $ARG | ./checker_Mac $ARG)
    if [ "$result" != "OK" ]; then
        echo "\033[0;31m$(printf "%02d" $((i+1))): $result\033[0m"
    else
        echo "$(printf "%02d" $((i+1))): $result"
    fi
done

echo  "\033[0;32m\nMOVES:\n\033[0m"

while [ $count -lt $NUM_CASES ]; do
    RG=$(ruby -e "puts ($MIN_RANGE..$MAX_RANGE).to_a.shuffle.join(' ')")
    operations=$(./push_swap $RG | wc -l)
    all_cases+=("$RG $operations")
    if [ $operations -gt $THRESHOLD ]; then
        echo "\033[0;31m$(printf "%02d" $((count+1))): $operations\033[0m"
        red_cases+=("$RG")
        if [ $operations -gt $max_operations ]; then
            max_operations=$operations
        fi
    else
        echo "$(printf "%02d" $((count+1))): $operations"
    fi
    ((count++))
done

echo  "\033[0;32m\nNumbers:\n\033[0m"
for i in "${!all_cases[@]}"; do
    echo "$(printf "%02d" $((i+1))):"
    echo "${all_cases[$i]}"
    if [ $i -lt $((${#all_cases[@]}-1)) ]; then
        echo 
    fi
done

echo "\033[1;31m\nMax operation: $max_operations\n\033[0m"
