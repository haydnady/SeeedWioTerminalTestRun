/* rawSend.ino Example sketch for IRLib2
 *  Illustrates how to send a code Using raw timings which were captured
 *  from the "rawRecv.ino" sample sketch.  Load that sketch and
 *  capture the values. They will print in the serial monitor. Then you
 *  cut and paste that output into the appropriate section below.
 */
#include <IRLibSendBase.h> // We need the base code
#include <IRLib_HashRaw.h> // Only use raw sender

IRsendRaw mySender;

/* Cut and paste the output from "rawRecv.ino" below here. It will 
 * consist of a #define RAW_DATA_LEN statement and an array definition
 * beginning with "uint16_t rawData[RAW_DATA_LEN]= {…" and concludes
 * with "…,1000};"
 */

const uint16_t RAW_DATA_LEN = 68;

uint16_t rawData[RAW_DATA_LEN] = {4600,4350,700,1550,650,1550,650,1600,650,450,650,450,650,450,650,450,700,400,700,1550,650,1550,650,1600,650,450,650,450,650,450,700,450,650,450,650,450,650,1550,700,450,650,450,650,450,650,450,650,450,700,400,650,1600,650,450,650,1550,650,1600,650,1550,650,1550,700,1550,650,1550,650};

/*
 * Cut-and-paste into the area above.
 */


void setup()
{
    Serial.begin(9600);
    delay(2000);
    while (!Serial)
        ; //delay for Leonardo
    Serial.println(F("Every time you press a key is a serial monitor we will send."));
}


void loop()
{
    if (Serial.read() != -1)
    {
        //send a code every time a character is received from the
        // serial port. You could modify this sketch to send when you
        // push a button connected to an digital input pin.
        mySender.send(rawData, RAW_DATA_LEN, 36); //Pass the buffer,length, optionally frequency
        Serial.println(F("Sent signal."));
    }
}