#include "deletebutton.h"

void DeleteButton::imClicked(bool)
{
    emit iChanged(this);
}
