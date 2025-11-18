#include "mbed.h"

// main() runs in its own thread in the OS
DigitalOut CS(D10);

SPI serialp(D11, D12, D13); // MOSI, MISO, SCLK
char send[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00};
            //1000000, 01000000, ... like transmit 1

int main() {
    serialp.format(8,0); // use 8 bit shift register
    serialp.frequency(1000000);
    CS = 1;
    
    for (char i : send) {
        CS = 0;
        serialp.write(i);
        CS = 1;
        thread_sleep_for(500);


    }
}

