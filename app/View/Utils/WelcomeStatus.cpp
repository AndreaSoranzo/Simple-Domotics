#include "WelcomeStatus.h"

const QList<QString> WelcomeStatus::status = {
    "Welcome home, it’s raining outside...",
    "Welcome home, what a beautiful day...",
    "Birds are signing, flowers are blooming...\nIn days like this you should…",
    "Welcome home, nice to have you here...",
    "QUAM two gusti is meglio che uam...",
    "Welcome home, how you doin'...",
    "Gotta go fast with creating those sensors..."};

const QString& WelcomeStatus::GetStatus() {
    int upperLimit = status.size();
    return status[RandomGenerator<int>::Generate(0, upperLimit)];
}