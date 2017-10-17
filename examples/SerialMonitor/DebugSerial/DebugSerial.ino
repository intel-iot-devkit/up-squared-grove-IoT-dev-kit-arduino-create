

int incomingByte = 0;   // for incoming serial data
void setup() {
        DebugSerial.begin(115200);     // opens serial port, sets data rate to 115200 bps
}
void loop() {
        // send data only when you receive data:
        if (DebugSerial.available() > 0) {
                // read the incoming byte:
                incomingByte = DebugSerial.read();
                // say what you got:
                DebugSerial.print("I received: ");
                DebugSerial.println(incomingByte, DEC);
        }
}