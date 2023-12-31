# Bibliothèque Arduino GL042MT

Cette bibliothèque permet d'interfacer le capteur ultrasonique sous-marin GL042MT avec une carte Arduino. Le capteur GL042MT est capable de mesurer des distances de 2 à 300 cm avec une précision de ±(0.5 + S_0.5%) si la distance mesurée (S) est inférieure à 200 cm, et de ±(1 + S_1%) si la distance mesurée est supérieure à 200 cm. Il est conçu pour fonctionner sous l'eau à une profondeur maximale de 10 mètres.

Cette bibliothèque a été créé par chatGPT4 à partir des données fournies sur ce site https://fr.aliexpress.com/i/1005005250918774.html

## Installation

1.  Téléchargez le fichier ZIP de la bibliothèque à partir de ce dépôt.
2.  Dans l'IDE Arduino, allez dans Croquis > Inclure une bibliothèque > Ajouter une bibliothèque .ZIP...
3.  Sélectionnez le fichier ZIP que vous avez téléchargé à l'étape 1.

## Utilisation

Voici un exemple de base de l'utilisation de la bibliothèque :

    #include "GL042MT.h"
    
    GL042MT sensor(10, 11);  // RX, TX
    
    void setup() {
      Serial.begin(115200);
      sensor.begin();
    }
    
    void loop() {
      int distance = sensor.readDistance();
      if (distance >= 0) {
        Serial.println("Distance: " + String(distance) + " mm");
      } else if (distance == -1) {
        Serial.println("Checksum error");
      } else if (distance == -2) {
        Serial.println("Not enough data");
      }
      delay(14);
    }

## Fonctionnalités supplémentaires

Ce dépôt contient également deux fichiers supplémentaires qui étendent les fonctionnalités de la bibliothèque GL042MT : `servoradar.ino` et `visuradar.pde`.

### Servo Radar (`servoradar.ino`)

`servoradar.ino` est un script Arduino qui contrôle le capteur GL042MT monté sur un servo moteur pour balayer un arc de 180 degrés. Il envoie ensuite les données de distance et d'angle au PC via le port série.

Le script utilise la bibliothèque Servo pour contrôler le servo moteur, et la bibliothèque GL042MT pour lire les données du capteur. Il effectue une boucle de 0 à 180 degrés, déplace le servo à chaque angle, lit la distance du capteur, et envoie ensuite l'angle et la distance au PC via le port série.

### Visualisation du Radar (`visuradar.pde`)

`visuradar.pde` est un script Processing qui lit les données du port série et les affiche sous forme de radar sonar. Il dessine un fond de radar avec des demi-cercles à des intervalles fixes pour représenter les distances, et affiche les obstacles détectés comme des points sur le radar.

Le script utilise la bibliothèque Processing Serial pour lire les données du port série. Il attend que des données soient disponibles, les lit jusqu'à ce qu'il atteigne une nouvelle ligne, puis divise la chaîne de caractères en angle et distance. Il convertit ensuite ces valeurs en coordonnées polaires et les dessine sur le radar.

## Fonctions

-   `GL042MT(rxPin, txPin)`: Crée une nouvelle instance de GL042MT avec les broches RX et TX spécifiées.
-   `begin()`: Initialise la communication série avec le capteur.
-   `readDistance()`: Lit la distance du capteur. Renvoie la distance en millimètres, ou -1 si une erreur de somme de contrôle se produit, ou -2 si suffisamment de données ne sont pas disponibles.

## Capteur GL042MT
1.  **Modèle et Série** : Le capteur fait partie de la série GL04 de capteurs ultrasoniques sous-marins.
    
2.  **Gamme de mesure** : Le capteur peut mesurer des distances de 2 à 300 cm.
    
3.  **Zone aveugle** : La zone aveugle du capteur, c'est-à-dire la distance minimale qu'il peut détecter, est de 2 cm.
    
4.  **Type de sortie** : Le capteur utilise une sortie contrôlée par UART.
    
5.  **Temps de réponse de sortie** : Le temps de réponse du capteur est de 10 ms. C'est le temps qu'il faut au capteur pour produire une mesure après avoir été déclenché.
    
6.  **Tension de fonctionnement** : Le capteur fonctionne avec une tension de 5 à 24 V DC.
    
7.  **Précision** : La précision du capteur est de ±(0.5 + S_0.5%) si la distance mesurée (S) est inférieure à 200 cm, et de ±(1 + S_1%) si la distance mesurée est supérieure à 200 cm.
    
8.  **Angle de détection** : L'angle de détection du capteur est de 5 à 10 degrés.
    
9.  **Niveau de protection du boîtier** : Le capteur a un niveau de protection IP68, ce qui signifie qu'il est étanche et peut fonctionner sous l'eau.
    
10.  **Profondeur maximale sous l'eau** : Le capteur peut fonctionner à une profondeur maximale de 10 mètres sous l'eau.
    
11.  **Couleur du boîtier** : Le boîtier du capteur est gris.
    
12.  **Médias de travail** : Le capteur est conçu pour fonctionner dans de l'eau propre.
    
13.  **Température ambiante** : Le capteur peut fonctionner dans des températures allant de -15 °C à 55 °C.
    
14.  **Connexion des fils** : Le fil rouge (VCC) se connecte à l'alimentation positive, le fil noir (GND) se connecte à l'alimentation négative, le fil jaune (RX) se connecte à la broche TX de l'Arduino, et le fil blanc (TX) se connecte à la broche RX de l'Arduino.

## Contribution

Les contributions à cette bibliothèque sont les bienvenues. N'hésitez pas à ouvrir une issue ou à soumettre une pull request.
