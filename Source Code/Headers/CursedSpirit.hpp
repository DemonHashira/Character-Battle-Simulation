#ifndef CursedSpirit_hpp
#define CursedSpirit_hpp

#include "../Headers/Antagonist.hpp"

// Header file for the CursedSpirit class
// publicly inheriting Antagonist
class CursedSpirit : public Antagonist {
protected:
    // Additional data field specific to Cursed Spirit
    int cursedEnergy;

public:
    // Constructor with inherited values from Antagonist
    CursedSpirit(const std::string& name, const std::string& specialAbility, int strength, int constitution,
                 int dexterity, int intelligence, int wisdom, int charisma, int darkAura,
                 int fear, int cursedEnergy);

    // Getter for the data field
    int GetCursedEnergy() const;

    // Setter for the data field
    void SetCursedEnergy(int cursedEnergy);

    // Concrete implementations for the pure virtual functions
    int DPS() override;
    double SpecialAbility() override;
    std::string SpecialAbilityName() override;
};

#endif /* CursedSpirit_hpp */
