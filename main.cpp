#include <Arduino.h>

int led = 13;                // pin sur leuel la led est connecté
int sensor = 8;              // pin sur lequel le detecteur PIR est connecté
int state = LOW;             // met le status comme LOW par défaut
int val = 0;                 // variable qui enregistre la valeure du detecteur PIR

void setup() {
  pinMode(led, OUTPUT);      // setup le pin de la led comme une output
  pinMode(sensor, INPUT);    // setup le pin de decteur PIR comme un input
  Serial.begin(9600);        // initialise la série
}

void loop(){
  val = digitalRead(sensor);   // récupère la valeure du decteur PIR
  if (val == HIGH) {           // vérifie si val est égal à HIGH
    digitalWrite(led, HIGH);   // si val est HIGH , allume la led

    if (state == LOW) {                       //vérifie si state est égal à LOW
      Serial.println("Motion detected!");     //Print Motion detected
      for (int i = 5; i >= 0; i--)            //boucle for avec i qui commence à 5 et qui se décrémente de 1 à chaque itération jusqu'a ce que i soit égal à 0
      {
        Serial.println(i);                    //Print la valeur de i pour afficher combien de temps il reste
        delay(1000);                          //delay de 1000ms
      }
      state = HIGH;       // Remet la valeur en high
    }
  } 
  else {
      digitalWrite(led, LOW); // éteint la led
      delay(50);              // delais de 50 milliseconds 
      if (state == HIGH){     // vérifie si state est égal à HIGH
        Serial.println("Motion stopped!");    //Print motion sotpped
        state = LOW;       // remet state omme égal à low  LOW
    }
  }
}
