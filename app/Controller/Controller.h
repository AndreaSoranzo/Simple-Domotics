#ifndef Controller_H
#define Controller_H

#include <QObject>

#include "../Model/Model.h"
#include "../View/MainWindow.h"
#include "EditorInjector.h"
#include "InfoViewSelector.h"
#include "SensorCreator.h"

class Controller : public QObject {
    Q_OBJECT
   private:
    Model& model;
    MainWindow& view;

    SensorCreator sensorCreator;
    EditorInjector editorInjector;
    InfoViewSelector infoViewSelector;

   public:
    Controller(Model& model, MainWindow& view);

    void Init() const;

   private:
    void UpdateUserInfo(const QString& name, const QString& mail, int palette);
    void CreateSensor();
    void UpdateSensor(unsigned int idx);
    void UpdateItemSensor(unsigned int idx) const;
    void DeleteSensor(unsigned int idx);
    void SearchSensor(const QString& queryText, const QString& queryFilter, bool match) const;
    void InspectSensor(unsigned int idx);
    void StartSimulation(unsigned int idx);
    void ResetSimulation(unsigned int idx);
    void SaveSensors(const QString& path);
    void LoadSensors(const QString& path);
};

#endif  // !Controller_H