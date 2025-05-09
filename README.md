# 📌 Projet : Algorithme de Dijkstra en C

## 🧠 Description

Ce projet implémente l’algorithme de **Dijkstra** en langage **C**, permettant de calculer les plus courts chemins depuis un sommet source vers tous les autres sommets d’un graphe **orienté et pondéré**. Le graphe est représenté sous forme de **matrice d'adjacence**.

---

## 🗂️ Structure du projet

- `Dijkstra.c` : Contient l’ensemble du code source (initialisation, affichage, Dijkstra, etc.)
- `README.md` : Ce fichier de documentation

---

## ✅ Fonctionnalités principales

### 🔹 Représentation du graphe
- Utilisation d'une matrice d'adjacence (`int M[N][N]`)
- Support des sommets identifiés par des lettres (`A`, `B`, `C`…)
- Graphe **orienté et valué**

### 🔹 Fonctions de base

| Fonction             | Description                                      |
|----------------------|--------------------------------------------------|
| `initMatriceAdj`     | Initialise la matrice à 0 (aucun arc)            |
| `ajouterArc`         | Ajoute un arc orienté avec un poids              |
| `supprimerArc`       | Supprime un arc donné                            |
| `marquerSommet`      | Initialise le tableau des sommets non marqués    |
| `AfficherMatriceChar`| Affiche la matrice avec noms de sommets en lettres |

### 🔹 Algorithme de Dijkstra

- Calcule les distances minimales depuis un sommet de départ
- Met à jour dynamiquement les prédécesseurs
- Affiche les résultats sous forme de tableau clair
- Reconstitution possible des chemins les plus courts

### 🔹 Parcours de graphe
- Implémentation d’un **parcours en profondeur récursif** (`parcoursEnProfondeur`)

---

## ⚙️ Compilation et exécution

### 🛠️ Compilation
```bash
gcc Dijkstra.c -o dijkstra
