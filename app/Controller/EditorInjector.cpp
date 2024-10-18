#include "EditorInjector.h"

#include "../Model/Sensors/GroundSensor.h"
#include "../Model/Sensors/HumiditySensor.h"
#include "../Model/Sensors/SmokeSensor.h"
#include "../Model/Sensors/SolarSensor.h"
#include "../Model/Sensors/TemperatureSensor.h"
#include "../Model/Sensors/WindSensor.h"
#include "../View/CustomWidgets/Editors/AlertEditor.h"
#include "../View/CustomWidgets/Editors/SimpleEditor.h"
#include "../View/CustomWidgets/Editors/SolarEditor.h"
#include "../View/CustomWidgets/Editors/TemperatureEditor.h"

EditorInjector::EditorInjector(EditPanel* editPanel) : editPanel(editPanel) {
}

void EditorInjector::visit(HumiditySensor& sens) {
    SimpleEditor* editor = new SimpleEditor(
        QString::fromStdString(sens.GetInfo().name),
        QString::fromStdString(sens.GetInfo().brand),
        QString::fromStdString(sens.GetInfo().moreInfo));
    editPanel->SetEditor(editor);

    // connects
    connect(editPanel, &EditPanel::OnApply, this, [&, editor]() -> void {
        if (!editor->IsChanged()) {
            return;
        }
        sens.GetInfo().name = editor->GetName().toStdString();
        sens.GetInfo().brand = editor->GetBrand().toStdString();
        sens.GetInfo().moreInfo = editor->GetInfo().toStdString();
        emit editPanel->OnEditComplete(sens.GetSensorId());
        editPanel->disconnect(this);
    });
}

void EditorInjector::visit(WindSensor& sens) {
    SimpleEditor* editor = new SimpleEditor(
        QString::fromStdString(sens.GetInfo().name),
        QString::fromStdString(sens.GetInfo().brand),
        QString::fromStdString(sens.GetInfo().moreInfo));
    editPanel->SetEditor(editor);

    connect(editPanel, &EditPanel::OnApply, this, [&, editor]() -> void {
        if (!editor->IsChanged()) {
            return;
        }
        sens.GetInfo().name = editor->GetName().toStdString();
        sens.GetInfo().brand = editor->GetBrand().toStdString();
        sens.GetInfo().moreInfo = editor->GetInfo().toStdString();
        emit editPanel->OnEditComplete(sens.GetSensorId());
        editPanel->disconnect(this);
    });
}

void EditorInjector::visit(TemperatureSensor& sens) {
    TemperatureEditor* editor = new TemperatureEditor(
        QString::fromStdString(sens.GetInfo().name),
        QString::fromStdString(sens.GetInfo().brand),
        QString::fromStdString(sens.GetInfo().moreInfo),
        sens.GetBatteries());
    editPanel->SetEditor(editor);

    connect(editPanel, &EditPanel::OnApply, this, [&, editor]() -> void {
        if (!editor->IsChanged()) {
            return;
        }
        sens.GetInfo().name = editor->GetName().toStdString();
        sens.GetInfo().brand = editor->GetBrand().toStdString();
        sens.GetInfo().moreInfo = editor->GetInfo().toStdString();
        sens.SetBatteries(editor->GetBatteries());
        emit editPanel->OnEditComplete(sens.GetSensorId());
        editPanel->disconnect(this);
    });
}

void EditorInjector::visit(SolarSensor& sens) {
    SolarEditor* editor = new SolarEditor(
        QString::fromStdString(sens.GetInfo().name),
        QString::fromStdString(sens.GetInfo().brand),
        QString::fromStdString(sens.GetInfo().moreInfo),
        QString::fromStdString(sens.GetCertification()));
    editPanel->SetEditor(editor);

    connect(editPanel, &EditPanel::OnApply, this, [&, editor]() -> void {
        if (!editor->IsChanged()) {
            return;
        }
        sens.GetInfo().name = editor->GetName().toStdString();
        sens.GetInfo().brand = editor->GetBrand().toStdString();
        sens.GetInfo().moreInfo = editor->GetInfo().toStdString();
        sens.SetCertificaion(editor->GetCertificaion().toStdString());
        emit editPanel->OnEditComplete(sens.GetSensorId());
        editPanel->disconnect(this);
    });
}

void EditorInjector::visit(GroundSensor& sens) {
    AlertEditor* editor = new AlertEditor(
        QString::fromStdString(sens.GetInfo().name),
        QString::fromStdString(sens.GetInfo().brand),
        QString::fromStdString(sens.GetInfo().moreInfo),
        sens.GetDangerLV());
    editPanel->SetEditor(editor);

    connect(editPanel, &EditPanel::OnApply, this, [&, editor]() -> void {
        if (!editor->IsChanged()) {
            return;
        }

        sens.GetInfo().name = editor->GetName().toStdString();
        sens.GetInfo().brand = editor->GetBrand().toStdString();
        sens.GetInfo().moreInfo = editor->GetInfo().toStdString();
        sens.SetDangerLV(editor->GetDanger());
        emit editPanel->OnEditComplete(sens.GetSensorId());
        editPanel->disconnect(this);
    });
}

void EditorInjector::visit(SmokeSensor& sens) {
    AlertEditor* editor = new AlertEditor(
        QString::fromStdString(sens.GetInfo().name),
        QString::fromStdString(sens.GetInfo().brand),
        QString::fromStdString(sens.GetInfo().moreInfo),
        sens.GetDangerLV());
    editPanel->SetEditor(editor);

    connect(editPanel, &EditPanel::OnApply, this, [&, editor]() -> void {
        if (!editor->IsChanged()) {
            return;
        }
        sens.GetInfo().name = editor->GetName().toStdString();
        sens.GetInfo().brand = editor->GetBrand().toStdString();
        sens.GetInfo().moreInfo = editor->GetInfo().toStdString();
        sens.SetDangerLV(editor->GetDanger());
        emit editPanel->OnEditComplete(sens.GetSensorId());
        editPanel->disconnect(this);
    });
}
