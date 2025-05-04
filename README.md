<img src="git_utils/banner.png" alt="logo_push-swap" style="width: 100%">

<br>

---

<br>

<details>
<summary>FRENCH VERSION</summary>

## Index
1. [Objectif](#objectif)
2. [Sujet](#sujet)
3. [Fonctionnement](#fonctionnement)
4. [Fonctions utilisées](#fonctions-utilisés)
	- [Parse](#parse)
	- [Erreurs](#errors)
	- [Checks](#checks)
	- [Moves](#moves)
	- [Algorithme](#algorithme)
5. [Résultats des tests](#résultats-des-tests)
6. [Notes](#note)
7. [Liens utiles](#liens-utiles)

<br>

## OBJECTIF
Développer un programme en langage C appelé "push_swap" qui prend la liste d'entiers comme argument en ligne de commande et affiche une séquence d'opérations permettant de trier ces entiers de manière optimale.

## SUJET
L'objectif principal du projet **push_swap** est de trier efficacement une pile d'entiers à l'aide d'un ensemble de règles prédéfinies, tout en minimisant le nombre d'opérations. <br>
L'idée centrale du projet est de créer deux piles, nommées "a" et "b", contenant une séquence d'entiers non triés au départ, tous empilés sur la pile "a". L'objectif est de trier ces entiers en utilisant un ensemble limité d'opérations de manipulation sur les piles.

#Contraintes et Règles
- Seules certaines opérations spécifiques sont autorisées pour manipuler les piles, telles que le déplacement d'éléments entre les piles, la rotation des éléments dans une pile, etc.
- L'efficacité du tri est mesurée en fonction du nombre total d'opérations effectuées.

<br>

## Fonctionnement

Le programme `push_swap` résout le problème de tri d'une pile d'entiers à l'aide d'opérations de manipulation de pile restreintes. Les opérations, telles que `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`, permettent d'effectuer des swaps, des rotations et des opérations de poussée entre deux piles.

<br>

## Arborescence
```
├── Makefile                 # Fichier de compilation pour générer l'exécutable.
├── checker                  # Programme pour check si les piles sont triées.
├── inc
│   └── push_swap.h          # Fichier d'en-tête.
└── srcs
	├── a_initializer.c      # Initialise la pile 'a' avec les valeurs d'entrée.
	├── b_initializer.c      # Initialise la pile 'b' pour les opérations de tri.
	├── errors.c             # Gère les erreurs et libère la mémoire en cas de problème.
	├── ft_split.c           # Divise une chaîne de caractères en plusieurs parties.
	├── main.c               # Point d'entrée principal du programme.
	├── move_push.c          # Implémente les opérations de poussée entre les piles.
	├── move_rev_rotate.c    # Implémente les rotations inversées des piles.
	├── move_rotate.c        # Implémente les rotations normales des piles.
	├── move_swap.c          # Implémente les opérations de swap sur les piles.
	├── sort_3.c             # Trie les trois premiers éléments de la pile 'a'.
	├── sort_stacks.c        # Trie les piles 'a' et 'b' avec l'algorithme principal.
	├── stack_init.c         # Initialise les structures de données pour les piles.
	└── stack_utils.c        # Fonctions utilitaires pour manipuler les piles.
```

<br>

## Fonctions utilisés

### Parse
```
long ft_atol(const char *s);					// Convertit une chaîne de caractères en long.
void add_node(t_stack **stack, int n);			// Ajoute un nouveau nœud à la fin de la pile.
void stack_creator(t_stack **a, char **argv);	// Initialise la pile 'a' en analysant les arguments passés.
t_stack *get_cheapest(t_stack *stack);			// Identifie le nœud de coût minimum dans la pile.
void prep_for_push(t_stack **stack, t_stack *top_node, char stack_name); // Prépare la pile pour push.
```

### Errors
```
int error_syntax(char *str_n);				// Vérifie la syntaxe d'une chaîne de caractères.
int error_duplicate(t_stack *a, int n);		// Vérifie si un nombre particulier existe déjà dans la pile.
void free_stack(t_stack **stack);			// Libère la mémoire allouée pour une pile.
void free_errors(t_stack **a);				// Libère la mémoire allouée pour une pile en cas d'erreur.
```

### Checks
```
int stack_size(t_stack *stack);				// Retourne la taille de la pile.
bool stack_is_sorted(t_stack *stack);		// Vérifie si la pile est triée de manière croissante.
t_stack *find_last(t_stack *stack);			// Retourne le dernier nœud de la pile.
t_stack *find_min(t_stack *stack);			// Identifie le nœud contenant la valeur minimale dans la pile.
t_stack *find_max(t_stack *stack);			// Identifie le nœud contenant la valeur maximale dans la pile.
```

### Moves
```
void sa(t_stack **a, bool print);					// Swap sur la pile 'a'.
void sb(t_stack **b, bool print);					// Swap sur la pile 'b'.
void ss(t_stack **a, t_stack **b, bool print);		// Swap simultanée sur les piles 'a' et 'b'.
void ra(t_stack **a, bool print);					// Rotation vers le haut sur la pile 'a'.
void rb(t_stack **b, bool print);					// Rotation vers le haut sur la pile 'b'.
void rr(t_stack **a, t_stack **b, bool print);		// Rotation simultanée sur les piles 'a' et 'b'.
void rra(t_stack **a, bool print);					// Rotation inverse sur la pile 'a'.
void rrb(t_stack **b, bool print);					// Rotation inverse sur la pile 'b'.
void rrr(t_stack **a, t_stack **b, bool print);		// Rotation inverse simultanée sur les piles 'a' et 'b'.
void pa(t_stack **a, t_stack **b, bool print);		// Opération de poussée de 'b' vers 'a'.
void pb(t_stack **b, t_stack **a, bool print);		// Opération de poussée de 'a' vers 'b'.
```

### Algorithme
```
void sort_3(t_stack **a);
// Trie les trois premiers éléments de la pile 'a'.

void rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);			
void rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
// Rotation (inversée ou non) simultanée des piles 'a' et 'b' jusqu'à ce que le nœud le moins cher atteigne sa position cible.

void mover(t_stack **a, t_stack **b, bool side);
// Déplace les éléments nécessaires entre les piles 'a' et 'b' pour effectuer une opération de poussée ou de tirage.

void min_on_top(t_stack **a);
// Place le nœud minimum au sommet de la pile 'a'.

void sort_turk(t_stack **a, t_stack **b);
// Trie les piles 'a' et 'b' avec l'algo Turkey Sort (tri par insertion et des opérations de manipulation de pile.)
```

<br>
<br>

---

<br>

### Résultats des tests

<div style="display: flex; flex-wrap: wrap; justify-content: center;">
	<img src="git_utils/testby100.png" alt="test_by_100" style="width: 49%">
	<img src="git_utils/testby500.png" alt="test_by_500" style="width: 49%">
</div>

 
## Note

<img src="git_utils/grade.png" alt="grade" style="width: 20%">


## Licence
This is a free work delivered for educational purposes during the main course at 42

[Licence](./LICENSE)

<br>

</details>

<br>

---

<br>

<details>
<summary>ENGLISH VERSION</summary>

## Index
1. [Objective](#objective)
2. [Subject](#subject)
3. [Functionality](#functionality)
4. [Used Functions](#used-functions)
	- [Parse](#parse)
	- [Errors](#errors)
	- [Checks](#checks)
	- [Moves](#moves)
	- [Algorithm](#algorithm)
5. [Test Results](#test-results)
6. [Notes](#notes)
7. [Useful Links](#useful-links)

<br>

## OBJECTIVE
Develop a C program called "push_swap" that takes a list of integers as a command-line argument and outputs a sequence of operations to optimally sort these integers.

## SUBJECT
The main goal of the **push_swap** project is to efficiently sort a stack of integers using a predefined set of rules while minimizing the number of operations. <br>
The central idea of the project is to create two stacks, named "a" and "b", containing an initially unsorted sequence of integers, all stacked in "a". The goal is to sort these integers using a limited set of stack manipulation operations.

#Constraints and Rules
- Only specific operations are allowed to manipulate the stacks, such as moving elements between stacks, rotating elements within a stack, etc.
- Sorting efficiency is measured by the total number of operations performed.

<br>

## Functionality

The `push_swap` program solves the problem of sorting a stack of integers using restricted stack manipulation operations. The operations, such as `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`, allow for swaps, rotations, and push operations between two stacks.

<br>

## Tree Structure
```
├── Makefile                 # Compilation file to generate the executable.
├── checker                  # Program to check if the stacks are sorted.
├── inc
│   └── push_swap.h          # Header file.
└── srcs
	├── a_initializer.c      # Initializes stack 'a' with input values.
	├── b_initializer.c      # Initializes stack 'b' for sorting operations.
	├── errors.c             # Handles errors and frees memory in case of issues.
	├── ft_split.c           # Splits a string into multiple parts.
	├── main.c               # Main entry point of the program.
	├── move_push.c          # Implements push operations between stacks.
	├── move_rev_rotate.c    # Implements reverse rotations of stacks.
	├── move_rotate.c        # Implements normal rotations of stacks.
	├── move_swap.c          # Implements swap operations on stacks.
	├── sort_3.c             # Sorts the first three elements of stack 'a'.
	├── sort_stacks.c        # Sorts stacks 'a' and 'b' using the main algorithm.
	├── stack_init.c         # Initializes data structures for the stacks.
	└── stack_utils.c        # Utility functions for stack manipulation.
```

<br>

## Used Functions

### Parse
```
long ft_atol(const char *s);					// Converts a string to a long.
void add_node(t_stack **stack, int n);			// Adds a new node to the end of the stack.
void stack_creator(t_stack **a, char **argv);	// Initializes stack 'a' by parsing the passed arguments.
t_stack *get_cheapest(t_stack *stack);			// Identifies the node with the minimum cost in the stack.
void prep_for_push(t_stack **stack, t_stack *top_node, char stack_name); // Prepares the stack for push.
```

### Errors
```
int error_syntax(char *str_n);				// Checks the syntax of a string.
int error_duplicate(t_stack *a, int n);		// Checks if a particular number already exists in the stack.
void free_stack(t_stack **stack);			// Frees the memory allocated for a stack.
void free_errors(t_stack **a);				// Frees the memory allocated for a stack in case of an error.
```

### Checks
```
int stack_size(t_stack *stack);				// Returns the size of the stack.
bool stack_is_sorted(t_stack *stack);		// Checks if the stack is sorted in ascending order.
t_stack *find_last(t_stack *stack);			// Returns the last node of the stack.
t_stack *find_min(t_stack *stack);			// Identifies the node containing the minimum value in the stack.
t_stack *find_max(t_stack *stack);			// Identifies the node containing the maximum value in the stack.
```

### Moves
```
void sa(t_stack **a, bool print);					// Swap on stack 'a'.
void sb(t_stack **b, bool print);					// Swap on stack 'b'.
void ss(t_stack **a, t_stack **b, bool print);		// Simultaneous swap on stacks 'a' and 'b'.
void ra(t_stack **a, bool print);					// Rotate up on stack 'a'.
void rb(t_stack **b, bool print);					// Rotate up on stack 'b'.
void rr(t_stack **a, t_stack **b, bool print);		// Simultaneous rotation on stacks 'a' and 'b'.
void rra(t_stack **a, bool print);					// Reverse rotate on stack 'a'.
void rrb(t_stack **b, bool print);					// Reverse rotate on stack 'b'.
void rrr(t_stack **a, t_stack **b, bool print);		// Simultaneous reverse rotation on stacks 'a' and 'b'.
void pa(t_stack **a, t_stack **b, bool print);		// Push operation from 'b' to 'a'.
void pb(t_stack **b, t_stack **a, bool print);		// Push operation from 'a' to 'b'.
```

### Algorithm
```
void sort_3(t_stack **a);
// Sorts the first three elements of stack 'a'.

void rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);			
void rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
// Simultaneous rotation (or reverse rotation) of stacks 'a' and 'b' until the cheapest node reaches its target position.

void mover(t_stack **a, t_stack **b, bool side);
// Moves the necessary elements between stacks 'a' and 'b' to perform a push or pull operation.

void min_on_top(t_stack **a);
// Places the minimum node at the top of stack 'a'.

void sort_turk(t_stack **a, t_stack **b);
// Sorts stacks 'a' and 'b' using the Turkey Sort algorithm (insertion sort and stack manipulation operations).
```

<br>
<br>

---

<br>

### Test Results

<div style="display: flex; flex-wrap: wrap; justify-content: center;">
	<img src="git_utils/testby100.png" alt="test_by_100" style="width: 49%">
	<img src="git_utils/testby500.png" alt="test_by_500" style="width: 49%">
</div>

 
## Notes

<img src="git_utils/grade.png" alt="grade" style="width: 20%">

## Licence
This is a free work delivered for educational purposes during the main course at 42

[Licence](./LICENSE)


<br>

</details>