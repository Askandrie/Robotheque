# ⚠️ Ce projet est en cours de construction et n’est pas encore terminé.

# Robotheque

Un petit utilitaire en ligne de commande pour optimiser l'organisation des livres dans une étagère et maximiser l'espace disponible.

## Table des matières

* [Description](#description)
* [Prérequis](#prérequis)
* [Installation](#installation)
* [Usage](#usage)
* [Format des CSV](#format-des-csv)
* [Licence](#licence)

## Description

`Robotheque` est un petit programme en C qui :

1. Parse un CSV listant les séries de livres (titre, dimensions, nombre de tomes).
2. Parse un second CSV listant les étagères disponibles (nom, dimensions).
3. Calcule et affiche dans le terminal comment ranger les livres de manière optimale pour utiliser l'espace des étagères.

## Prérequis

* Un compilateur C compatible C99 (ex. `gcc` ou `cc`).
* `make` pour lancer la compilation.
* **libcsv** pour le parsing des fichiers CSV.

### Installation

1. Clonez le dépôt :

   ```bash
   git clone https://github.com/<votre-utilisateur>/Robotheque.git
   cd Robotheque
   ```

2. Compilez :

   ```bash
   make
   ```

3. L'exécutable `Robotheque` est généré à la racine du projet.

## Usage

```bash
./Robotheque LIVRES.csv ETAGERES.csv
```

* **LIVRES.csv** : chemin vers le fichier CSV contenant la liste des livres.
* **ETAGERES.csv** : chemin vers le fichier CSV contenant les informations des étagères.

Exemple :

```bash
./Robotheque series.csv shelves.csv
```

## Format des CSV

### Fichier Livres (LIVRES.csv)

Chaque ligne doit contenir les colonnes suivantes, séparées par des virgules :

1. `titre de la série` (texte)
2. `hauteur` (nombre entier, mm ou unité choisie)
3. `largeur` (nombre entier)
4. `profondeur` (nombre entier)
5. `nombre de tomes` (nombre entier)

Le fichier peut commencer par une ligne d’en-tête (facultative) :

```csv
titre,hauteur,largeur,profondeur,nombre_tomes
Bleach,180,130,30,74
One Piece,200,145,50,100
```

### Fichier Étagères (ETAGERES.csv)

Chaque ligne doit contenir les colonnes suivantes, séparées par des virgules :

1. `nom ou emplacement de l’étagère` (texte)
2. `hauteur` (nombre entier)
3. `largeur` (nombre entier)
4. `profondeur` (nombre entier)

Exemple :

```csv
Étagère A,400,800,350
Étagère B,300,600,300
```

##

## Licence

Ce projet est distribué sous la licence MIT. Voir le fichier [LICENSE](LICENSE) pour plus d’informations.
