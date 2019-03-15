#ifndef __CONTROLLER_H
#define __CONTROLLER_H

class ControllerInterface {
    public:
        virtual ~ControllerInterface();

        // File management
        virtual int newFile() = 0;
        virtual int openFile() = 0;
        virtual int close() = 0;
        virtual int saveFile() = 0;
        
        // File operations
        virtual int writeFile() = 0;
        virtual int readFile() = 0;
};

#endif
