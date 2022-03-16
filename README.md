# POA labo1 - Matrix Reloaded
## Diagramme de classe

## Choix de modélisation

## Tests

### Constructeur

| Fonction testée | Intitulé du test | Résultat attendu | Résultat obtenu |
|----------|-------------|:------:|:------:|
| Constructeur aléatoire | Construction d'une matrice avec un nombre de lignes et de colonnes strictement positifs | ok | ok |
| Constructeur aléatoire | Construction d'une matrice avec un nombre de lignes de 0 et un nombre de colonnes strictement positif | failed | failed |
| Constructeur aléatoire | Construction d'une matrice avec un nombre de colonnes de 0 et un nombre de lignes strictement positif | failed | failed |
| Constructeur de copie | Construction d'une matrice avec un nombre de lignes et de colonnes strictement positif avec le constructeur de copie | ok | ok |

### Opérateurs

| Fonction testée | Intitulé du test | Résultat attendu | Résultat obtenu |
|----------|-------------|:------:|:------:|
| Opérateur d'affectation | Affectation d'une matrice avec une autre matrice | ok | ok |

### Addition

| Fonction testée | Intitulé du test | Résultat attendu | Résultat obtenu |
|----------|-------------|:------:|:------:|
| Addition statique | Addition statique entre 2 matrices de mêmes tailles | ok | ok |
| Addition statique | Addition statique entre 2 matrices de différentes tailles | ok | ok |
| Addition statique | Addition statique entre 2 matrices de modulos différents | failed | failed |
| Addition self | Addition self entre 2 matrices de mêmes tailles | ok | ok |
| Addition self | Addition self entre 2 matrices de différentes tailles | ok | ok |
| Addition self | Addition self entre 2 matrices de modulos différents | failed | failed |
| Addition dynamique | Addition dynamique entre 2 matrices de mêmes tailles | ok | ok |
| Addition dynamique | Addition dynamique entre 2 matrices de différentes tailles | ok | ok |
| Addition dynamique | Addition dynamique entre 2 matrices de modulos différents | failed | failed |

### Soustraction

| Fonction testée | Intitulé du test | Résultat attendu | Résultat obtenu |
|----------|-------------|:------:|:------:|
| Soustraction statique | Soustraction statique entre 2 matrices de mêmes tailles | ok | ok |
| Soustraction statique | Soustraction statique entre 2 matrices de différentes tailles | ok | ok |
| Soustraction statique | Soustraction statique entre 2 matrices de modulos différents | failed | failed |
| Soustraction self | Soustraction self entre 2 matrices de mêmes tailles | ok | ok |
| Soustraction self | Soustraction self entre 2 matrices de différentes tailles | ok | ok |
| Soustraction self | Soustraction self entre 2 matrices de modulos différents | failed | failed |
| Soustraction dynamique | Soustraction dynamique entre 2 matrices de mêmes tailles | ok | ok |
| Soustraction dynamique | Soustraction dynamique entre 2 matrices de différentes tailles | ok | ok |
| Soustraction dynamique | Soustraction dynamique entre 2 matrices de modulos différents | failed | failed |

### Multiplication

| Fonction testée | Intitulé du test | Résultat attendu | Résultat obtenu |
|----------|-------------|:------:|:------:|
| Multiplication statique | Multiplication statique entre 2 matrices de mêmes tailles | ok | ok |
| Multiplication statique | Multiplication statique entre 2 matrices de différentes tailles | ok | ok |
| Multiplication statique | Multiplication statique entre 2 matrices de modulos différents | failed | failed |
| Multiplication self | Multiplication self entre 2 matrices de mêmes tailles | ok | ok |
| Multiplication self | Multiplication self entre 2 matrices de différentes tailles | ok | ok |
| Multiplication self | Multiplication self entre 2 matrices de modulos différents | failed | failed |
| Multiplication dynamique | Multiplication dynamique entre 2 matrices de mêmes tailles | ok | ok |
| Multiplication dynamique | Multiplication dynamique entre 2 matrices de différentes tailles | ok | ok |
| Multiplication dynamique | Multiplication dynamique entre 2 matrices de modulos différents | failed | failed |
