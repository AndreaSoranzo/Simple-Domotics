#ifndef TypeEnum_H
#define TypeEnum_H

enum class SensorType {  // "None" is repeated => enum classes
    Humidity,
    Wind,
    Smoke,
    Ground,
    Solar,
    Temperature,
    None
};

enum class DistributionType {
    Exponential,
    Normal,
    Random,
    Uniform,
    None
};

enum class SolarCertification {
    A1,
    A2,
    B1,
    B2,
    Unclassified
};

#endif  // !TypeEnum_H