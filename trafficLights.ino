#define FIRST_LED 11
#define SECOND_LED 12
#define THIRD_LED 13
#define NO_OF_STATES 3
#define FIRST_STATE 1

void runFirstState(){
  digitalWrite(FIRST_LED, HIGH);
  delay(500);
  digitalWrite(FIRST_LED, LOW);

}

void runSecondState(){
  digitalWrite(SECOND_LED, HIGH);
  delay(500);
  digitalWrite(SECOND_LED, LOW);

}

void runThirdState(){
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
  Serial.begin(9600);
  pinMode(FIRST_LED, OUTPUT);
  pinMode(SECOND_LED, OUTPUT);
  pinMode(THIRD_LED, OUTPUT);

}

void loop() {

  (*lightStates[currentState-1])();
  
  if (direction == true) {
    currentState++;
  } else {
    currentState--;
  }

  if ((currentState == NO_OF_STATES) || (currentState == FIRST_STATE)) {
    direction = !direction;
  }
}
