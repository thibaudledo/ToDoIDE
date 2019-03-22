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
    for(ObserverInterface* o : m_observerList)
    {
        o->updateData();
    }
}
