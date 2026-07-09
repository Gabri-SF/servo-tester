# Servo Tester

Open-source hardware servo tester built with an ATtiny85 microcontroller. Designed in Altium Designer.

## Features

- **2 modes**, toggled with a single push button (interrupt-driven):
  - **Manual** – position controlled live by an onboard potentiometer.
  - **Auto Sweep** – automatically sweeps the servo between 0° and 180°.
- **2 status LEDs** indicating the active mode.
- **Reverse-polarity protection** via a P-channel MOSFET.
- **470 µF capacitor** for power decoupling/filtering.
- **6-pin ISP header** for programming/reprogramming the ATtiny85.
- Power input pins that can be fed from a battery/PSU or directly from an ESC's BEC.
- Servo output header(s) to connect the servo(s) under test.

## Repository contents

| File | Description |
|---|---|
| `Servo_Tester.PrjPcb` | Altium project file |
| `Servo_Tester.PrjPcbStructure` | Project structure descriptor |
| `Servo_Tester.SchDoc` | Schematic |
| `PCB_Servo_Tester.PcbDoc` | PCB layout |
| `Servo_Tester.BomDoc` | Bill of materials (Altium native format) |
| `Servo_Tester_BOM.xlsx` | Bill of materials with Digi-Key part numbers, pricing and datasheets |
| `Project Outputs for Servo_Tester.zip` | Manufacturing outputs (Gerbers, drill files, pick & place, BOM) ready to submit to a fab house such as JLCPCB |
| `firmware/servo_tester.ino` | ATtiny85 firmware (Arduino sketch) |

## Opening the project

Requires [Altium Designer](https://www.altium.com/altium-designer). Open `Servo_Tester.PrjPcb` — the schematic and PCB are self-contained, no external libraries needed.

## Manufacturing

Unzip `Project Outputs for Servo_Tester.zip` and upload its contents directly to your PCB fab house (e.g. JLCPCB).

## Programming

Flash `firmware/servo_tester.ino` onto the ATtiny85 through the 6-pin ISP header, using the Arduino IDE with the [ATTinyCore](https://github.com/SpenceKonde/ATTinyCore) board package and a compatible ISP programmer (e.g. USBasp, Arduino as ISP).

Pin mapping used by the firmware:

| ATtiny85 pin | Function |
|---|---|
| PB0 | Servo signal output |
| PB1 | Mode button (input, pull-up, pin-change interrupt) |
| PB2 | Potentiometer input (A1) |
| PB3 | Mode LED 1 |
| PB4 | Mode LED 2 |

## License

MIT — see [LICENSE](LICENSE).
