/*
 * Homework for Coursera MOOC by EPFL
 * Statistics of buttons pressed
 *
 * On presse alternativement et irrégulièrement sur le poussoir Pous1 et sur 
 * le poussoir Pous2. Le programme doit compter les pressions sur Pou1 et sur Pous2. 
 * Il doit allumer Led1 si on a pressé plus souvent sur Pous1. 
 * Il doit allumer Led2 si c'est le contraire. 
 * Au début du programme et en cas d'égalité, aucune Led ne dois s'allumer.
 * Pour contrôler votre programme, le correcteur enverra des "pression" sur 
 * Pous1 et Pous2 d'une durée d'environ 0.2s, séparées par une demi-seconde, 
 * sans rebonds de contacts.
 */
#define TIME 200

const int L1 = 4; // 
const int L2 = 5; // 
const int P1 = 2; // 
const int P2 = 3; // 
int P1_pressed = 0; // 
int P2_pressed= 0; // 
int start_time = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);  
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
}

void loop()
{
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  start_time = millis();
  while (millis() - start_time < TIME) {
    if (!digitalRead(P1)) {
      P1_pressed++;
    }
    if (!digitalRead(P2)) {
      P2_pressed++;
    }
  }
  
  if (P1_pressed > P2_pressed) {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
  } else if (P1_pressed < P2_pressed) {
    digitalWrite(L2, HIGH);
    digitalWrite(L1, LOW);
  } else {
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
  }
  
  P1_pressed = 0;
  P2_pressed = 0;
  
  delay(500);
}
