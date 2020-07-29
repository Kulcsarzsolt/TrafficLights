#define FIRST_LED 11
#define SECOND_LED 12
#define THIRD_LED 13
#define NO_OF_STATES 3
#define FIRST_STATE 1

int lightStates[3] = {
  FIRST_LED,
  SECOND_LED,
  THIRD_LED
};

boolean direction = true;
int currentState = 1;

void setup() {
  Serial.begin(9600);
  pinMode(FIRST_LED, OUTPUT);
  pinMode(SECOND_LED, OUTPUT);
  pinMode(THIRD_LED, OUTPUT);

}

void loop() {
  digitalWrite(lightStates[currentState-1], HIGH);
  delay(500);
  digitalWrite(lightStates[currentState-1], LOW);

  if (direction == true) {
    currentState++;
  } else {
    currentState--;
  }

  if ((currentState == NO_OF_STATES) || (currentState == FIRST_STATE)) {
    direction = !direction;
  }
}
