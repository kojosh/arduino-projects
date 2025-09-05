const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 0;

void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void loop() {
  // Read state of On/Off switch
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  // Read state of direction switch
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin) / 4;

  // If current switch state differs with previous state
  // And if the switch is currently HIGH, set motorEnabled on
  if(onOffSwitchState != previousOnOffSwitchState) {
    if(onOffSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }

  // If direction switch differs with previous state
  // Change motor direction
  if(directionSwitchState != previousDirectionSwitchState) {
    if(directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }
  if(motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  if(motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  }
  else {
    analogWrite(enablePin, 0);
  }

  // Save current state of switches
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}
