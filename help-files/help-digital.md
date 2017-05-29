# Digital I/O

| Ribbon Pin | Use / RPi Number |
| ---------- |:---------------- |
| 1          | 5v               |
| 2          | Ground           |
| 3          | BCM 14 (TXD)     |
| 4          | BCM 15 (RXD)     |
| 5          | BCM 18           |
| 6          | BCM 17           |
| 7          | BCM 4            |
| 8          | BCM 3 (SCL)      |
| 9          | BCM 2 (SDA)      |
| 10         | 3v3              |


The ribbon header has 7 digital pins available (after the 5v, 3v3, and Ground pins). Please note that a Raspberry pi can supply less current per pin, as well as less total current, than an Arduino, and that it operates at a 3v3 logic level. Some devices components (such as relays) may not operate correctly at this voltage, and attempting to input a full 5v will damage the board. Digital input (buttons, switches, etc) should always come from the 3v3 pin, and digital output should be fed through a logic level converter. 
