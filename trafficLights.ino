#include "trafficLights.h"

void resetDisplay() {
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_DP, LOW);
}

void turnOffDisplay() {
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_DP, HIGH);
}

void display(int input) {
  switch (input) {
  case 0:
    digitalWrite(DISPLAY_G, HIGH);
    break;
  case 1:
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, HIGH);
    digitalWrite(DISPLAY_F, HIGH);
    digitalWrite(DISPLAY_G, HIGH);
    break;
  case 2:
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_F, HIGH);
    break;
  case 3:
    digitalWrite(DISPLAY_E, HIGH);
    digitalWrite(DISPLAY_F, HIGH);
    break;
  case 4:
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, HIGH);
    break;
  case 5:
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_E, HIGH);
    break;
  case 6:
    digitalWrite(DISPLAY_B, HIGH);
    break;
  case 7:
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, HIGH);
    digitalWrite(DISPLAY_F, HIGH);
    digitalWrite(DISPLAY_G, HIGH);
    break;
  case 8:
    break;
  case 9:
    digitalWrite(DISPLAY_E, HIGH);
    break;
  default:
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_C, HIGH);
  }
}

void runFirstState() {

  digitalWrite(FIRST_LED, HIGH);
  for (int i = 9; i >= 0; i--) {
    resetDisplay();
    display(i);
    delay(1000);

  }
  digitalWrite(FIRST_LED, LOW);
  turnOffDisplay();
}


void runSecondState() {
  int i = 0;
  while (i < 4) {
    digitalWrite(SECOND_LED, HIGH);
    delay(100);
    digitalWrite(SECOND_LED, LOW);
    delay(100);

    i++;
  }
}

void runThirdState() {
  digitalWrite(THIRD_LED, HIGH);
  for (int i = 5; i >= 0; i--) {
    resetDisplay();
    display(i);
    delay(1000);
  }
  digitalWrite(THIRD_LED, LOW);
  turnOffDisplay();

}

void (*lightStates[3])() = {
  runFirstState,
  runSecondState,
  runThirdState
};


boolean direction = true;
int currentState = 1;


void setup() {
  pinMode(FIRST_LED, OUTPUT);
  pinMode(SECOND_LED, OUTPUT);
  pinMode(THIRD_LED, OUTPUT);
  pinMode(DISPLAY_A, OUTPUT);
  pinMode(DISPLAY_B, OUTPUT);
  pinMode(DISPLAY_C, OUTPUT);
  pinMode(DISPLAY_D, OUTPUT);
  pinMode(DISPLAY_E, OUTPUT);
  pinMode(DISPLAY_F, OUTPUT);
  pinMode(DISPLAY_G, OUTPUT);
  pinMode(DISPLAY_DP, OUTPUT);
}

void loop() {
  (*lightStates[currentState - 1])();

  if (direction == true) {
    currentState++;
  }
  else {
    currentState--;
  }

  if ((currentState == NO_OF_STATES) || (currentState == FIRST_STATE)) {
    direction = !direction;
  }
}
