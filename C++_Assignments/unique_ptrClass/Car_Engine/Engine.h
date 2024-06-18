#ifndef ENGINE_H
#define ENGINE_H

    class Engine
    {
    private:
        
    public:
        virtual void Start()=0;
        virtual void Stop()=0;
        
        virtual ~Engine()=default;
    };
    

    

#endif