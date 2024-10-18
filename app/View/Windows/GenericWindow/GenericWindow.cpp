#include "GenericWindow.h"

GenericWindow::GenericWindow(const QString& headerText,QWidget* parent) : AbstractWindow(parent), header(headerText) {
}

void GenericWindow::Notify(const std::string& name, const std::string&, int) {
    header.UpdateUser(QString::fromStdString(name));
}

Header* GenericWindow::GetHeader() {
    return &header;
}
