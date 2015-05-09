/*
 * Homework for Coursera MOOC by EPFL - week 3
 * SOS du Titanic!
 *
 * Le programme doit produire un signal de détresse lumineux 
 * en code Morse, sur la Led L1. 
 * Voici la succession des traits et des point pour former "S O S" : 
 * . . . - - - . . . 
 * Le message doit être répété en continu, comme des "mots" séparés 
 * (en respectant donc l'espace entre les mots).
 *
 * Voici les contraintes temporelles : - durée d'un point (dot) : 0.2s - 
 * durée d'un trait (dash) : 0.6s - espace entre traits ou points : 0.2s - 
 * espace entre lettres : 0.6s - espace entre mots : 1.4s
 */

#define TIME_POINT 200 // duration of a point
#define TIME_DASH 600 // duration of a dash
#define TIME_SPACE_P_D 200 // duration of a space between dash/point
#define TIME_SPACE_LET 600 // duration of a space between letters
#define TIME_SPACE_WORDS 1400 // duration of a space between words

const int L1 = 4; // Is lit if button P1 was pushed more times in 0.2s
void letter_S();
void letter_O();
void space_letters();
void space_words();

void setup()
{
  Serial.begin(9600);
  pinMode(L1, OUTPUT);
}

void loop()
{
  letter_S();
  space_letters();
  letter_O();
  space_letters();
  letter_S();
  space_words();
}


void letter_S()
{
  // leter S in Morse code is: ". . ."
  digitalWrite(L1, HIGH); // point
  delay(TIME_POINT);
  digitalWrite(L1, LOW); // space point
  delay(TIME_SPACE_P_D);
  digitalWrite(L1, HIGH); // point
  delay(TIME_POINT);
  digitalWrite(L1, LOW); // space point
  delay(TIME_SPACE_P_D);
  digitalWrite(L1, HIGH); // point
  delay(TIME_POINT);
}

void letter_O()
{
  // letter O in Morse code is "- - -"
  digitalWrite(L1, HIGH);
  delay(TIME_DASH);
  digitalWrite(L1, LOW);
  delay(TIME_SPACE_P_D);
  digitalWrite(L1, HIGH);
  delay(TIME_DASH);
  digitalWrite(L1, LOW);
  delay(TIME_SPACE_P_D);
  digitalWrite(L1, HIGH);
  delay(TIME_DASH);
}

void space_letters()
{
  digitalWrite(L1, LOW);
  delay(TIME_SPACE_LET);
}

void space_words()
{
  digitalWrite(L1, LOW);
  delay(TIME_SPACE_WORDS);
}
