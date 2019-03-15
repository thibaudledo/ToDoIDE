#ifndef __COMPONENT_INTERFACE_H
#define __COMPONENT_INTERFACE_H


#include <list>


class ComponentInterface {
    public:
        int addComponent(ComponentInterface &componentInterface);
        int removeComponent(ComponentInterface &componentInterface);

        virtual void update() = 0;

    private:
        std::list<ComponentInterface *> m_componentList;
};

#endif
