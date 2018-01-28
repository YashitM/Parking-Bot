#include "rgb_lcd.h";
#include <Stepper.h>

const int stepsPerRevolution = 200;
int sensorPin1 = A0;
int sensorValue1 = 0;
int sensorPin2 = A1;
int sensorValue2 = 0;

int Pin1 = 10;
int Pin2 = 11;
int Pin3 = 12;
int Pin4 = 13;

rgb_lcd lcd;

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    pinMode(Pin1, OUTPUT);
    pinMode(Pin2, OUTPUT);
    pinMode(Pin3, OUTPUT);
    pinMode(Pin4, OUTPUT);
}

void move_front()
{
    for (int i = 0; i < 8; i++)
    {
        switch (i)
        {
        case 0:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, HIGH);
            break;
        case 1:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, HIGH);
            digitalWrite(Pin4, HIGH);
            break;
        case 2:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, HIGH);
            digitalWrite(Pin4, LOW);
            break;
        case 3:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, HIGH);
            digitalWrite(Pin3, HIGH);
            digitalWrite(Pin4, LOW);
            break;
        case 4:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, HIGH);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, LOW);
            break;
        case 5:
            digitalWrite(Pin1, HIGH);
            digitalWrite(Pin2, HIGH);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, LOW);
            break;
        case 6:
            digitalWrite(Pin1, HIGH);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, LOW);
            break;
        case 7:
            digitalWrite(Pin1, HIGH);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, HIGH);
            break;
        default:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, LOW);
            break;
        }
    }
}

void move_back()
{
    for (int i = 7; i >= 0; i--)
    {
        switch (i)
        {
        case 0:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, HIGH);
            break;
        case 1:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, HIGH);
            digitalWrite(Pin4, HIGH);
            break;
        case 2:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, HIGH);
            digitalWrite(Pin4, LOW);
            break;
        case 3:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, HIGH);
            digitalWrite(Pin3, HIGH);
            digitalWrite(Pin4, LOW);
            break;
        case 4:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, HIGH);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, LOW);
            break;
        case 5:
            digitalWrite(Pin1, HIGH);
            digitalWrite(Pin2, HIGH);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, LOW);
            break;
        case 6:
            digitalWrite(Pin1, HIGH);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, LOW);
            break;
        case 7:
            digitalWrite(Pin1, HIGH);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, HIGH);
            break;
        default:
            digitalWrite(Pin1, LOW);
            digitalWrite(Pin2, LOW);
            digitalWrite(Pin3, LOW);
            digitalWrite(Pin4, LOW);
            break;
        }
    }
}

void loop()
{
    lcd.setRGB(102, 0, 102);
    sensorValue1 = analogRead(sensorPin1);
    sensorValue2 = analogRead(sensorPin2);
    move_front();
    delay(1000);
    move_back();
    lcd.clear();
    lcd.setCursor(0, 0);
    if (sensorValue1 > 850 && sensorValue2 > 850)
    {
        // First Parking Empty and Second Parking Empty
        char toPrint[100] = "A2 & B1 Vacant";
        Serial.println(toPrint);
        lcd.println(toPrint);
    }
    else if (sensorValue1 <= 850 && sensorValue2 <= 850)
    {
        // First Parking Full and Second Parking Full
        // Motor should be at the parking B
        char toPrint[100] = "No Parking";
        Serial.println(toPrint);
        lcd.println(toPrint);
    }
    else if (sensorValue1 > 850 && sensorValue2 <= 850)
    {
        // First Parking Empty and Second Parking Full
        // Stepper Motor should be at home position.

        char toPrint[100] = "Park in A2--->>> ";
        Serial.println(toPrint);
        lcd.println(toPrint);
    }
    else if (sensorValue1 <= 850 && sensorValue2 > 850)
    {
        // First Parking Full and Second Parking Empty
        // Motor should be at position B
        char toPrint[100] = "Park in B1--->>> ";
        Serial.println(toPrint);
        lcd.println(toPrint);
    }
    delay(1000);
}