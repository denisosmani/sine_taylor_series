# Sine Function Implementation using Taylor Series

This project demonstrates the implementation of the sine function using the Taylor series approximation. The code is written in C for the 8051 MCU and includes interaction with a keyboard and LCD screen. The hardware design for the calculator is simulated using Proteus v8.11 software.

## Features

- Calculates the sine of an angle in radians using a Taylor series approximation.
- User interaction through a keyboard and LCD screen.
- ANS button displays the calculated value.
- ON/C button clears the calculated value.

## Proteus

![Proteus Sine Calculator](https://user-images.githubusercontent.com/76630405/231287421-5cc6ccb4-8e9f-42d9-b29d-3f012d09563f.png)

## Taylor Series Formula

![Taylor Series Formula](https://github.com/denisosmani/sine_taylor_series/assets/76630405/3bb30c6f-813b-406c-87a7-fcf903f36715.png)

The sine function is approximated using the Taylor series exclusively within the interval of the first period (0 to 2π). Subsequent arguments belonging to different periods are transformed through calculations within the first period, and then the sin(x) result is computed.

![Taylor Series Visualization](https://github.com/denisosmani/sine_taylor_series/assets/76630405/4cfb8f06-9013-4bbf-b05e-eef771288530.png)



