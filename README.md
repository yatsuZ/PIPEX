# Projet Pipex 42

## Description

Le projet Pipex de 42 consiste à recréer le fonctionnement des pipes dans un environnement Unix en utilisant C.
L'objectif est de permettre l'exécution de deux commandes en série, 
en redirigeant la sortie de la première commande vers l'entrée de la deuxième commande, 
tout en prenant en charge la gestion des fichiers.

### Exemples

Voici comment fonctionnent les pipes en shell Unix :

```shell
$> < infile ls -l | wc -l > outfile
$> < infile grep a1 | wc -w > outfile
```

Ce que doit faire mon programme :

```shell
$> ./pipex infile "ls -l" "wc -l" outfile
$> ./pipex infile "grep a1" "wc -w" outfile
```

## Utilisation

Le programme doit être exécuté de la manière suivante :

```shell
./pipex file1 cmd1 cmd2 file2
```

- file1 et file2 sont des noms de fichiers.
- cmd1 et cmd2 sont des commandes shell avec leurs paramètres.

Le programme exécute cmd1 en prenant file1 comme entrée, puis redirige la sortie de cmd1 vers cmd2. Enfin, la sortie de cmd2 est écrite dans file2.

## Cas particulier

Le programme doit gérer des cas où plusieurs commandes sont exécutées simultanément, par exemple :

```shell
time < infile | sleep 5 | sleep 10 | sleep 5 > outfile
```

Les commandes sleep doivent s'exécuter en même temps.

## TO DO

A chaque étape, vérifier l'absence de fuites de mémoire !!!

|       CE QUE JE DOIS FAIRE        |  valide      |
| ----------------------------- | ------------ |
|      Pouvoir exécuter une commande en mode simple comme "./pipex ls"	 | ✅ 28/09/2023 |
|      Pouvoir rediriger la sortie vers un fichier et le créer s'il n'existe pas | X |
|      Pouvoir rediriger l'entrée d'une commande à partir d'un fichier | X |
|      Pouvoir rediriger la sortie de cmd1 vers cmd2 | X |
|      Fusionner toutes les fonctionnalités | X |
|      Assurer que les commandes s'exécutent simultanément | X |
|      Parsing | X |

## Exigences

Mon projet doit respecter les règles suivantes :

- Je dois fournir un Makefile qui compilera mes fichiers sources.
- Mon programme ne doit pas se terminer de manière inattendue (erreur de segmentation, erreur de bus, double libération, etc.).
- Évitez les fuites de mémoire.

## Auteur

Ce projet a été réalisé par MOI !!! :smiley:

| Info          | Ou me retrouver                                                      |
| ------------- | -------------------------------------------------------------------- |
| Nom👋         | Zaoui                                                                |
| Prenom😄      | Yassine                                                              |
| Pseudo😁      | Yatsu                                                                |
| Login 42🏫    | Yzaoui                                                               |
| E-mail📬      | y.zaoui.pro@gmail.com                                                |
| Instagram📸   | [@yatsu__officiel](https://www.instagram.com/yatsu__officiel/)       |
