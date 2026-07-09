# Servo Tester

Open-source hardware servo tester built with an ATtiny85 microcontroller. Designed in Altium Designer.

## Features

- **3 modes**, cycled with a single push button:
  - **Auto Sweep** – automatically sweeps the servo back and forth.
  - **Trim / Neutral** – outputs a fixed center (1500 µs) pulse.
  - **Manual** – position controlled live by an onboard potentiometer.
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

## Opening the project

Requires [Altium Designer](https://www.altium.com/altium-designer). Open `Servo_Tester.PrjPcb` — the schematic and PCB are self-contained, no external libraries needed.

## Manufacturing

Unzip `Project Outputs for Servo_Tester.zip` and upload its contents directly to your PCB fab house (e.g. JLCPCB).

## Programming

Flash the ATtiny85 through the 6-pin ISP header using a compatible programmer (e.g. USBasp, Arduino as ISP).

## License

MIT — see [LICENSE](LICENSE).
