#ifndef Hollow_hpp
#define Hollow_hpp

#include "../Headers/Antagonist.hpp"

// Header file for the Hollow class
// publicly inheriting Antagonist
class Hollow : public Antagonist {
protected:
    // Additional data field specific to Hollow
    int hollowFlash;

public:
    // Constructor with inherited values from Antagonist
    Hollow(const std::string& name, const std::string& specialAbility, int strength, int constitution,
           int dexterity, int intelligence, int wisdom, int charisma, int darkAura,
           int fear, int hollowFlash);

    // Getter for the data field
    int GetHollowFlash() const;

    // Setter for the data field
    void SetHollowFlash(int hollowFlash);

    // Concrete implementation for the pure virtual functions
    int DPS() override;
    double SpecialAbility() override;
    std::string SpecialAbilityName() override;
};

#endif /* Hollow_hpp */
