#ifndef SoulRipper_hpp
#define SoulRipper_hpp

#include "../Headers/Protagonist.hpp"

// Header file for the Soul Ripper class
// publicly inheriting Protagonist
class SoulRipper : public Protagonist {
protected:
    // Additional data field specific to Soul Ripper
    int spiritualPower;
    
public:
    // Constructor with inherited values from Character and Protagonist
    SoulRipper(const std::string& name, const std::string& specialAbility, int strength, int constitution,
                int dexterity, int intelligence, int wisdom, int charisma, int holyAura,
                int reputation, int spiritualPower);
    
    // Getter for the data field
    int GetSpiritualPower() const;
    
    // Setter for the data field
    void SetSpiritualPower(int spiritualPower);
    
    // Concrete implementations for the pure virtual functions
    int DPS() override;
    double SpecialAbility() override;
    std::string SpecialAbilityName() override;
};

#endif /* SoulRipper_hpp */
