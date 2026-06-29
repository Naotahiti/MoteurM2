#include "InputManager.h"
#include <Windows.h>

InputManager& InputManager::Get()
{
    static InputManager instance;
    return instance;
}

void InputManager::BindKey(InputAction action, int key)
{
    keyBindings[action] = key;
}

bool InputManager::IsActionPressed(InputAction action)
{
    if (keyBindings.find(action) == keyBindings.end())
        return false;

    int key = keyBindings[action];
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}