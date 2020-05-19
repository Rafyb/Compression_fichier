# Compression fichier

GIT : https://github.com/Rafyb/Compression_fichier

## Equipe

- Johann De Almeida
- Raphaël Bauvin

## Notice d'utilisation

Compiler à l'aide de la commande `make`

Exectuer à l'aide de la commande transform ou detransform
`./transform(detransform) Nobre_de_bloc Nom_fichier_entree Nom_fichier_sortie`

Exemple :
`./transform 1 fichier_binaire.bloc transformee.bloc`
`./detransform 1 transformee.bloc detransformee.bloc`

Il est possible aussi de tester avec `./testTransform Nombre_de_bloc` qui va générer un fichier "fichier_binaire.bloc" contant le nombre de bloc passé, le transformer, le détransformer et enfin faire la différence avec le(s) bloc(s) obtenu(s) et celui du départ
