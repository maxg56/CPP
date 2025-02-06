#!/bin/bash

# Vérifier si un répertoire a été fourni
if [ $# -ne 1 ]; then
    echo "Usage: $0 <chemin_du_dossier>"
    exit 1
fi

dir_path=$(realpath "$1")

# Vérifier que le dossier existe
if [ ! -d "$dir_path" ]; then
    echo "Le dossier spécifié n'existe pas."
    exit 1
fi

# Trouver et exécuter tous les Makefile
find "$dir_path" -maxdepth 2 -type f -name "Makefile" | while read -r makefile; do
    make -C "$(dirname "$makefile")"
done

# Créer le dossier EXEC s'il n'existe pas
exec_dir="/EXEC"
mkdir -p "$exec_dir"

# Récupérer tous les fichiers exécutables et les copier dans EXEC/
find "$dir_path" -maxdepth 1 -type f -executable | while read -r exe; do
    cp "$exe" "$exec_dir/"
    echo "Copié : $exe → $exec_dir/"
done

echo "Tous les exécutables ont été copiés dans $exec_dir/"



