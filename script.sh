#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <nombre_exercices>"
    exit 1
fi

# Vérifier si l'argument est un nombre
if ! [[ "$1" =~ ^[0-9]+$ ]]; then
    echo "Erreur : l'argument doit être un nombre."
    exit 1
fi

num_exercises=$1

# Trouver le dernier dossier CPPXX (trié numériquement)
last_cpp_dir=$(find . -maxdepth 1 -type d -name "CPP[0-9]*" | sort -V | tail -n 1)


if [ -z "$last_cpp_dir" ]; then
    new_cpp_dir="CPP00"
else
    last_number=$(echo "$last_cpp_dir" | grep -o '[0-9]*$')
    new_number=$((10#${last_number#0} + 1))
    new_cpp_dir=$(printf "CPP%02d" "$new_number")
fi

# Création des dossiers
mkdir -p "$new_cpp_dir"

i=0
while [ "$i" -lt "$num_exercises" ]; do
    exercise_number=$(printf "ex%02d" "$i")
    mkdir -p "$new_cpp_dir/$exercise_number/src"
    mkdir -p "$new_cpp_dir/$exercise_number/include"
    cp "Makefile" "$new_cpp_dir/$exercise_number"
    ((i++))
done

echo "Dossiers créés dans : $new_cpp_dir"
