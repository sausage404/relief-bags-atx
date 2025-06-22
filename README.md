# Line Following Delivery Robot Control System
Add data board ATX2 from https://github.com/INEXdev/ArduinoAVR/raw/main/package_inex_avr_index.json

A control system for an ATX2-based line following robot with package delivery capabilities.

## Features

- Line following using 4 sensors (2 front, 2 back)
- Package delivery mechanism using servo motor
- Smooth movement with acceleration/deceleration
- Precise turning controls (90° and 180°)
- Sensor-based position adjustment

## Hardware Requirements

- ATX2 controller board
- 2 DC motors (left and right)
- 4 line detection sensors
- 1 servo motor for package delivery
- Chassis with package holding mechanism

## Configuration Constants

### Motor Settings
- Left/Right bias adjustments for motor calibration
- Turn power: 50% of maximum
- Movement power: 67% of maximum
- Line following check power: 42% of maximum

### Sensor Settings
- Black detection threshold: 500 for all sensors
- Line unit delay: 220ms
- Turn delays: 300ms (90°), 490ms (180°)

## Main Functions

### Movement Control
- `mf()`: Forward movement with acceleration
- `mb()`: Backward movement with acceleration
- `tl()`: Left turn (90° or 180°)
- `tr()`: Right turn (90° or 180°)
- `smf()`: Slow forward movement for rough surfaces

### Line Following
- `mfub()`: Forward until black line detection
- `mbub()`: Backward until black line detection
- `dp()`: Package delivery sequence

### Utilities
- `testSensors()`: Display sensor readings
- `adjustServo()`: Servo position adjustment

## Setup Instructions

1. Configure sensor thresholds based on lighting conditions
2. Adjust motor bias values for straight movement
3. Calibrate turn delays for precise 90° and 180° turns
4. Test and adjust servo angles for reliable package delivery

## Troubleshooting

- If robot veers: Adjust LEFT_BIAS and RIGHT_BIAS
- If turns are inaccurate: Modify turn delay constants
- If line detection fails: Check sensor thresholds
- If delivery is unreliable: Calibrate servo angles

## License

This software is released under the [GNU General Public License v3](https://github.com/sausage404/mbext-project/blob/main/LICENSE).


If you encounter any problems or have suggestions, please file an issue on the GitHub repository.
