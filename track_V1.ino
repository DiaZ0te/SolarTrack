#include <Servo.h>// on importe la bibliothèque
Servo servo1,servo2; // on crée l'objet Servo
int angle=0;
int angle2=180;
int pinServo1=9; // on définit le pin lié à la commande du servo1
int pinServo2=8; // on définit le pin lié à la commande du servo2
int pinR1=A1; // on définit le pin lié à la lecture de la R1 (en haut à gauche)
int pinR2=A2;  // on définit le pin lié à la lecture de la R2 (en haut à droite)
int pinR3=A3;  // on définit le pin lié à la lecture de la R3 (en bas à droite)
int pinR4=A4;  // on définit le pin lié à la lecture de la R3 (en bas à gauche)
int  Rh;
int Rb;

void setup() {
  servo1.attach(pinServo1); // on relie l'objet servo au pin de commande
  servo2.attach(pinServo2); // on relie l'objet servo au pin de commande
  Serial.begin(9600);
}

void loop() {
    int R1=analogRead(pinR1); // lecture de la valeur du potentiomètre
    int R2=analogRead(pinR2); // lecture de la valeur du potentiomètre
    int R3=analogRead(pinR3); // lecture de la valeur du potentiomètre
    int R4=analogRead(pinR4); // lecture de la valeur du potentiomètre
    Serial.println(R1);
    Serial.println(R2);
    Serial.println(R3);
    Serial.println(R4);
    delay(50);
    
    if((R1-R2)>50)
    {
      ////Tourne vers la droite
      angle=angle+5;
    }
    if ((R2-R1)>50)
    {
      ////Tourne vers la gauche
      angle=angle-5;
    }    
   Rh=(R1+R2)/2;
   Rb= (R3+R4)/2;
    if((Rh-R3)>50)
    {
      ////Tourne vers le haut
      angle2=angle2+5;
    }
    
    if ((Rb-Rh)>50)
    {
      ////Tourne vers le bas
      angle2=angle2-5;
    }

    if (angle<=0)
    {
      angle=0;
    }
    if (angle>=180)
    {
      angle=180;
    }
    if (angle2>=180)
    {
      angle2=0;
    }
    if (angle2<=0)
    {
      angle2=180;
    }

    servo1.write(angle);
    servo2.write(angle2);
    Serial.println(angle);
    Serial.println(angle2);
}
