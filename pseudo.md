# Pseudo code de programme

1. Boucle principale (Recommencer)
2. Saisir la limite entre 2 et 1000 avec validation
3. Vider le buffer après la saisie
4. Pour chaque nombre 'n' de 2 à 'limite':
5. Vérifier si 'n' est premier (boucle de 2 à i*i <= n)
6. Si 'n' est premier, l'afficher avec setw() et incrémenter le compteur
7. Si le compteur atteint n_col, passer à la ligne suivante
8. Demander à l'utilisateur s'il veut recommencer [O/N] avec validation