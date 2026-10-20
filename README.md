# CPP – Modules C++ 00 à 09 (42)

Ce dépôt regroupe mes solutions des **modules C++ de l'école 42** (CPP00 à CPP09). Chaque module introduit une notion du C++ et contient plusieurs exercices indépendants (`ex00`, `ex01`, ...).

## Compilateur et standard

- Compilateur : `c++` (`g++` pour `CPP07/ex02`)
- Standard : **C++98** (`-std=c++98`)
- Flags : `-Wall -Wextra -Werror` (plus `-g` pour `CPP07/ex02`, `CPP09/ex00` et `CPP09/ex01`)

## Modules et notions abordées

| Module | Notions | Exercices |
|--------|---------|-----------|
| **CPP00** | Classes, fonctions membres, flux d'entrée/sortie, membres statiques | `megaphone`, `PhoneBook` (répertoire de contacts), `Account` |
| **CPP01** | Allocation mémoire (`new` / `delete`), pointeurs et références, fichiers (`fstream`), pointeurs sur fonctions membres, `switch` | `Zombie` / `zombieHorde`, adresses et références, `HumanA` / `HumanB` / `Weapon`, `file_replace` (remplacement de chaînes dans un fichier), `Harl`, filtre `Harl` |
| **CPP02** | Forme canonique orthodoxe, surcharge d'opérateurs, nombres à virgule fixe | `Fixed` (3 versions) |
| **CPP03** | Héritage, héritage multiple et virtuel (problème du diamant) | `ClapTrap`, `ScavTrap`, `FragTrap`, `DiamondTrap` |
| **CPP04** | Polymorphisme par sous-typage, fonctions virtuelles, classes abstraites, copie profonde | `Animal` / `Dog` / `Cat` / `WrongAnimal`, `Brain` |
| **CPP05** | Exceptions (`try` / `catch`, classes d'exception) | `Bureaucrat`, `Form`, `AForm` et formulaires concrets (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`), `Intern` |
| **CPP06** | Casts C++ (`static_cast`, `reinterpret_cast`, `dynamic_cast`) | `ScalarConverter`, `Serializer` (`uintptr_t`), identification de type `Base` / `A` / `B` / `C` |
| **CPP07** | Templates de fonctions et de classes | `whatever` (`swap`, `min`, `max`), `iter`, `Array` |
| **CPP08** | Conteneurs, itérateurs et algorithmes de la STL | `easyfind`, `Span`, `MutantStack` (`std::stack` itérable) |
| **CPP09** | Choix de conteneurs STL | `btc` (`std::map`, cours du bitcoin), `RPN` (`std::stack`, notation polonaise inverse), `PmergeMe` (tri de Ford-Johnson avec `std::deque` et `std::vector`) |

## Organisation

```
CPPXX/
└── exYY/
    ├── Makefile
    ├── include/   # en-têtes (.hpp, .tpp)
    └── src/       # sources (.cpp)
```

Exception : `CPP00/ex00` contient directement `megaphone.cpp` et son `Makefile`.

## Compiler et lancer un exercice

Chaque exercice a son propre `Makefile` :

```bash
cd CPP09/ex01
make          # compile l'exécutable
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
make clean    # supprime les fichiers objets
make fclean   # supprime aussi l'exécutable
make re       # fclean puis all
```

Les objets sont placés dans un dossier `.tmp/obj/` (ignoré par git). Le nom de l'exécutable est défini par la variable `NAME` du `Makefile` de l'exercice.

> Dans `CPP01/ex00`, `ex01` et `ex02`, `NAME` est vide : `make` ne produit rien. Il faut passer le nom à la main, par exemple `make NAME=zombie`.

La plupart des exercices se lancent sans argument (`./Bureaucrat`, `./Span`, ...) et exécutent les tests écrits dans leur `main.cpp`. Ceux qui prennent des arguments :

| Exercice | Exécutable | Arguments |
|----------|------------|-----------|
| `CPP00/ex00` | `megaphone` | un ou plusieurs mots |
| `CPP01/ex04` | `file_replace` | `<filename> <s1> <s2>` : crée `<filename>.replace` |
| `CPP01/ex06` | `arlFilter` | un niveau (`DEBUG`, `INFO`, `WARNING`, `ERROR`) |
| `CPP06/ex00` | `ScalarConverter` | une ou plusieurs valeurs littérales |
| `CPP09/ex00` | `btc` | un fichier d'entrée (ex. `input.txt`, lu avec `data.csv`) |
| `CPP09/ex01` | `RPN` | une expression en notation polonaise inverse |
| `CPP09/ex02` | `PmergeMe` | une suite d'entiers positifs |

### Exemples

```
$ ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$ ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *

$ ./ScalarConverter 42

Input: 42
char: *
int: 42
float: 42.0f
double: 42.0

$ ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
Result: 42

$ ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::deque : 14 us
Time to process a range of 5 elements with std::vector : 8 us
```

(Les temps affichés par `PmergeMe` varient d'une exécution à l'autre.)

## État de compilation

Testé avec `g++ 13.3` (Linux). Tous les exercices compilent, sauf :

- `CPP01/ex06` : refusé par `g++` (`-Werror=implicit-fallthrough`), compile avec `make CC=clang++` ;
- `CPP02/ex00`, `ex01`, `ex02` : erreur d'édition de liens (constructeur de copie de `Fixed` non défini) ;
- `CPP07/ex01` : erreur de compilation dans `main.cpp` (appel de `iter` avec une fonction template surchargée).

## Scripts utilitaires

À la racine :

- `Makefile` : modèle de `Makefile` copié dans chaque nouvel exercice ;
- `script.sh <nombre_exercices>` : crée le module suivant (`CPPXX`) avec les dossiers `exYY/src`, `exYY/include` et une copie du `Makefile` modèle ;
- `update_src.sh` : remplit la variable `SRC =` du `Makefile` de chaque exercice avec les `.cpp` trouvés ;
- `script2.sh <dossier>` : lance `make` dans les sous-dossiers du dossier donné et copie les exécutables dans `/EXEC`.
