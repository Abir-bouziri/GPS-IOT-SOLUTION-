# GPS-IOT-SOLUTION-
cette solution nous permet de géolocaliser la position de notre voiture en utilisant la technologie l'internet des objets.

En premier lieu , on a besoin d'installer le ide arduinio contenant "le esp bibliothéque".

En deuxiéme lieu ,on a besoin d'installer un serveur XAMP . 

L'annexe 1 qui aura lieu  dans ce dossier va vous expliquer le fonctionnement de cette solution en détails.

L'arduino_gps_code__final1.ino : nous permet de extraire les données du GPS et l'envoit vers le serveur XAMP en utilisant LE DATA TYPE XML et le REST API .

dota.php est un script php qui nous permet d' extraire les données d'un ficher XML et de l'insérer dans  la basse données SQL en utilisant le language PHP .
 
 Le fichier GPS.SQL  est un fichier exemplaire SQL contient des données et des valeurs d'un GPS été en cours de fonctionement .
 
 


