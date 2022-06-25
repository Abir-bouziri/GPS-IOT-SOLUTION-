# GPS-IOT-SOLUTION-
cette solution nous permet de géolocaliser la position de notre voiture en utilisant la technologie l'internet des objets.

En premier lieu , on a besoin d'installer le ide arduinio contenant "le esp bibliothéque".

En deuxiéme lieu ,on a besoin d'installer un serveur XAMP . 

L'annexe 1 qui aura lieu  dans ce dossier va vous expliquer le fonctionnement de cette solution en détails.

L'arduino_gps_code__final1.ino : nous permet de extraire les données du GPS et l'envoit vers le serveur XAMP en utilisant LE DATA TYPE XML et le REST API .

dota.php est un script php qui nous permet d' extraire les données d'un ficher XML et de l'insérer dans  la basse données SQL en utilisant le language PHP .
 
 Le fichier GPS.SQL  est un fichier exemplaire SQL contient des données et des valeurs d'un GPS été en cours de fonctionement .
   
# Le fonctionnement de la solution :

1- esp8266 communique avec le GPS à l'aide du branchement qui aura lieu dans l'annexe 2 et un code arduino  tout en envoyant les coordonnées nécessaires (latitude, longitude, id véhicule, immatriculé du véhicule) à la carte .

2- esp8266 communique avec le serveur web en se connectant à l'AP (ACESS POINT ) où le serveur web y appartient (En travail dans un serveur local ,dans notre cas c’est le PC qui joue le rôle d’un point d’accès et contient le serveur web).

3- web serveur exécute le script php dont ce dernier exécute la requête http ou https,
extrait les données envoyées dans la requête et les insère dans la base de données.

4- A l’aide du .net connector nous pouvons accéder à la base de données et extraire les
données utiles et les visualiser dans une carte géographique en utilisant .net framework.

 

 


