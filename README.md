## UART on ATmega16

[UART](https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter) is the oldest and most common interface. 
Every MCUs has UART now. 

Here's the simple task. Create program sending every 1 sec letter 'A'. Question is how to check it. You can choose one of them:
- Oscilloscope
- [HyperTerminal](https://www.hilgraeve.com/hyperterminal-serial-port/) for Windows
- [Minicom](https://help.ubuntu.com/community/Minicom) for UNIX

## Installation

0. You can use another MCUs. All you need is datasheet. Don't forget change pins!  
1. Make project in AVR Studio choosing 8-bit MCU ATmega16.  
2. Copy code from `uart.c` into your `main.c` file.
3. Build project.

## License

Free
