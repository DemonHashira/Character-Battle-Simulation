#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cstring>
#include "../JSON/json.hpp"
#include "../Headers/Character.hpp"
#include "../Headers/Antagonist.hpp"
#include "../Headers/Protagonist.hpp"
#include "../Headers/DemonSlayer.hpp"
#include "../Headers/Sorcerer.hpp"
#include "../Headers/SoulRipper.hpp"
#include "../Headers/CursedSpirit.hpp"
#include "../Headers/Hollow.hpp"
#include "../Headers/Demon.hpp"

// Driver program

// Function for creating characters
std::unique_ptr<Character> createCharacter() {
    std::string type, name, specialAbility;
    int strength, constitution, dexterity, intelligence, wisdom, charisma;
    int extraAttribute1, extraAttribute2, extraAttribute3;
    
    std::cout << "Enter character type: Sorcerer/DemonSlayer/SoulRipper/CursedSpirit/Hollow/Demon ";
    std::cin >> type;
    
    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws, name);
    
    std::cout << "Enter special ability name: ";
    std::getline(std::cin, specialAbility);
    
    std::cout << "Enter strength: ";
    std::cin >> strength;
    
    std::cout << "Enter constitution: ";
    std::cin >> constitution;
    
    std::cout << "Enter dexterity: ";
    std::cin >> dexterity;
    
    std::cout << "Enter intelligence: ";
    std::cin >> intelligence;
    
    std::cout << "Enter wisdom: ";
    std::cin >> wisdom;
    
    std::cout << "Enter charisma: ";
    std::cin >> charisma;
    
    if (type == "Sorcerer") {
        std::cout << "Enter holy aura: ";
        std::cin >> extraAttribute1;
        std::cout << "Enter reputation: ";
        std::cin >> extraAttribute2;
        std::cout << "Enter innate technique: ";
        std::cin >> extraAttribute3;
        return std::make_unique<Sorcerer>(name, specialAbility, strength, constitution, dexterity, intelligence, wisdom, charisma, extraAttribute1, extraAttribute2, extraAttribute3);
    } else if (type == "DemonSlayer") {
        std::cout << "Enter holy aura: ";
        std::cin >> extraAttribute1;
        std::cout << "Enter reputation: ";
        std::cin >> extraAttribute2;
        std::cout << "Enter demon slayer mark: ";
        std::cin >> extraAttribute3;
        return std::make_unique<DemonSlayer>(name, specialAbility, strength, constitution, dexterity, intelligence, wisdom, charisma, extraAttribute1, extraAttribute2, extraAttribute3);
    } else if (type == "SoulRipper") {
        std::cout << "Enter holy aura: ";
        std::cin >> extraAttribute1;
        std::cout << "Enter reputation: ";
        std::cin >> extraAttribute2;
        std::cout << "Enter spiritual power: ";
        std::cin >> extraAttribute3;
        return std::make_unique<SoulRipper>(name, specialAbility, strength, constitution, dexterity, intelligence, wisdom, charisma, extraAttribute1, extraAttribute2, extraAttribute3);
    } else if (type == "CursedSpirit") {
        std::cout << "Enter dark aura: ";
        std::cin >> extraAttribute1;
        std::cout << "Enter fear: ";
        std::cin >> extraAttribute2;
        std::cout << "Enter cursed energy: ";
        std::cin >> extraAttribute3;
        return std::make_unique<CursedSpirit>(name, specialAbility, strength, constitution, dexterity, intelligence, wisdom, charisma, extraAttribute1, extraAttribute2, extraAttribute3);
    } else if (type == "Hollow") {
        std::cout << "Enter dark aura: ";
        std::cin >> extraAttribute1;
        std::cout << "Enter fear: ";
        std::cin >> extraAttribute2;
        std::cout << "Enter hollow flash: ";
        std::cin >> extraAttribute3;
        return std::make_unique<Hollow>(name, specialAbility, strength, constitution, dexterity, intelligence, wisdom, charisma, extraAttribute1, extraAttribute2, extraAttribute3);
    } else if (type == "Demon") {
        std::cout << "Enter dark aura: ";
        std::cin >> extraAttribute1;
        std::cout << "Enter fear: ";
        std::cin >> extraAttribute2;
        std::cout << "Enter blood demon art: ";
        std::cin >> extraAttribute3;
        return std::make_unique<Demon>(name, specialAbility, strength, constitution, dexterity, intelligence, wisdom, charisma, extraAttribute1, extraAttribute2, extraAttribute3);
    }
    return nullptr;
}


// QuickSort algorithm for sorting the vector based on DPS
void quickSort(std::vector<std::unique_ptr<Character>>& arr, int low, int high) {
    if (low < high) {
        // Partitioning the array
        double pivot = arr[high]->DPS();
        int i = low - 1;
        for (int j = low; j < high ; j++) {
            if (arr[j]->DPS() >= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int partitioningIndex = i + 1;
        
        // Sorting the two partitions
        quickSort(arr, low, partitioningIndex - 1);
        quickSort(arr, partitioningIndex+ 1, high);
        
    }
}

// Function for calling the Quick Sort
void sortCharactersByDPS(std::vector<std::unique_ptr<Character>>& characters) {
    quickSort(characters, 0, characters.size() - 1.0);
}

// Function for calling the createCharacter function
void createCharacterCall(std::vector<std::unique_ptr<Character>>& characters) {
    char addMore = 'y';
    
    while (tolower(addMore) == 'y') {
        auto newCharacter = createCharacter();
        if (newCharacter) {
            characters.push_back(std::move(newCharacter));
        }
        
        std::cout << std::endl;
        std::cout << "Do you want to add more characters? (y/n): ";
        std::cin >> addMore;
        std::cout << std::endl;
    }
}

// Function for reading the JSON file
std::vector<std::unique_ptr<Character>> readCharactersJSON(const std::string& filename) {
    // Reading the JSON file while checking if any errors occur and printing their result
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file" << std::endl;
        std::cerr << "Error code: " << strerror(errno) << std::endl;
        throw std::runtime_error("File could not be opened");
    }
    
    nlohmann::json jsonCharacters;
    try {
        file >> jsonCharacters;
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        throw;
    }
    
    // Filling the vector with the information from the JSON file
    std::vector<std::unique_ptr<Character>> characters;
    for (auto& jsonCharacter : jsonCharacters) {
        try {
            std::string type = jsonCharacter.at("type").get<std::string>();
            if (type == "Protagonist") {
                characters.push_back(std::make_unique<Protagonist>(
                    jsonCharacter.at("name").get<std::string>(),
                    jsonCharacter.at("specialAbility").get<std::string>(),
                    jsonCharacter.at("strength").get<int>(),
                    jsonCharacter.at("constitution").get<int>(),
                    jsonCharacter.at("dexterity").get<int>(),
                    jsonCharacter.at("intelligence").get<int>(),
                    jsonCharacter.at("wisdom").get<int>(),
                    jsonCharacter.at("charisma").get<int>(),
                    jsonCharacter.at("holyAura").get<int>(),
                    jsonCharacter.at("reputation").get<int>()
                ));
            } else if (type == "Antagonist") {
                characters.push_back(std::make_unique<Antagonist>(
                    jsonCharacter.at("name").get<std::string>(),
                    jsonCharacter.at("specialAbility").get<std::string>(),
                    jsonCharacter.at("strength").get<int>(),
                    jsonCharacter.at("constitution").get<int>(),
                    jsonCharacter.at("dexterity").get<int>(),
                    jsonCharacter.at("intelligence").get<int>(),
                    jsonCharacter.at("wisdom").get<int>(),
                    jsonCharacter.at("charisma").get<int>(),
                    jsonCharacter.at("darkAura").get<int>(),
                    jsonCharacter.at("fear").get<int>()
                ));
            } else if (type == "Sorcerer") {
                characters.push_back(std::make_unique<Sorcerer>(
                    jsonCharacter.at("name").get<std::string>(),
                    jsonCharacter.at("specialAbility").get<std::string>(),
                    jsonCharacter.at("strength").get<int>(),
                    jsonCharacter.at("constitution").get<int>(),
                    jsonCharacter.at("dexterity").get<int>(),
                    jsonCharacter.at("intelligence").get<int>(),
                    jsonCharacter.at("wisdom").get<int>(),
                    jsonCharacter.at("charisma").get<int>(),
                    jsonCharacter.at("holyAura").get<int>(),
                    jsonCharacter.at("reputation").get<int>(),
                    jsonCharacter.at("innateTechnique").get<int>()
                ));
            } else if (type == "DemonSlayer") {
                characters.push_back(std::make_unique<DemonSlayer>(
                    jsonCharacter.at("name").get<std::string>(),
                    jsonCharacter.at("specialAbility").get<std::string>(),
                    jsonCharacter.at("strength").get<int>(),
                    jsonCharacter.at("constitution").get<int>(),
                    jsonCharacter.at("dexterity").get<int>(),
                    jsonCharacter.at("intelligence").get<int>(),
                    jsonCharacter.at("wisdom").get<int>(),
                    jsonCharacter.at("charisma").get<int>(),
                    jsonCharacter.at("holyAura").get<int>(),
                    jsonCharacter.at("reputation").get<int>(),
                    jsonCharacter.at("demonSlayerMark").get<int>()
                ));
            } else if (type == "SoulRipper") {
                characters.push_back(std::make_unique<SoulRipper>(
                    jsonCharacter.at("name").get<std::string>(),
                    jsonCharacter.at("specialAbility").get<std::string>(),
                    jsonCharacter.at("strength").get<int>(),
                    jsonCharacter.at("constitution").get<int>(),
                    jsonCharacter.at("dexterity").get<int>(),
                    jsonCharacter.at("intelligence").get<int>(),
                    jsonCharacter.at("wisdom").get<int>(),
                    jsonCharacter.at("charisma").get<int>(),
                    jsonCharacter.at("holyAura").get<int>(),
                    jsonCharacter.at("reputation").get<int>(),
                    jsonCharacter.at("spiritualPower").get<int>()
                ));
            } else if (type == "CursedSpirit") {
                characters.push_back(std::make_unique<CursedSpirit>(
                    jsonCharacter.at("name").get<std::string>(),
                    jsonCharacter.at("specialAbility").get<std::string>(),
                    jsonCharacter.at("strength").get<int>(),
                    jsonCharacter.at("constitution").get<int>(),
                    jsonCharacter.at("dexterity").get<int>(),
                    jsonCharacter.at("intelligence").get<int>(),
                    jsonCharacter.at("wisdom").get<int>(),
                    jsonCharacter.at("charisma").get<int>(),
                    jsonCharacter.at("darkAura").get<int>(),
                    jsonCharacter.at("fear").get<int>(),
                    jsonCharacter.at("cursedEnergy").get<int>()
                ));
            } else if (type == "Demon") {
                characters.push_back(std::make_unique<Demon>(
                    jsonCharacter.at("name").get<std::string>(),
                    jsonCharacter.at("specialAbility").get<std::string>(),
                    jsonCharacter.at("strength").get<int>(),
                    jsonCharacter.at("constitution").get<int>(),
                    jsonCharacter.at("dexterity").get<int>(),
                    jsonCharacter.at("intelligence").get<int>(),
                    jsonCharacter.at("wisdom").get<int>(),
                    jsonCharacter.at("charisma").get<int>(),
                    jsonCharacter.at("darkAura").get<int>(),
                    jsonCharacter.at("fear").get<int>(),
                    jsonCharacter.at("bloodDemonArt").get<int>()
                ));
            } else if (type == "Hollow") {
                characters.push_back(std::make_unique<Hollow>(
                    jsonCharacter.at("name").get<std::string>(),
                    jsonCharacter.at("specialAbility").get<std::string>(),
                    jsonCharacter.at("strength").get<int>(),
                    jsonCharacter.at("constitution").get<int>(),
                    jsonCharacter.at("dexterity").get<int>(),
                    jsonCharacter.at("intelligence").get<int>(),
                    jsonCharacter.at("wisdom").get<int>(),
                    jsonCharacter.at("charisma").get<int>(),
                    jsonCharacter.at("darkAura").get<int>(),
                    jsonCharacter.at("fear").get<int>(),
                    jsonCharacter.at("hollowFlash").get<int>()
                ));
            } else {
                std::cerr << "Uknown character type: " << type << std::endl;
            }
            
        } catch (const nlohmann::json::exception& e) {
            std::cerr << "Error processing character: " << e.what() << std::endl;
            continue;
        }
    }
    return characters;
}

int main() {
    // Creating the vector
    std::vector<std::unique_ptr<Character>> characters;
    
    // Asking the user if he wants to create characters
    std::cout << "Welcome to the Anime Character Simulation Battle Arena!" << std::endl;
    char choice;
    std::cout << "Do you want to create a character or use the existing ones? (y/n) ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
    
    if (tolower(choice) == 'y') {
        createCharacterCall(characters);
        std::cout << std::endl;
    }
    
    // Load characters from JSON file if the user doesn't want to create their own
    // or in addition to the created characters
    try {
        auto charactersFromJson = readCharactersJSON("../JSON/characters.json");
        for (auto& character : charactersFromJson) {
            characters.push_back(std::move(character));
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occured while reading characters from JSON: " << e.what() << std::endl;
        if (characters.empty()) {
            return 1;
        }
    }
    
    // Sorting the array and printing the leaderboard in descending order
    sortCharactersByDPS(characters);
    std::cout << "\t\t\t\tLEADERBOARD" << std::endl;
    std::cout << std::endl;
    int count = 1;
    for (const auto& character : characters) {
        std::cout << count << ". " << character->GetName() << ", DPS: " << character->DPS() << ", Special Ability: " << character->SpecialAbilityName() << std::endl;
        std::cout << std::endl;
        count++;
    }
    return 0;
}
