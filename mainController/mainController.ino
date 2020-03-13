#include <LcdKeypad.h>

LcdKeypad* myLcdKeypad = 0;

const int noKey = 0,
          selectMode = 1,
          leftMode = 2,
          rightMode = 3,
          upMode = 4,
          downMode = 5;

const int setLightIntensity = 0,
          setTemperatuer = 1,
          setHumidity = 2;

int pressedKey = 0, currentMode = 0;

byte setLightIntensityValue = 50,
     setHumidityValue = 100,
     setTemperatureValue = 240;

byte tempLightIntensityValue = 0,
     tempHumidityValue = 0,
     tempTemperatureValue = 0;


class MyLcdKeypadAdapter : public LcdKeypadAdapter {
  private:
    LcdKeypad* m_lcdKeypad;
    unsigned char m_value;

  public:
    MyLcdKeypadAdapter(LcdKeypad* lcdKeypad)
      : m_lcdKeypad(lcdKeypad)
      , m_value(7)
    {}

    void handleKeyChanged(LcdKeypad::Key newKey) {
      if (0 != m_lcdKeypad) {
        if (LcdKeypad::UP_KEY == newKey) {

          //          Serial.print("Key vlaue:");
          //          Serial.println(newKey);
          pressedKey = upMode;

        } else if (LcdKeypad::DOWN_KEY == newKey) {
          pressedKey = downMode;
          //          Serial.print("Key vlaue:");
          //          Serial.println(newKey);

        } else if (LcdKeypad::SELECT_KEY == newKey) {
          pressedKey = selectMode;
          //          Serial.print("Key vlaue:");
          //          Serial.println(newKey);

        } else if (LcdKeypad::LEFT_KEY == newKey) {
          pressedKey = leftMode;
          //          Serial.print("Key vlaue:");
          //          Serial.println(newKey);

        } else if (LcdKeypad::RIGHT_KEY == newKey) {
          pressedKey = rightMode;
          //          Serial.print("Key vlaue:");
          //          Serial.println(newKey);

        } else {
          pressedKey = noKey;
        }
       // m_lcdKeypad->setBackLightOn(true);
        //        m_lcdKeypad->setBacklight(static_cast<LcdKeypad::LcdBacklightColor>(LcdKeypad::LCDBL_BLUE & 10));

        //        m_lcdKeypad->setCursor(0, 1);
        //        m_lcdKeypad->print(m_value);
        //        m_lcdKeypad->print("                ");

      }
    }

};


void setup() {
  Serial.begin(9600);

  myLcdKeypad = new LcdKeypad();
  myLcdKeypad->attachAdapter(new MyLcdKeypadAdapter(myLcdKeypad));
  //  myLcdKeypad->setCursor(0, 0);
  //  myLcdKeypad->print("Value:");
  myLcdKeypad->setBackLightOn(true);

}

void loop() {

  pressedKey = 0;
  delay(100);
  switch (pressedKey) {
    case selectMode:
      {
        switch (currentMode) {
          case  setLightIntensity: {
              Serial.print("Saving value ");
              Serial.println(tempLightIntensityValue);
              setLightIntensityValue = tempLightIntensityValue;
              break;
            }
          case setTemperatuer: {
              Serial.print("Saving value ");
              Serial.println(tempTemperatureValue);
              setTemperatureValue = tempTemperatureValue;
              break;
            }
          case setHumidity: {
              Serial.print("Saving value ");
              Serial.println(tempHumidityValue);
              setHumidityValue = tempHumidityValue;
              break;
            }
        }
        break;
      }
    case  leftMode:
      {
        switch (currentMode) {
          case  setLightIntensity: {
              currentMode = setTemperatuer;
              tempTemperatureValue = setTemperatureValue;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Mode :-");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print("Set Temperature.");
              Serial.print("Current Mode : ");
              Serial.println(currentMode);
              break;
            }
          case setTemperatuer: {
              currentMode = setHumidity;
              tempHumidityValue = setHumidityValue;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Mode :-");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print("Set Humidity.");
              Serial.print("Current Mode : ");
              Serial.println(currentMode);
              break;
            }
          case setHumidity: {
              currentMode = setLightIntensity;
              tempLightIntensityValue = setLightIntensityValue;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Mode :-");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print("Set Lighting.");
              Serial.print("Current Mode : ");
              Serial.println(currentMode);
              break;
            }
          default: {
              break;
            }

        }
        break;
      }
    case  rightMode:
      {
        switch (currentMode) {
          case setLightIntensity: {
              currentMode = setHumidity;
              tempHumidityValue = setHumidityValue;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Mode :-");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print("Set Humidity.");
              Serial.print("Current Mode : ");
              Serial.println(currentMode);
              break;
            }
          case setTemperatuer: {
              currentMode = setLightIntensity;
              tempLightIntensityValue = setLightIntensityValue;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Mode :-");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print("Set Lighting.");
              Serial.print("Current Mode : ");
              Serial.println(currentMode);
              break;
            }
          case setHumidity: {
              currentMode = setTemperatuer;
              tempTemperatureValue = setTemperatureValue;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Mode :-");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print("Set Temperature.");
              Serial.print("Current Mode : ");
              Serial.println(currentMode);
              break;
            }
          default: {
              break;
            }

        }
        break;
      }
    case upMode:
      {
        switch (currentMode) {
          case setLightIntensity: {
              tempLightIntensityValue  = tempLightIntensityValue + 1;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Lighting val");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempLightIntensityValue);
              Serial.print("Light Set Point : ");
              Serial.println(tempLightIntensityValue);
              break;
            }
          case setTemperatuer: {
              tempTemperatureValue  = tempTemperatureValue + 1;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Temperature");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempTemperatureValue);
              Serial.print("Temperature Set point : ");
              Serial.println(tempTemperatureValue);
              break;
            }
          case setHumidity: {
              tempHumidityValue  = tempHumidityValue + 1;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Humidity");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempHumidityValue);
              Serial.print("Humidity set point : ");
              Serial.println(tempHumidityValue);
              break;
            }
          default: {
              //              currentMode = setLightIntensity;
              //              Serial.print("Current Mode : ");
              //              Serial.println(currentMode);
              break;
            }

        }
        break;
      }
    case downMode:
      {
        switch (currentMode) {
          case setLightIntensity: {
              tempLightIntensityValue  = tempLightIntensityValue - 1;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Lighting val");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempLightIntensityValue);
              Serial.print("Light Set Point : ");
              Serial.println(tempLightIntensityValue);
              break;
            }
          case setTemperatuer: {
              tempTemperatureValue  = tempTemperatureValue - 1;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Temperature");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempTemperatureValue);
              Serial.print("Temperature Set point : ");
              Serial.println(tempTemperatureValue);
              break;
            }
          case setHumidity: {
              tempHumidityValue  = tempHumidityValue - 1;
              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Humidity");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempHumidityValue);
              Serial.print("Humidity set point : ");
              Serial.println(tempHumidityValue);
              break;
            }
          default: {
              //              currentMode = setLightIntensity;
              //              Serial.print("Current Mode : ");
              //              Serial.println(currentMode);
              break;
            }

        }
        break;
      }

  }
}
//int getPressedKey() {
//
//  boolean last_press = LOW;
//
//  if (myLcdKeypad->isUpKey()) {
//    delay(50);
//    if (myLcdKeypad->isUpKey()) {
//      return upMode;
//    } else {
//      return noKey;
//    }
//
//  } else if (myLcdKeypad->isDownKey()) {
//    delay(50);
//    if (myLcdKeypad->isDownKey()) {
//      return downMode;
//    } else {
//      return noKey;
//    }
//  } else if (myLcdKeypad->isSelectKey()) {
//    delay(50);
//    if (myLcdKeypad->isSelectKey()) {
//      return selectMode;
//    } else {
//      return noKey;
//    }
//  } else if (myLcdKeypad->isLeftKey()) {
//    delay(50);
//    if (myLcdKeypad->isLeftKey()) {
//      return leftMode;
//    } else {
//      return noKey;
//    }
//  } else if (myLcdKeypad->isRightKey()) {
//    delay(50);
//    if (myLcdKeypad->isRightKey()) {
//      return rightMode;
//    } else {
//      return noKey;
//    }
//  } else {
//    return noKey;
//  }
//
//
//
//}
