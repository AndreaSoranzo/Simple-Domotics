#ifndef WelcomeStatus_H
#define WelcomeStatus_H

#include <QList>

#include "../../Utils/RandomGenerator.h"

class WelcomeStatus {
   private:
    static const QList<QString> status;
    WelcomeStatus();

   public:
    static const QString& GetStatus();
};

#endif  // !WelcomeStatus_H
