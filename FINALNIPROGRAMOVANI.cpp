#include <iostream>
#include <string>
using namespace std;

int main() {
    int playerclasschoice;
    int maxHealth;
    int currentHealth;
    int maxMana;
    int currentMana;
    int gold;
    int level;
    int experience;
    int attack;

    cout << "Vyberte si classu:" << endl;
    cout << "1. Paladin" << endl;
    cout << "2. Lovec" << endl;
    cout << "3. Mag" << endl;
    cout << "4. Warlock" << endl;

    bool confirmed = false;
    while (!confirmed) {
        cout << "Zadejte číslo classy: ";
        cin >> playerclasschoice;

        switch (playerclasschoice) {
            case 1:
                maxHealth = 5;
                currentHealth = 5;
                maxMana = 5;
                currentMana = 5;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 3;
                break;
            case 2:
                maxHealth = 4;
                currentHealth = 4;
                maxMana = 4;
                currentMana = 4;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 4;
                break;
            case 3:
                maxHealth = 3;
                currentHealth = 3;
                maxMana = 6;
                currentMana = 6;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 2;
                break;
            case 4:
                maxHealth = 4;
                currentHealth = 4;
                maxMana = 5;
                currentMana = 5;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 3;
                break;
            default:
                cout << "Neplatná volba. Zkuste znovu." << endl;
                continue;
        }

        string className;
        if (playerclasschoice == 1) className = "Paladin";
        else if (playerclasschoice == 2) className = "Lovec";
        else if (playerclasschoice == 3) className = "Mag";
        else if (playerclasschoice == 4) className = "Warlock";

        cout << "Class: " << className << endl;
        cout << "Statistiky:" << endl;
        cout << "Život - " << currentHealth << "/" << maxHealth << endl;
        cout << "Útok - " << attack << endl;
        cout << "Mana - " << currentMana << "/" << maxMana << endl;

        string choice;
        cout << "Chcete potvrdit výběr? (ano/ne): ";
        cin >> choice;
        if (choice == "ano") {
            confirmed = true;
        }
    }

    cout << "Začíná vaše dobrodružství!" << endl;

    return 0;
}
