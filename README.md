# Bioinformatics DNA Sequence Alignment Tool (C++)

A command-line tool built in C++ that performs global pairwise sequence alignment on DNA/RNA sequences using the Needleman-Wunsch algorithm. 

## Features
- Implements classic dynamic programming matrix optimization.
- Backtracks through memory arrays to reconstruct the highest-scoring structural alignment.
- Custom alignment scoring parameters (Match: +1, Mismatch: -1, Gap: -2).

## How to Run
```bash
g++ -std=c++11 alignment.cpp -o aligner
./aligner
