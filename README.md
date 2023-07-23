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
