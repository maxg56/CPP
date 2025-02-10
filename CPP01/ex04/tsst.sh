#!/bin/bash

# Compilation
make

# Test 1 : Fichier vide
echo "====== Tests 1 ======"
echo -n "" > test1.txt
./file_replace test1.txt "old" "new"
echo "Test 1 (empty file) -> " $(cat test1.txt.replace)

# Test 2 : s1 absent
echo 
echo "====== Tests 2 ======"
echo "This is a test file with no matching words." > test2.txt
./file_replace test2.txt "old" "new"
echo "Test 2 (s1 not in file) -> " $(cat test2.txt.replace)

# Test 3 : s1 == s2
echo 
echo "====== Tests 3 ======"
echo "The quick brown fox jumps over the lazy dog." > test3.txt
./file_replace test3.txt "fox" "fox"
echo "Test 3 (s1 == s2) -> " $(cat test3.txt.replace)

# Test 4 : s1 présent plusieurs fois
echo ""
echo "====== Tests 4 ======"
echo "apple orange apple banana apple cherry" > test4.txt
./file_replace test4.txt "apple" "orange"
echo "Test 4 (multiple occurrences) -> " $(cat test4.txt.replace)

# Test 5 : s1 au début, milieu, fin
echo 
echo "====== Tests 5 ======"
echo "apple is at the start, banana in the middle, and apple at the end." > test5.txt
./file_replace test5.txt "apple" "orange"
echo "Test 5 (s1 at start, middle, end) -> " $(cat test5.txt.replace)

echo 
echo "====== Tests 6 ======"
echo "apple is at the start, banana in the middle, and apple at the end." > test6.txt
./file_replace test6.txt "banana" "orange"
echo "Test 6 (s1 at start, middle, end) -> " $(cat test6.txt.replace)

# Nettoyage
rm -f test*.txt test*.txt.replace file_replace

