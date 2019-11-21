#ifndef EVENT_RECEIVER_HPP_INCLUDED
#define EVENT_RECEIVER_HPP_INCLUDED

#include <irrlicht.h>
#include "input_holder.hpp"


struct SAppContext
{
    irr::IrrlichtDevice* device;
};


class EventReceiver : public irr::IEventReceiver
{
public:
    SAppContext* context;

    EventReceiver(SAppContext& context);
    ~EventReceiver();
    virtual bool OnEvent(const irr::SEvent& event);
};

#endif // EVENT_RECEIVER_HPP_INCLUDED
