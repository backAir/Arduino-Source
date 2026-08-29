/*  Braviary Height Glitch
 *
 *  From: https://github.com/PokemonAutomation/
 *
 */

#ifndef PokemonAutomation_PokemonLA_RngAdvances_H
#define PokemonAutomation_PokemonLA_RngAdvances_H

#include "NintendoSwitch/NintendoSwitch_SingleSwitchProgram.h"

namespace PokemonAutomation{
namespace NintendoSwitch{
namespace PokemonLA{


class RngAdvances_Descriptor : public SingleSwitchProgramDescriptor{
public:
    RngAdvances_Descriptor();
};


class RngAdvances : public SingleSwitchProgramInstance{
public:
    RngAdvances();

    virtual void program(SingleSwitchProgramEnvironment& env, ProControllerContext& context) override;
};





}
}
}
#endif
