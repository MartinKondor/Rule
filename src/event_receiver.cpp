#include "event_receiver.hpp"

#include <iostream>


extern InputHolder INPUT;


EventReceiver::EventReceiver(SAppContext& context)
{
    this->context = &context;
}

EventReceiver::~EventReceiver() {}

bool EventReceiver::OnEvent(const irr::SEvent& event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    {
        // If the key is pressed, it sets the state to true, else if it is released, it will be set to false.
        INPUT.keyState[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }

    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
    {
        INPUT.mouseInput = event.MouseInput;
        // std::cout << event.MouseInput.X << ", " << event.MouseInput.Y << ", Wheel:" << event.MouseInput.Wheel << std::endl;
    }

    return false;
}
