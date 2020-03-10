// https://www.carnetdumaker.net/articles/faire-plusieurs-choses-la-fois-avec-une-carte-arduino/
// https://www.jujens.eu/posts/2014/Jan/11/communication-serie-facile-python/
int pinBut=2;
int buzzer = 12;//the pin of the active buzzer
int valBut;

void setup() {
  Serial.begin(9600); //Initialisation de la communication avec la console
  pinMode(pinBut, INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
}

void transmission_etat_bouton() {
  valBut = digitalRead(pinBut);
  if (valBut == LOW)
  {
    Serial.println("1");
  }
  else {
    Serial.println("0");
  }
}

void ecoute_etat_clavier() {
    
    //delay(500);//wait for 1ms
    //digitalWrite(buzzer,LOW);
    while(Serial.available()) {
      int lu = Serial.read();
      if (lu == 1)
        digitalWrite(buzzer,HIGH);
    }
}

void loop() {
  ecoute_etat_clavier();
  transmission_etat_bouton();
}
