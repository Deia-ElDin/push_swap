# chmod +x test.sh

MIN_RANGE=-250
MAX_RANGE=250
THRESHOLD=5500
NUM_CASES=100
all_cases=()
count=0
max_moves=0
total_moves=0
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
    movess=$(./push_swap $RG | wc -l)
    all_cases+=("$RG $movess")
    if [ $movess -gt $THRESHOLD ]; then
        echo "\033[0;31m$(printf "%02d" $((count+1))): $movess\033[0m"
        red_cases+=("$RG")
        if [ $movess -gt $max_moves ]; then
            max_moves=$movess
        fi
    else
        echo "$(printf "%02d" $((count+1))): $movess"
    fi
    ((count++))
done


echo  "\033[0;32m\nNumbers:\n\033[0m"
for i in "${!all_cases[@]}"; do
    echo "$(printf "%02d" $((i+1))):" >> Numbers.txt
    echo "${all_cases[$i]}" >> Numbers.txt
    if [ $i -lt $((${#all_cases[@]}-1)) ]; then
        echo  >> Numbers.txt
    fi
done

for moves in "${all_cases[@]##* }"; do
    total_moves=$((total_moves + moves))
done

average_moves=$(bc <<< "scale=0; ($total_moves + $NUM_CASES - 1) / $NUM_CASES")

echo "\033[1;34m\nMax Moves: $max_moves\nAverage Moves: $average_moves\n\033[0m"
