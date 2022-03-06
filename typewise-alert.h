#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef enum{
	SENT,
	NOT_SENT
}AlertStatus;

typedef AlertStatus (*sendTo)(AlertTarget);
sendTo SendAlert[c_NUM_ALERT_TARGETS] ={sendToController , sendToEmail };

const int c_PASSIVE_COOLING_LOWER_LIMIT = 0;
const int c_PASSIVE_COOLING_UPPER_LIMIT = 35;
const int c_HIACTIVE_COOLING_LOWER_LIMIT = 0;
const int c_HIACTIVE_COOLING_UPPER_LIMIT = 45;
const int c_MEDACTIVE_COOLING_LOWER_LIMIT = 0;
const int c_MEDACTIVE_COOLING_UPPER_LIMIT = 40;
const int c_NUM_COOLING_TYPES = 3;
const int c_NUM_ALERT_TARGETS = 2;

const int c_LOWER_LIMITS[c_NUM_COOLING_TYPES] = {c_PASSIVE_COOLING_LOWER_LIMIT,c_HIACTIVE_COOLING_LOWER_LIMIT,c_MEDACTIVE_COOLING_LOWER_LIMIT};
const int c_UPPER_LIMITS[c_NUM_COOLING_TYPES] ={c_PASSIVE_COOLING_UPPER_LIMIT,c_HIACTIVE_COOLING_UPPER_LIMIT,c_MEDACTIVE_COOLING_UPPER_LIMIT};
//typedef struct {
//  CoolingType coolingType;
//  char brand[48];
//} BatteryCharacter;

AlertStatus checkAndAlertifBreached(
  AlertTarget alertTarget, BreachType breachType);

AlertStatus sendToController(BreachType breachType);
AlertStatus sendToEmail(BreachType breachType);




