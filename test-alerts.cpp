#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(12, 0, 30) == NORMAL);
  REQUIRE(inferBreach(35, 20, 30) == TOO_HIGH);
}

TEST_CASE("get the lower limit for breach ") {
  REQUIRE(getLowerLimitforBreach(PASSIVE_COOLING) == c_PASSIVE_COOLING_LOWER_LIMIT);
  REQUIRE(getLowerLimitforBreach(HI_ACTIVE_COOLING)  == c_HIACTIVE_COOLING_LOWER_LIMIT);
  REQUIRE(getLowerLimitforBreach(MED_ACTIVE_COOLING) == c_MEDACTIVE_COOLING_LOWER_LIMIT);
}

TEST_CASE("get the upper limit for breach ") {
  REQUIRE(getLowerLimitforBreach(PASSIVE_COOLING) == c_PASSIVE_COOLING_UPPER_LIMIT);
  REQUIRE(getLowerLimitforBreach(HI_ACTIVE_COOLING)  == c_HIACTIVE_COOLING_UPPER_LIMIT);
  REQUIRE(getLowerLimitforBreach(MED_ACTIVE_COOLING) == c_MEDACTIVE_COOLING_UPPER_LIMIT);
}



TEST_CASE("Classify temperature breach") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -3) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -4) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING ,-5) == TOO_LOW);

  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING ,45) == TOO_HIGH);

  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 25) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 30) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING ,35) == NORMAL);
}

  TEST_CASE("Check whether alert is sent or not when temperature is breached") {
  REQUIRE(checkAndAlertifBreached(TO_CONTROLLER, TOO_LOW) == SENT);
  REQUIRE(checkAndAlertifBreached(TO_EMAIL, TOO_LOW) == SENT);
  REQUIRE(checkAndAlertifBreached(TO_CONTROLLER, NORMAL) == NOT_SENT);  
  REQUIRE(checkAndAlertifBreached(TO_EMAIL, NORMAL) == NOT_SENT); 
  REQUIRE(checkAndAlertifBreached(TO_CONTROLLER, TOO_HIGH) == SENT);  
  REQUIRE(checkAndAlertifBreached(TO_EMAIL, TOO_HIGH) == SENT); 
}

