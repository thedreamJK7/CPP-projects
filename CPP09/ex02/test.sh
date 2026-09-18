#!/bin/bash

PASS=0
FAIL=0

check() {
    local DESC="$1"
    local INPUT="$2"
    local EXPECT_ERROR="$3"

    ./PmergeMe $INPUT > /tmp/out.txt 2>&1

    if [ "$EXPECT_ERROR" = "1" ]; then
        grep -q "Error" /tmp/out.txt
        if [ $? -eq 0 ]; then
            echo "[OK]  $DESC"
            PASS=$((PASS+1))
        else
            echo "[FAIL] $DESC | expected Error, got: $(cat /tmp/out.txt)"
            FAIL=$((FAIL+1))
        fi
    else
        local N=$(echo $INPUT | wc -w)
        local EXP=$(echo $INPUT | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/ $//')
        local OUT=$(sed -n '2p' /tmp/out.txt | sed 's/[[:space:]]*$//')
        if [ "$OUT" = "$EXP" ]; then
            echo "[OK]  $DESC"
            PASS=$((PASS+1))
        else
            echo "[FAIL] $DESC"
            echo "       got: $OUT"
            echo "       exp: $EXP"
            FAIL=$((FAIL+1))
        fi
    fi
}

echo "========== Edge Cases =========="
check "single element"           "42"
check "two elements"             "2 1"
check "three elements (odd)"     "3 2 1"
check "already sorted"           "1 2 3 4 5"
check "reverse sorted"           "5 4 3 2 1"
check "duplicates"               "3 3 3 1 2"
check "zero in input"            "0 5 3"
check "two same elements"        "7 7"

echo ""
echo "========== Jacobsthal Boundaries =========="
check "n=3  (J boundary)"   "$(seq 1 3  | sort -R | tr '\n' ' ')"
check "n=5  (J boundary)"   "$(seq 1 5  | sort -R | tr '\n' ' ')"
check "n=11 (J boundary)"   "$(seq 1 11 | sort -R | tr '\n' ' ')"
check "n=21 (J boundary)"   "$(seq 1 21 | sort -R | tr '\n' ' ')"
check "n=22 (past J=21)"    "$(seq 1 22 | sort -R | tr '\n' ' ')"
check "n=43 (J boundary)"   "$(seq 1 43 | sort -R | tr '\n' ' ')"
check "n=44 (past J=43)"    "$(seq 1 44 | sort -R | tr '\n' ' ')"

echo ""
echo "========== Larger Inputs =========="
check "n=50"   "$(seq 1 50   | sort -R | tr '\n' ' ')"
check "n=100"  "$(seq 1 100  | sort -R | tr '\n' ' ')"
check "n=500"  "$(seq 1 500  | sort -R | tr '\n' ' ')"
check "n=3000" "$(seq 1 3000 | sort -R | tr '\n' ' ')"

echo ""
echo "========== Error Handling =========="
check "no arguments"       ""                   1
check "negative number"    "3 -1 5"             1
check "float number"       "3 2.5 1"            1
check "non-numeric"        "3 abc 1"            1
check "space in arg"       "\"3 2 1\""          1

echo ""
echo "========== Stress Test (100 random runs) =========="
S_PASS=0; S_FAIL=0
for i in $(seq 1 100); do
    n=$((RANDOM % 500 + 1))
    INPUT=$(seq 1 $n | sort -R | tr '\n' ' ')
    ./PmergeMe $INPUT > /tmp/out.txt 2>&1
    EXP=$(seq 1 $n | tr '\n' ' ' | sed 's/ $//')
    OUT=$(sed -n '2p' /tmp/out.txt | sed 's/[[:space:]]*$//')
    if [ "$OUT" = "$EXP" ]; then
        S_PASS=$((S_PASS+1))
    else
        S_FAIL=$((S_FAIL+1))
        echo "[FAIL] stress n=$n"
    fi
done
echo "Stress: $S_PASS/100 passed"
PASS=$((PASS+S_PASS))
FAIL=$((FAIL+S_FAIL))

echo ""
echo "========== Results =========="
echo "Total: $PASS passed, $FAIL failed"
