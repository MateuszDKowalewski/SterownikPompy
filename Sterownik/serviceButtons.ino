bool lastState[4];
//Contain buttons state in last turn of loop
//0 - ENTER
//1 - ESCAPE
//2 - LEFT
//3 - RIGHT

bool currentState[4];
//Contain buttons state in current turn of loop
//0 - ENTER
//1 - ESCAPE
//2 - LEFT
//3 - RIGHT

bool justBumpped[4];
//Contains buttons state
//TRUE - button just bumpped
//FALSE - button do not bumpped
//0 - ENTER
//1 - ESCAPE
//2 - LEFT
//3 - RIGHT

void setupButtons() {
  //Setting up all buttons
  //It have to be run in main setup function

  pinMode(ENTER, INPUT_PULLUP);
  pinMode(ESCAPE, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);

  lastState[0] = true;
  lastState[1] = true;
  lastState[2] = true;
  lastState[3] = true;

  currentState[0] = true;
  currentState[1] = true;
  currentState[2] = true;
  currentState[3] = true;

  justBumpped[0] = false;
  justBumpped[1] = false;
  justBumpped[2] = false;
  justBumpped[3] = false;
}

bool wasButtonBumpped(int button_id) {
  //Return true when button was just pressed and false otherwise
  //Button_id contains id of button to check

  switch (button_id) {
    case ENTER:
      return justBumpped[0];
      break;

    case ESCAPE:
      return justBumpped[1];
      break;

    case LEFT:
      return justBumpped[2];
      break;

    case RIGHT:
      return justBumpped[3];
      break;

    default:
      return false;
      break;
  }
}

void buttonsCheckState() {
  //It have to be run in all turn of loop before any other action

  justBumpped[0] = false;
  justBumpped[1] = false;
  justBumpped[2] = false;
  justBumpped[3] = false;

  currentState[0] = digitalRead(ENTER);
  currentState[1] = digitalRead(ESCAPE);
  currentState[2] = digitalRead(LEFT);
  currentState[3] = digitalRead(RIGHT);

  //Check state of all buttons
  //If it is different than in last turn of loop wait 20ms
  //If button was just realised set justBumpped to true

  for (int i = 0; i < 4; i++) {
    if (currentState[i] != lastState[i]) {
      delay(20);
      justBumpped[i] = currentState[i];
    }
  }

  lastState[0] = currentState[0];
  lastState[1] = currentState[1];
  lastState[2] = currentState[2];
  lastState[3] = currentState[3];
}
