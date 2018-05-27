bool isTime;
bool isRain;
bool isON;

void setON(bool b){
  isON = b;
}

void check(){
  isRain = isRaining();
  isTime = isGoodTime();
}

bool runPump(){
  if((isTime == true) && (isRain == false) && (isON == true)){
    return true;
  }else{
    return false;
  }
}
