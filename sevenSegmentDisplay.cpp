#include <Arduino.h>
#include "sevenSegmentDisplay.h"


void resetDisplay()
{
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_DP, LOW);
}

void turnOffDisplay()
{
  digitalWrite(DISPLAY_A, HIGH);
  digitalWrite(DISPLAY_B, HIGH);
  digitalWrite(DISPLAY_C, HIGH);
  digitalWrite(DISPLAY_D, HIGH);
  digitalWrite(DISPLAY_E, HIGH);
  digitalWrite(DISPLAY_F, HIGH);
  digitalWrite(DISPLAY_G, HIGH);
  digitalWrite(DISPLAY_DP, HIGH);
}

void display(int input)
{
  switch (input)
  {
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