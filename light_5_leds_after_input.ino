void setup() 
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.end();
  Serial.begin(9600);
}

void loop() 
{
  byte byteRead;
  int i = 0;
  if (Serial.available()) {
    byteRead = Serial.read() - '0';
    if ( (byteRead < 0) || (byteRead > 6) ) {
      Serial.print("Please insert a number between za ledurile pe care le am (adica 0-5)");
      Serial.print("\n");
    } else {
      if (digitalRead(byteRead + 1) == HIGH) {
        digitalWrite((byteRead + 1), LOW);
        delay(100);
      }
      else {
        digitalWrite((byteRead + 1), HIGH);
        delay(100);
      }
    }
  }
}
