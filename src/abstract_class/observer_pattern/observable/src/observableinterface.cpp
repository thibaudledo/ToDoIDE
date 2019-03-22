#include "observableinterface.h"

ObservableInterface::~ObservableInterface()
{
    for(auto o : m_observerList)
    {
        delete o;
    }
}

void ObservableInterface::registerObserver(ObserverInterface *o)
{
    m_observerList.push_back(o);
    qDebug() << QString::number(m_observerList.size());
}

void ObservableInterface::removeObserver(ObserverInterface *ob)
{
    for(auto o : m_observerList)
    {
        if(o == ob)
        {
            delete o;
        }
    }
}

void ObservableInterface::updateAllObserver()
{
        qDebug() << "4";
    for(ObserverInterface* o : m_observerList)
    {
        qDebug() << "5";
        o->updateData();
        qDebug() << "7";
    }
}
