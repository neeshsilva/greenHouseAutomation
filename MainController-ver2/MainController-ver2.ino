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

int pressedKey = 0,
    currentMode = 0;

byte setLightIntensityValue = 50,
     setHumidityValue = 100,
     setTemperatureValue = 240;

byte tempLightIntensityValue = 0,
     tempHumidityValue = 0,
     tempTemperatureValue = 0;

boolean showCurrentValue = HIGH;


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

  if (showCurrentValue) {
    myLcdKeypad->clear();
    myLcdKeypad->setCursor(0, 0);
    myLcdKeypad->print("Hum. ");
    myLcdKeypad->setCursor(5, 0);
    myLcdKeypad->print("Temp. ");
    myLcdKeypad->setCursor(11, 0);
    myLcdKeypad->print("Intes");

    myLcdKeypad->setCursor(0, 1);
    myLcdKeypad->print(setHumidityValue);
    myLcdKeypad->setCursor(5, 1);
    myLcdKeypad->print(setTemperatureValue);
    myLcdKeypad->setCursor(11, 1);
    myLcdKeypad->print(setLightIntensityValue);
    delay(50);
  }

  switch (pressedKey) {

    case selectMode: {
        showCurrentValue = LOW;
        switch (currentMode) {
          case setLightIntensity: {
              setLightIntensityValue = tempLightIntensityValue;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Saving Light");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print("Intensity Level");

              showCurrentValue = HIGH;
              delay(2000);
              break;
            }
          case setTemperatuer: {
              setTemperatureValue = tempTemperatureValue;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Saving Temperat");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print("ure Level");

              showCurrentValue = HIGH;
              delay(2000);
              break;
            }
          case setHumidity: {
              setHumidityValue = tempHumidityValue;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Saving Humidity");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print("Level");

              showCurrentValue = HIGH;
              delay(2000);
              break;
            }
        }
        break;

      }
    case leftMode: {
        showCurrentValue = LOW;
        switch (currentMode) {
          case  setLightIntensity: {
              currentMode = setTemperatuer;
              tempTemperatureValue = setTemperatureValue;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Temperature");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempTemperatureValue);

              break;
            }
          case setTemperatuer: {
              currentMode = setHumidity;
              tempHumidityValue = setHumidityValue;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Humidity");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempHumidityValue);

              break;
            }
          case setHumidity: {
              currentMode = setLightIntensity;
              tempLightIntensityValue = setLightIntensityValue;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Lighting val");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempLightIntensityValue);

              break;
            }
        }

        break;
      }
    case rightMode: {
        showCurrentValue = LOW;

        switch (currentMode) {
          case setLightIntensity: {
              currentMode = setHumidity;
              tempHumidityValue = setHumidityValue;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Humidity");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempHumidityValue);

              break;
            }
          case setTemperatuer: {
              currentMode = setLightIntensity;
              tempLightIntensityValue = setLightIntensityValue;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Lighting val");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempLightIntensityValue);

              break;
            }
          case setHumidity: {
              currentMode = setTemperatuer;
              tempTemperatureValue = setTemperatureValue;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Temperature");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempTemperatureValue);

              break;
            }
        }

        break;
      }
    case upMode: {
        showCurrentValue = LOW;
        switch (currentMode) {
          case setLightIntensity: {
              tempLightIntensityValue  = tempLightIntensityValue + 1;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Lighting val");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempLightIntensityValue);

              break;
            }
          case setTemperatuer: {
              tempTemperatureValue  = tempTemperatureValue + 1;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Temperature");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempTemperatureValue);

              break;
            }
          case setHumidity: {
              tempHumidityValue  = tempHumidityValue + 1;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Humidity");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempHumidityValue);

              break;
            }
        }
        break;
      }
    case downMode: {
        showCurrentValue = LOW;
        switch (currentMode) {
          case setLightIntensity: {
              tempLightIntensityValue  = tempLightIntensityValue - 1;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Lighting val");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempLightIntensityValue);

              break;
            }
          case setTemperatuer: {
              tempTemperatureValue  = tempTemperatureValue - 1;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Temperature");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempTemperatureValue);

              break;
            }
          case setHumidity: {
              tempHumidityValue  = tempHumidityValue - 1;

              myLcdKeypad->clear();
              myLcdKeypad->setCursor(0, 0);
              myLcdKeypad->print("Set Humidity");
              myLcdKeypad->setCursor(0, 1);
              myLcdKeypad->print(tempHumidityValue);

              break;
            }
        }
        break;
      }
  }

}
