#ifndef OBSERVERINTERFACE_H
#define OBSERVERINTERFACE_H

#include <QObject>

#include <QDebug>

class ObserverInterface
{
public:
    ObserverInterface();
    virtual ~ObserverInterface();
    virtual void updateData() = 0;
};

#endif // OBSERVERINTERFACE_H
