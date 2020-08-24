#include <Arduino.h>
#include "trafficLights.h"
#include "sevenSegmentDisplay.h"

int ledState = LOW;
unsigned long previousMillis = 0;
long interval = 250;

void runFirstState()
{

  digitalWrite(FIRST_LED, HIGH);
  for (int i = 9; i >= 0; i--)
  {
    resetDisplay();
    display(i);
    delay(1000);
    int counter = 0;
    if (i <= 5)
    {
      while (counter <= 6)
      {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval)
          previousMillis = currentMillis;

        if (ledState == LOW)
        {
          ledState = HIGH;
        }
        else
        {
          ledState = LOW;
        }

        digitalWrite(FIRST_LED, ledState);
        counter++;
        interval = 100;
        previousMillis = 0;
      }
    }
  }
  digitalWrite(FIRST_LED, LOW);
  turnOffDisplay();
}

void runSecondState()
{
  
    digitalWrite(SECOND_LED, HIGH);
    delay(100);
    digitalWrite(SECOND_LED, LOW);
    delay(100);
}

void runThirdState()
{
  digitalWrite(THIRD_LED, HIGH);
  for (int i = 5; i >= 0; i--)
  {
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
    runThirdState};

boolean direction = true;
int currentState = 1;

void setup()
{
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

void loop()
{

  (*lightStates[currentState - 1])();

  if (direction == true)
  {
    currentState++;
  }
  else
  {
    currentState--;
  }

  if ((currentState == NO_OF_STATES) || (currentState == FIRST_STATE))
  {
    direction = !direction;
  }
}
