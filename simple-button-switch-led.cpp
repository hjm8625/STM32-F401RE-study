#include "mbed.h"
DigitalOut led(LED1);
DigitalIn button(BUTTON1);
// main() runs in its own thread in the OS
int main()
{   bool state = 1; // using state of button
    while (true) {
        bool now = button.read();
        if (state == 1 && now == 0) {
            led = !led;
            ThisThread::sleep_for(200ms);
            // stop thread for 200ms -> solve the debounce problem
        }

        state = now;
        
    }
}
