#ifndef OBSERVABLEINTERFACE_H
#define OBSERVABLEINTERFACE_H

#include "observerinterface.h"

#include <QDebug>

class ObservableInterface
{
protected:
    std::list<ObserverInterface*> m_observerList;
public:
    virtual ~ObservableInterface();
    virtual void registerObserver(ObserverInterface*);
    virtual void removeObserver(ObserverInterface*);
    virtual void updateAllObserver();

};

#endif // OBSERVABLEINTERFACE_H
