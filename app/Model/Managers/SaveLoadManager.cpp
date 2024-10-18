#include "SaveLoadManager.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <exception>

bool SaveLoadManager::Save(const std::vector<AbstractSensor*> sensors, const std::string& path) {
    QJsonArray jsonObjs;
    for (const AbstractSensor* sens : sensors) {
        jsonObjs.push_back(converter.ToJson(*sens));
    }
    QJsonDocument document(jsonObjs);
    QFile json_file(path.c_str());
    if (json_file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        json_file.write(document.toJson());
        json_file.close();
        return true;
    }
    return false;
}

std::vector<AbstractSensor*> SaveLoadManager::Load(const std::string& path) {
    std::vector<AbstractSensor*> sensors;
    QFile json_file(path.c_str());
    if (!json_file.open(QFile::ReadOnly)) {
        throw std::runtime_error("Cannot open file");
    }
    QByteArray data = json_file.readAll();
    json_file.close();
    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonArray json_items = document.array();

    for (const QJsonValue& value : json_items) {
        QJsonObject json_object = value.toObject();
        AbstractSensor* newSensor = converter.ToObj(json_object);
        if (!newSensor) {
            ConvertError(sensors);
            throw std::runtime_error("File not valid");
        }
        sensors.push_back(newSensor);
    }
    return sensors;
}

void SaveLoadManager::ConvertError(std::vector<AbstractSensor*>& sensors) const {
    for (AbstractSensor* var : sensors) {
        delete var;
    }
}
