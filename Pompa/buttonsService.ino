byte buttons[8];
byte pressed[8];

void buttonsSetup(){
  pinMode(OPTION_1, INPUT);
  pinMode(OPTION_2, INPUT);
  pinMode(OPTION_3, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(MENU, INPUT);
  pinMode(MINUS, INPUT);
  pinMode(PLUS, INPUT);

  buttons[0] = 0;
  buttons[1] = 0;
  buttons[2] = 0;
  buttons[3] = 0;
  buttons[4] = 0;
  buttons[5] = 0;
  buttons[6] = 0;
  buttons[7] = 0;
}

void buttonsReset(){
  pressed[0] = 0;
  pressed[1] = 0;
  pressed[2] = 0;
  pressed[3] = 0;
  pressed[4] = 0;
  pressed[5] = 0;
  pressed[6] = 0;
  pressed[7] = 0;
}

bool wasButtonPressed(int button){
  switch(button){
    case OPTION_1:
      if(pressed[0] == 1){
        return true;
      }
    break;

    case OPTION_2:
      if(pressed[1] == 1){
        return true;
      }
    break;

    case OPTION_3:
      if(pressed[2] == 1){
        return true;
      }
    break;

    case MENU:
      if(pressed[3] == 1){
        return true;
      }
    break;

    case LEFT:
      if(pressed[4] == 1){
        return true;
      }
    break;

    case RIGHT:
      if(pressed[5] == 1){
        return true;
      }
    break;

    case PLUS:
      if(pressed[6] == 1){
        return true;
      }
    break;

    case MINUS:
      if(pressed[7] == 1){
        return true;
      }
    break;
  }

  return false;
}

void buttonCheckState(){
  if(digitalRead(OPTION_1) == LOW){
    buttons[0] = 1;
  }else{
    if(buttons[0] == 1){
      //Serial.println(1);
      pressed[0] = 1;
      delay(20);
    }
    buttons[0] = 0;
  }

  if(digitalRead(OPTION_2) == LOW){
    buttons[1] = 1;
  }else{
    if(buttons[1] == 1){
      //Serial.println(2);
      pressed[1] = 1;
      delay(20);
    }
    buttons[1] = 0;
  }

  if(digitalRead(OPTION_3) == LOW){
    buttons[2] = 1;
  }else{
    if(buttons[2] == 1){
      //Serial.println(3);
      pressed[2] = 1;
      delay(20);
    }
    buttons[2] = 0;
  }

  if(digitalRead(MENU) == LOW){
    buttons[3] = 1;
  }else{
    if(buttons[3] == 1){
      //Serial.println("MENU");
      pressed[3] = 1;
      delay(20);
    }
    buttons[3] = 0;
  }

  if(digitalRead(LEFT) == LOW){
    buttons[4] = 1;
  }else{
    if(buttons[4] == 1){
      //Serial.println("LEFT");
      pressed[4] = 1;
      delay(20);
    }
    buttons[4] = 0;
  }

  if(digitalRead(RIGHT) == LOW){
    buttons[5] = 1;
  }else{
    if(buttons[5] == 1){
      //Serial.println("RIGHT");
      pressed[5] = 1;
      delay(20);
    }
    buttons[5] = 0;
  }

  if(digitalRead(PLUS) == LOW){
    buttons[6] = 1;
  }else{
    if(buttons[6] == 1){
      //Serial.println("+");
      pressed[6] = 1;
      delay(20);
    }
    buttons[6] = 0;
  }

  if(digitalRead(MINUS) == LOW){
    buttons[7] = 1;
  }else{
    if(buttons[7] == 1){
      //Serial.println("-");
      pressed[7] = 1;
      delay(20);
    }
    buttons[7] = 0;
  }
}

