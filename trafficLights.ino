#define FIRST_LED 11
#define SECOND_LED 12
#define THIRD_LED 13
#define NO_OF_STATES 3
#define FIRST_STATE 1
#define DISPLAY_A 3
#define DISPLAY_B 2
#define DISPLAY_C 7
#define DISPLAY_D 8
#define DISPLAY_E 9
#define DISPLAY_F 4
#define DISPLAY_G 5
#define DISPLAY_DP 6

void runFirstState() {
  digitalWrite(FIRST_LED, HIGH);
  delay(500);
  digitalWrite(FIRST_LED, LOW);
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
  delay(500);
  digitalWrite(THIRD_LED, LOW);

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
