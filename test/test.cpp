#include <iostream>

#include "Model/NotificationSystem/NotificationCreator.h"
#include "Model/Managers/SaveLoadManager.h"
#include "Model/Managers/SensorManager.h"
#include "Model/Sensors/Distributions/ExponentialDistribution.h"
#include "Model/Sensors/Distributions/NormalDistribuition.h"
#include "Model/Sensors/SmokeSensor.h"
#include "Model/Sensors/SolarSensor.h"
#include "Model/Sensors/TemperatureSensor.h"
#include "Model/Sensors/WindSensor.h"
#include "Model/User/UserData.h"
#include "Model/User/UserDataLoader.h"
#include "Utils/RandomGenerator.h"

int main() {
    UserData d("GianlucaVacchi", "gianlucavacchi@bro.com", ColorScheme::BoringTan);
    if (!SaveUser(d, "../user.qam")) {
        std::cout << "Non ho salvato" << std::endl;
    }
    UserData d1;
    try {
        d1 = LoadUser("../user.qam");
        std::cout << d1.GetName() << std::endl;
        std::cout << d1.GetMail() << std::endl;
        std::cout << d1.GetScheme() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    SensorManager cm;
    //NotificationManager nm;
    SaveLoadManager slm;

    AbstractSensor* s = new SmokeSensor("sDA", "sd", 200, "Sd");
    AbstractSensor* sw = new WindSensor("no", "no", "no");
    AbstractSensor* s1 = new SmokeSensor("sda", "sd", 43, "Sd");
    AbstractSensor* s2 = new SolarSensor("sdb", "sd", "A1","sd");
    AbstractSensor* s3 = new TemperatureSensor("sdu", "sd", "Sd", 4, 53);

    s->SetDistribution(new ExponentialDistribution(100, 0.2));
    sw->SetDistribution(new NormalDistribuition(100, 50, 3));
    s1->SetDistribution(new NormalDistribuition(100, 50, 3));
    s2->SetDistribution(new NormalDistribuition(100, 50, 3));
    s3->SetDistribution(new NormalDistribuition(100, 50, 3));

    if (cm.AddSensor(s) != 0) {
    } else {
        std::cout << "quam" << std::endl;
    }
    if (cm.AddSensor(s1) != 0) {
    } else {
        std::cout << "quam" << std::endl;
    }
    if (cm.AddSensor(s2) != 0) {
    } else {
        std::cout << "quam" << std::endl;
    }
    if (cm.AddSensor(s3) != 0) {
    } else {
        std::cout << "quam" << std::endl;
    }
    if (cm.AddSensor(sw) != 0) {
    } else {
        std::cout << "quam" << std::endl;
    }

    // s->Start();

    std::vector<AbstractSensor*> tot;
    // slm.Save(cm.GetAll(), "../save.json");
    std::cout << AbstractSensor::products << std::endl;

    try {
        tot = slm.Load("../save.json");
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << tot.size() << std::endl;
    for (size_t i = 0; i < tot.size(); i++) {
        std::cout << tot[i]->GetInfo().name << std::endl;
    }

    cm.Inizialize(tot);
    std::cout << AbstractSensor::products << std::endl;

    std::cout << RandomGenerator<long double>::Generate(3.3, 3.6) << std::endl;

    tot = cm.GetAll();

    for (size_t i = 0; i < cm.GetSize(); i++) {
        std::cout << tot[i]->GetSensorId() << std::endl;
    }

    std::cout << "/////////////////////////////////////////////////////" << std::endl;

    // cm.RemoveSensor("sda");
    tot = cm.GetAll();

    for (size_t i = 0; i < cm.GetSize(); i++) {
        std::cout << tot[i]->GetInfo().name << std::endl;
    }

    // AlertNotificationVisitor alv(nm);
    // std::cout << s->GetDescription() << std::endl;
    //  s->accept(alv);


    std::cout << "/////////////////////////////////////////////////////" << std::endl;

    Query q("a", {}, false);
    QueryResults qr = cm.Search(q);
    std::cout << "Results : " << qr.ToSensorId().size() << std::endl;
    for (size_t i = 0; i < qr.ToSensorId().size(); i++) {
        std::cout << qr.ToSensorId()[i] << std::endl;
    }
}
