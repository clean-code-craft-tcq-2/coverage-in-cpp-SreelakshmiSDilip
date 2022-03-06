#include "typewise-alert.h"
#include <stdio.h>

sendTo SendAlert[c_NUM_ALERT_TARGETS] ={sendToController , sendToEmail };

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
BreachType breachType = NORMAL;
  if(value < lowerLimit) {
    breachType =  TOO_LOW;
  }
  if(value > upperLimit) {
    breachType =  TOO_HIGH;
  }
  return breachType;
}

int getLowerLimitforBreach(CoolingType coolingType)
{
	return c_LOWER_LIMITS[coolingType];
}
int getUpperLimitforBreach(CoolingType coolingType)
{
	return c_UPPER_LIMITS[coolingType];
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  int lowerLimit = getLowerLimitforBreach(coolingType);
  int upperLimit = getUpperLimitforBreach(coolingType);
 
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

AlertStatus checkAndAlertifBreached(AlertTarget alertTarget, BreachType breachType) {

	AlertStatus alertStatus = NOT_SENT;

	if(NORMAL != breachType)
	{
		alertStatus = SendAlert[alertTarget](breachType);
	}
	return alertStatus;

}


