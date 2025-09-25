#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
# Reset color
DEFAULT='\033[0m'

## Type detection

# Check pseudo-literals (nan, inf) first.

# Use simple regex-style tests (^[+-]?\d+$, ^[+-]?\d+\.\d+f$, etc.).

if [ $# -ne 1 ]; then
	echo -e "${YELLOW}Usage: $0 [program_name]${DEFAULT}"
	exit 1
fi

program="$1"


current_test=(
	"c"
	"0"
	"nan"
	"42.0f"
	"-42"
	"42"
	"-4.2"
	"4.2"
	"0.0"
	"0.0f"
	"nanf"
	"+inff"
	"-inff"
)


test_valid_cases=(
	""
	"0"
	"nan"
	"42.0f"
	"-42"
	"42"
	"-4.2"
	"4.2"
	"0.0"
	"0.0f"
	"nanf"
	"+inff"
	"-inff"
)

for case in "${current_test[@]}"; do
	echo -e "${GREEN}Running: ./$program $case${DEFAULT}"
	./$program "$case"
	echo "-----------------------------"
done

#for test_case in "${test_valid_cases[@]}"; do
#	echo "Running: ./convert $test_case"
#	./convert "$test_case"
#	echo "-----------------------------"
#done


#to do check for .e cases improve the while loop that checks for types !!