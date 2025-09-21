# !/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
# Reset color
DEFAULT='\033[0m'

## Type detection

# Check pseudo-literals (nan, inf) first.

# Use simple regex-style tests (^[+-]?\d+$, ^[+-]?\d+\.\d+f$, etc.).

# Recognize a single character in single quotes as CHAR


test_valid_cases = (
	"" # Empty string
	"Hello, World!" # Simple string
)


