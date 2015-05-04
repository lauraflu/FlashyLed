/*
 * Homework for Coursera MOOC by EPFL
 * System for controlling the flow of cars in a parking lot.
 *
 * There are two leds for signaling if the parking lot is empty or full
 * and two buttons for the entrance and departure barriers.
 * The circuit follows the format of the LearnCBot shield for Arduino,
 * thus the leds and buttons are connected to certain pins and the
 * buttons are considered pressed when "0" and released when "1".
 */

#define WAIT 5

const int L1 = 4; // lit if a car must wait to enter the lot (there are 5 cars in the lot)
const int L2 = 5; // lit if the parking lot is empty
const int P1 = 2; // button which controls the entrance barrier
const int P2 = 3; // button which controls the departure barrier
int P1_state = 0; // button 1 pressed?
int P2_state = 0; // button 2 pressed?
int cars = 0; // number of cars in a lot at a time

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
  if (cars == 0) {
    digitalWrite(L2, HIGH); // parking lot is empty
    P1_state = digitalRead(P1);
    if (!P1_state) {
      cars++; // a car enters the parking lot
      digitalWrite(L2, LOW); // parking lot is no longer empty
      Serial.println("Cars in the parking lot: ");
      Serial.println(cars);
    }
    // no car can leave the parking lot, don't test P2
  } else if (cars == WAIT) {
    digitalWrite(L1, HIGH); // if there are more than 5 cars in the parking lot, L1 is lit
    P1_state = digitalRead(P1);
    if (!P1_state) {
      cars++; // a car enters the parking lot
      // digitalWrite(L1, LOW);
      Serial.println("Cars in the parking lot: ");
      Serial.println(cars);
    }
    P2_state = digitalRead(P2);
    if (!P2_state) {
      cars--; // a car exits the parking lot
      digitalWrite(L1, LOW);
      Serial.println("Cars in the parking lot: ");
      Serial.println(cars);
    }
  } else {
    
    P1_state = digitalRead(P1);
    if (!P1_state) {
      cars++; // a car enters the parking lot
      Serial.println("Cars in the parking lot: ");
      Serial.println(cars);
    }
    P2_state = digitalRead(P2);
    if (!P2_state) {
      cars--; // a car exits the parking lot
      Serial.println("Cars in the parking lot: ");
      Serial.println(cars);
    }
  } 
   
  delay(20);
  
}
