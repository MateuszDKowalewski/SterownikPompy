int rainLimit = 550;

bool isRaining(){
  if(analogRead(RAIN) <= rainLimit){
    return true;
  }else{
    return false;
  }
}

int howRainyIs(){
  return analogRead(RAIN);
}

