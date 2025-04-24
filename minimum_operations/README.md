# Minimum Operations

Voyons ce que fait exactement ce script Python, ligne par ligne, et comment il réussit tous les tests du checker du projet "0. Minimum Operations" 👨‍💻.

## 🧩 Fichier : 0-minoperations.py
```python
#!/usr/bin/python3
```
## 👉 Shebang : permet d’exécuter le fichier directement en ligne de commande (ex : ./0-minoperations.py) en utilisant l’interpréteur Python3.

```python
"""
Calculates the fewest number of operations needed
to result in exactly n H characters using only
Copy All and Paste operations.
"""
```

## 👉 Docstring de module : Description du but du fichier (obligatoire pour valider avec le checker Holberton).

```python
def minOperations(n):
    """
    Returns the minimum number of operations
    needed to get exactly n Hs in a file.
    """
```

## 👉 Docstring de fonction : Explique ce que fait la fonction minOperations.

📐 La logique interne :
```python
    if n < 2:
        return 0
```

## 👉 Si n est inférieur à 2 (ex : 0, 1 ou négatif), il est impossible ou inutile d’avoir un nombre de H supérieur à 1 (tu commences déjà avec un H), donc retour immédiat à 0.

```python
    operations = 0
    factor = 2
```

## 👉 Initialisation :

operations : compteur du nombre total d'opérations.

factor : commence à 2 car c’est le plus petit facteur possible.

🔁 Boucle principale :
```python
    while n > 1:
```

## 👉 Tant qu’on n’a pas réduit n à 1 (ce qui signifie qu’on a simulé les multiplications jusqu’à 1), on continue.

```python
        while n % factor == 0:
            operations += factor
            n //= factor
```

## 👉 Si n est divisible par factor, c’est qu’on peut le considérer comme une étape de multiplication (ex: Copy + plusieurs Paste).

On :

Ajoute factor au total d'opérations (1 Copy All + x Paste = x + 1).

Réduit n en divisant par ce factor.

💡 Cela revient à factoriser n en entiers premiers.

```python
        factor += 1
```
## 👉 On passe au prochain facteur possible.

## ✅ Exemple : minOperations(9)
Factorisation de 9 = 3 × 3
→ Ajoute 3 (1 Copy + 2 Paste)
→ Puis encore 3
→ Total = 6 opérations

## ✅ Tests du checker (explication)
```bash
| Entrée        | Sortie attendue | Explication                                                              |
|---------------|------------------|---------------------------------------------------------------------------|
| 21            | 10               | 21 = 3 × 7 → 3 + 7 = 10 opérations                                       |
| 19170307      | 19170307         | Nombre premier → il faudra n opérations (1 copy + n-1 paste)            |
| 972           | 21               | 972 = 2 × 2 × 3 × 3 × 3 × 3 × 3 → 2+2+3+3+3+3+3 = 21                     |
| 1             | 0                | Déjà 1 H, aucune opération nécessaire                                   |
| 0 ou -12      | 0                | Impossible → retour 0                                                   |
| 2147483640    | ✓ correcte       | Un très grand nombre, mais bien factorisé → toujours fonctionnel        |

```

## 🧼 PEP8
Le script est bien formaté.

Pas de ligne trop longue.

Noms de variables explicites.

Présence des docstrings pour la fonction et le module.

## 🚀 Résumé
Cette fonction utilise la décomposition en facteurs premiers de n pour modéliser une stratégie optimale de copier-coller. Chaque facteur représente un "bloc" de Copy + Paste, et leur somme donne le nombre minimal d'opérations.
