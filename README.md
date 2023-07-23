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

## Contribution

Les contributions à cette bibliothèque sont les bienvenues. N'hésitez pas à ouvrir une issue ou à soumettre une pull request.
