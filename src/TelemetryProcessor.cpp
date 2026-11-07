/**
 * @file TelemetryProcessor.cpp
 * @author COC NASA Team (Yutian Cao & Contributors)
 * @brief Core physics and telemetry parsing engine for aerospace payloads.
 * @version 1.0.2
 * @date 2026
 * 
 * Distributed under the MIT License.
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

class TelemetryProcessor {
private:
    // Standard atmospheric constants
    const double GRAVITY = 9.80665; // m/s^2
    const double MOLAR_MASS_AIR = 0.0289644; // kg/mol
    const double UNIVERSAL_GAS_CONSTANT = 8.3144598; // J/(mol·K)
    const double SEA_LEVEL_PRESSURE = 101325.0; // Pascals
    const double SEA_LEVEL_TEMP = 288.15; // Kelvin

    struct SensorData {
        double timestamp;
        double pressure_pa;
        double temperature_c;
        double humidity_percent;
    };

    std::vector<SensorData> data_log;

public:
    TelemetryProcessor() {
        std::cout << "[SYSTEM] Initializing COC Payload Telemetry Core..." << std::endl;
    }

    /**
     * @brief Parses incoming raw data stream from the payload sensors
     */
    void ingestData(double t, double p, double temp, double hum) {
        if (p < 0 || temp < -273.15) {
            throw std::invalid_argument("[ERROR] Invalid sensor readings detected.");
        }
        data_log.push_back({t, p, temp, hum});
    }

    /**
     * @brief Calculates the payload's current altitude using the Barometric Formula
     * Uses multivariable state parameters for precise atmospheric modeling.
     */
    double calculateAltitude(const SensorData& data) {
        // Convert Celsius to Kelvin
        double temp_k = data.temperature_c + 273.15;
        
        // Barometric formula derived from differential equations of fluid statics
        // h = (R * T / (g * M)) * ln(P0 / P)
        double altitude = (UNIVERSAL_GAS_CONSTANT * temp_k) / (GRAVITY * MOLAR_MASS_AIR) 
                          * std::log(SEA_LEVEL_PRESSURE / data.pressure_pa);
                          
        return altitude;
    }

    /**
     * @brief Runs batch physics analysis on all collected data telemetry
     */
    void runDiagnostics() {
        std::cout << "\n--- Commencing Flight Physics Diagnostics ---" << std::endl;
        for (const auto& entry : data_log) {
            double alt = calculateAltitude(entry);
            std::cout << "T+" << entry.timestamp << "s | "
                      << "Pressure: " << entry.pressure_pa << " Pa | "
                      << "Est. Altitude: " << alt << " meters" << std::endl;
        }
        std::cout << "--- Diagnostics Complete ---\n" << std::endl;
    }
};

// Example usage / Test routine
int main() {
    try {
        TelemetryProcessor payloadEngine;
        
        // Simulating ascent data points
        payloadEngine.ingestData(10.5, 95000.0, 14.2, 45.0);
        payloadEngine.ingestData(120.0, 70000.0, 2.5, 30.0);
        payloadEngine.ingestData(450.0, 30000.0, -25.0, 10.0);
        
        payloadEngine.runDiagnostics();
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
