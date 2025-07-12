```md
Registres généraux (GPRs - General Purpose Registers)
Ces registres sont utilisés pour diverses opérations, y compris les calculs, les arguments des fonctions, les résultats, etc.

rax :

Usage principal : Accumulateur.

Rôle dans la convention d'appel : Registre de retour pour la valeur des fonctions. Utilisé pour retourner des résultats (par exemple, la valeur d'une fonction comme la longueur d'une chaîne).

Usage général : Opérations arithmétiques et logiques.

rbx :

Usage principal : Registre de base.

Rôle dans la convention d'appel : Non utilisé pour les arguments des fonctions. Ce registre peut être modifié dans une fonction sans que cela affecte l'appelant.

Usage général : Utilisé comme un registre temporaire, souvent pour les calculs intermédiaires.

rcx :

Usage principal : Registre de compteur.

Rôle dans la convention d'appel : rcx contient le 4e argument de la fonction. Il est également utilisé dans les boucles et les appels système pour le comptage.

Usage général : Principalement utilisé pour les opérations de boucle et d'itération.

rdx :

Usage principal : Registre de données.

Rôle dans la convention d'appel : rdx contient le 3e argument de la fonction.

Usage général : Utilisé pour les calculs (par exemple, les divisions et multiplications).

rsi :

Usage principal : Registre source.

Rôle dans la convention d'appel : rsi contient le 2e argument de la fonction.

Usage général : Utilisé comme source de données pour certaines instructions.

rdi :

Usage principal : Registre destination.

Rôle dans la convention d'appel : rdi contient le 1er argument de la fonction.

Usage général : Utilisé pour le premier argument dans une fonction, comme un pointeur vers une chaîne de caractères dans ft_strlen.

rbp :

Usage principal : Base Pointer (pointeur de base).

Rôle dans la convention d'appel : Utilisé pour accéder aux variables locales et aux arguments de la fonction dans la pile.

Usage général : Pointeur vers le début du cadre de la pile de la fonction.

rsp :

Usage principal : Stack Pointer (pointeur de pile).

Rôle dans la convention d'appel : Utilisé pour pointer vers la partie supérieure de la pile. Il est modifié au fur et à mesure que les fonctions poussent ou retirent des éléments de la pile.

Usage général : Il indique l'adresse actuelle de la pile.

r8 à r15 :

Usage principal : Registres supplémentaires.

Rôle dans la convention d'appel : r8 à r15 contiennent les arguments 5 à 8 d'une fonction (si elle en reçoit).

Usage général : Registres généraux supplémentaires, utilisés pour les arguments et autres opérations.
```

Récapitulatif de l'utilisation des registres pour les arguments dans une fonction System V ABI (x86-64) :
rdi : 1er argument

rsi : 2e argument

rdx : 3e argument

rcx : 4e argument

r8 : 5e argument

r9 : 6e argument

rsp : Pointeur de pile (stack pointer)

rbp : Base pointer (pointeur de base pour la pile)

al = lowest byte of rax
bl = lowest byte of rbx
cl = lowest byte of rcx
dl = lowest byte of rdx