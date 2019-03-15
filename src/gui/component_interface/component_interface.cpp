#include "component_interface.h"


int ComponentInterface::addComponent(ComponentInterface &componentInterface) {
    m_componentList.push_back(&componentInterface);
}


int ComponentInterface::removeComponent(ComponentInterface &componentInterface) {
    m_componentList.remove(&componentInterface);
}
