On pull le repo pour en avoir la dernière version :

`git pull origin main`

On crée une nouvelle branche avec pour nom l'issue :

`git checkout -b branchName`

On fait le travail nécessaire dans la branche.

Puis quand on a finit on ajoute nos changement au commit :

`git add -A` si on ne rajoute aucun fichier, sinon on peut faire `git add *` pour tout inclure.

Puis on commit en ajoutant le #numéro de l'issue :

`git commit -m "fixed issue #1"`

Puis on push :

`git push -u origin branchName`

Avant de merge au main on fait un pull pour être sûr d'avoir la dernière version et ainsi éviter
des conflits :

`git pull origin main`

On peut maintenant créer une pull request sur le site de github :

On peut le faire depuis la page "Code" en cliquant sur le message orange. Ou alors en allant
dans les "branches" et en cliquant le "new pull request" de la bonne branch
Github vérifie si la PR peut être merge sans conflit, si c'est possible un message vert
apparaît et il est possible de valider la PR (si l'utilisateur à les droits). Il vaut mieux “squash”
le merge, celà permet de n’ajouter qu’un seul commit dans le main peu importe le nombre
de commit dans la PR. Les commits resteront quand même en historique dans la PR même
un fois la branche supprimée.

Un bouton pour supprimer la branche est disponible.

Maintenant que le merge à été fait sur github et faut mettre son git local à jour :

`git checkout main
git pull`

On peut supprimer la branche qui ne nous sert plus :

`git branch -D branchName`

En cas de merge conflict pendant la PR :

`git pull origin main`

Normalement on voit un message indiquant le conflit.

Après résolution du conflit :

`git add -A`

`git commit -m "conflict resolved"`

`git push`

La PR sera à jour et pourra être validée