#ifndef Sorcerer_hpp
#define Sorcerer_hpp

#include "../Headers/Protagonist.hpp"

// Header file for the Sorcerer class
// publicly inheriting Protagonist
class Sorcerer : public Protagonist {
protected:
    // Additional data field specific to Sorcerer
    int innateTechnique;

public:
    // Constructor with inherited values from Protagonist
    Sorcerer(const std::string& name, const std::string& specialAbility, int strength, int constitution,
             int dexterity, int intelligence, int wisdom, int charisma, int holyAura,
             int reputation, int innateTechnique);

    // Getter for the data field
    int GetInnateTechnique() const;

    // Setter for the data field
    void SetInnateTechnique(int innateTechnique);

    // Concrete implementations for the pure virtual functions
    int DPS() override;
    double SpecialAbility() override;
    std::string SpecialAbilityName() override;
};

#endif /* Sorcerer_hpp */
