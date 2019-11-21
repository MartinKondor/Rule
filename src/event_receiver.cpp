#include "event_receiver.hpp"

#include <iostream>


extern Config CONFIG;


EventReceiver::EventReceiver(SAppContext& context)
{
    this->context = &context;
}

EventReceiver::~EventReceiver() {}

bool EventReceiver::OnEvent(const irr::SEvent& event)
{
    switch (event.EventType)
   {
      case irr::EET_KEY_INPUT_EVENT:
      {
         // If the key is pressed, it sets the state to true, else if it is released, it will be set to false.
         CONFIG.keyState[event.KeyInput.Key] = event.KeyInput.PressedDown;
      }
   }
    return false;
}
