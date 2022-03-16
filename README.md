# POA labo1 - Matrix Reloaded
## Diagramme de classe

## Choix de modélisation

## Tests

| Fonction testée | Intitulé du test | Résultat attendu | Résultat obtenu |
|----------|-------------|:------:|:------:|
| Constructeur aléatoire | Construction d'une matrice avec un nombre de lignes et de colonnes strictement positifs | ok | ok |
| Constructeur aléatoire | Construction d'une matrice avec un nombre de lignes de 0 et un nombre de colonnes strictement positif | failed | failed |
| Constructeur aléatoire | Construction d'une matrice avec un nombre de colonnes de 0 et un nombre de lignes strictement positif | failed | failed |
| Constructeur de copie | Construction d'une matrice avec un nombre de lignes et de colonnes strictement positif avec le constructeur de copie | ok | ok |
| Opérateur d'affectation | Affectation d'une matrice avec une autre matrice | ok | ok |
| Addition statique | Addition statique entre 2 matrices de mêmes tailles | ok | ok |
| Addition statique | Addition statique entre 2 matrices de différentes tailles | ok | ok |
| Addition statique | Addition statique entre 2 matrices de modulos différents | failed | failed |
| Addition self | Addition self entre 2 matrices de mêmes tailles | ok | ok |
| Addition self | Addition self entre 2 matrices de différentes tailles | ok | ok |
| Addition self | Addition self entre 2 matrices de modulos différents | failed | failed |
| Addition dynamique | Addition dynamique entre 2 matrices de mêmes tailles | ok | ok |
| Addition dynamique | Addition dynamique entre 2 matrices de différentes tailles | ok | ok |
| Addition dynamique | Addition dynamique entre 2 matrices de modulos différents | failed | failed |
