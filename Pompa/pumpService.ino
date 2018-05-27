bool isTime;
bool isRain;

void check(){
  isRain = isRaining();
  isTime = isGoodTime();
}

bool runPump(){
  if((isTime == true) && (isRain == false)){
    return true;
  }else{
    return false;
  }
}

