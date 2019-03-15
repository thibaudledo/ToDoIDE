#ifndef OBSERVERINTERFACE_H
#define OBSERVERINTERFACE_H

#include <QObject>

class ObserverInterface
{
public:
    virtual ~ObserverInterface() = 0;
    virtual void update() = 0;
};

#endif // OBSERVERINTERFACE_H
