#pragma once
#include <unordered_map>
#include "InputAction.h"

    class InputManager
    {
    public:

        static InputManager& Get();

        void BindKey(InputAction action, int key);
        bool IsActionPressed(InputAction action);

    private:

        std::unordered_map<InputAction, int> keyBindings;
    };


