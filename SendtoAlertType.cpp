
const char* TEMPSTATUS = ["NORMAL","TOO LOW","TOO HIGH"];


AlertStatus sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return SENT;
}

AlertStatus sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);
  printf("Hi, the temperature is %s\n" ,TEMPSTATUS[breachType] );
  return SENT;
    
  }
