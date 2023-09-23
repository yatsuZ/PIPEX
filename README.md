# PIPEX
Projet Pipex de 42

## Description le but du projet est de reproduire les pip.

```
Exemple :

 $> < infile ls -l | wc -l > outfile
 $> < infile grep a1 | wc -w > outfile

Ce que doit faire mon programme :

$> ./pipex infile "ls -l" "wc -l" outfile
$> ./pipex infile "grep a1" "wc -w" outfile
```
mon programme dois s'exécute de cette manière :

|  ./pipex file1 cmd1 cmd2 file2

Il faut prendre 4 arguments :
• file1 et file2 sont des noms de fichiers.
• cmd1 et cmd2 sont des commandes shell avec leurs paramètres.

Description :

je dois executer cmd1 en prenant comment entrée file 1 puis 
cmd2 prendra comment entre la sortie de cmd1 pour finir
la sortie de cmd2 sera dans file2.

Cas particulier :

time < infile | sleep 5 | sleep 10 | sleep 5 > outfile

Les sleep sexecute en meme temp DONC les cmd dois sexecute en meme temp.

## TO DO

A chaque étape, vérifier l'absence de fuites de mémoire !!!

|       CE QUE JE DOIS FAIRE        |  valide      |
| ----------------------------- | ------------ |
|      Pouvoir juste execute une commande en mode juste faire "./pipex ls" | X |
|      Pouvoir rediriger la sortie vers un fchier et si le fichier n'existe pas le crée | X |
|      Pouvoir metre une entre de fichier a une commande | X |
|      Pouvoir rediriger la sortie de cmd1 vers cmd2 | X |
|      Fusione tout ce qui est dis | X |
|      Faire que les cmd sexecute simultanement. | X |
