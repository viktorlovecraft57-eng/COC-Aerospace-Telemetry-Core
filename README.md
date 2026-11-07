# COC NASA Payload - Telemetry & Physics Engine 🚀

![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)
![Build: Passing](https://img.shields.io/badge/build-passing-brightgreen.svg)
![Language: C++](https://img.shields.io/badge/Language-C++17-orange.svg)

## Overview
This repository contains the core aerospace computing infrastructure and physics simulation engine maintained by the **College of the Canyons (COC) NASA Team**. 

Designed specifically for undergraduate and community college space exploration payloads (such as HASP and Student Launch), this engine provides a lightweight, highly-optimized C++ architecture for parsing multi-sensor data streams and running real-time thermodynamic and orbital dynamics calculations.

## The Ecosystem Gap We Fill
Historically, aerospace competition codebases are either too proprietary or overly complex (requiring enterprise-grade RTOS). This open-source framework lowers the barrier to entry, allowing academic teams with limited computational resources to quickly implement reliable telemetry physics modeling.

## Key Features
- **Barometric Altitude Modeling**: Solves atmospheric fluid statics differential equations in real-time.
- **Multivariable State Parsing**: Handles pressure, temperature, humidity, and 3-axis IMU data.
- **Low Memory Footprint**: Optimized C++ execution for microcontrollers commonly used in student payloads.

## Getting Started
To compile the core processor on any Unix-like system or Windows (via MinGW):

```bash
g++ -std=c++17 src/TelemetryProcessor.cpp -o telemetry_engine
./telemetry_engine# COC-Aerospace-Telemetry-Core
Open-source telemetry processing and physics simulation engine for undergraduate aerospace payloads.
