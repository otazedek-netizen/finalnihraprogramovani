#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
    int classBonusDamage;
    string className;
    srand(time(0));

    cout << "Vyberte si classu:" << endl;
    cout << "1. Paladin" << endl;
    cout << "2. Lovec" << endl;
    cout << "3. Mag" << endl;
    cout << "4. Warlock" << endl;

    bool confirmed = false;
    while (!confirmed) {
        cout << "Zadejte cislo classy: ";
        cin >> playerclasschoice;

        switch (playerclasschoice) {
            case 1:
                maxHealth = 16;
                currentHealth = 16;
                maxMana = 8;
                currentMana = 8;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 5;
                classBonusDamage = 5;
                break;
            case 2:
                maxHealth = 14;
                currentHealth = 14;
                maxMana = 7;
                currentMana = 7;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 6;
                classBonusDamage = 5;
                break;
            case 3:
                maxHealth = 13;
                currentHealth = 13;
                maxMana = 10;
                currentMana = 10;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 4;
                classBonusDamage = 6;
                break;
            case 4:
                maxHealth = 16;
                currentHealth = 16;
                maxMana = 8;
                currentMana = 8;
                gold = 0;
                level = 1;
                experience = 0;
                attack = 6;
                classBonusDamage = 5;
                break;
            default:
                cout << "Neplatna volba Zkuste znovu." << endl;
                continue;
        }

        if (playerclasschoice == 1) className = "Paladin";
        else if (playerclasschoice == 2) className = "Lovec";
        else if (playerclasschoice == 3) className = "Mag";
        else if (playerclasschoice == 4) className = "Warlock";

        cout << "Class: " << className << endl;
        cout << "Statistiky:" << endl;
        cout << "Zivot - " << currentHealth << "/" << maxHealth << endl;
        cout << "Utok - " << attack << endl;
        cout << "Mana - " << currentMana << "/" << maxMana << endl;

        string choice;
        cout << "Chcete potvrdit vyber? (ano/ne): ";
        cin >> choice;
        if (choice == "ano") {
            confirmed = true;
        }
    }

    int hp_nepritel = 10;
    int utok_nepritel = 2;

    cout << endl << "Narazil jsi na nepritele!" << endl;

    while (hp_nepritel > 0 && currentHealth > 0) {
        int akce;
        cout << "Tvoje HP: " << currentHealth << " | HP nepritele: " << hp_nepritel << endl;
        cout << "1 - Utok, 2 - Nic: ";
        cin >> akce;

        if (akce == 1) {
            hp_nepritel = hp_nepritel - (attack + classBonusDamage);
            cout << "Dal jsi ranu za " << (attack + classBonusDamage) << endl;
        }

        if (hp_nepritel > 0) {
            currentHealth = currentHealth - utok_nepritel;
            cout << "Nepritel te zasahl za " << utok_nepritel << endl;
        }
    }

    if (currentHealth <= 0) {
        cout << "Prohra!" << endl;
        return 0;
    } else {
        cout << "Vyhra! Porazil jsi prvni monstrum." << endl;
        if (rand() % 2 == 0) {
            cout << "Nasel jsi u nej 5 penez." << endl;
            gold = gold + 5;
        } else {
            cout << "Monstrum u sebe nemelo zadne penize." << endl;
        }
    }

    cout << "Pokracujes do male vesnice." << endl;
    cout << "Mas " << gold << " zlato." << endl;
    cout << "1 - Vylepsit zivot o 1 za 5 zlata" << endl;
    cout << "2 - Vylepsit utok o 1 za 5 zlata" << endl;
    cout << "3 - Nic" << endl;
    int volbaVesnice;
    cin >> volbaVesnice;
    if (volbaVesnice == 1) {
        if (gold >= 5) {
            maxHealth = maxHealth + 1;
            currentHealth = maxHealth;
            gold = gold - 5;
            cout << "Maximalni zivot vylepsen na " << maxHealth << "." << endl;
        } else {
            cout << "Nemas dostatek zlata! Pokracujes bez vylepseni." << endl;
        }
    } else if (volbaVesnice == 2) {
        if (gold >= 5) {
            attack = attack + 1;
            gold = gold - 5;
            cout << "Utok vylepsen na " << attack << "." << endl;
        } else {
            cout << "Nemas dostatek zlata! Pokracujes bez vylepseni." << endl;
        }
    } else {
        cout << "Pokracujes bez vylepseni." << endl;
    }

    cout << "Prichazis do dalsiho souboje s orkem." << endl;
    int hp_ork = 12;
    int utok_ork = 3;

    while (hp_ork > 0 && currentHealth > 0) {
        int akce2;
        cout << "Tvoje HP: " << currentHealth << " | HP orka: " << hp_ork << endl;
        cout << "1 - Utok, 2 - Specialni utok (vyuzije 2 many): ";
        cin >> akce2;

        if (akce2 == 1) {
            hp_ork = hp_ork - (attack + classBonusDamage);
            cout << "Uderil jsi orka za " << (attack + classBonusDamage) << " poskozeni." << endl;
        } else if (akce2 == 2) {
            if (currentMana >= 2) {
                hp_ork = hp_ork - (attack + classBonusDamage + 2);
                currentMana = currentMana - 2;
                cout << "Pouzil jsi specialni utok za " << (attack + classBonusDamage + 2) << " poskozeni." << endl;
            } else {
                cout << "Nemas dost many!" << endl;
            }
        } else {
            cout << "Nic jsi neudelal." << endl;
        }

        if (hp_ork > 0) {
            currentHealth = currentHealth - utok_ork;
            cout << "Ork te uderil za " << utok_ork << "." << endl;
        }
    }

    if (currentHealth <= 0) {
        cout << "Prohral jsi proti orku." << endl;
        return 0;
    } else {
        cout << "Vyhral jsi proti orku!" << endl;
        if (rand() % 2 == 0) {
            gold = gold + 10;
            cout << "Ziskal jsi 10 zlata." << endl;
        } else {
            cout << "Ork u sebe nemel zadne penize." << endl;
        }
        experience = experience + 10;
        cout << "Ziskal jsi 10 zkusenosti." << endl;
        if (experience >= level * 10) {
            level = level + 1;
            maxHealth = maxHealth + 1;
            attack = attack + 1;
            currentHealth = maxHealth;
            cout << "Novy level! Mas level " << level << "." << endl;
            cout << "Max zivot +1, utok +1." << endl;
        }
    }

    cout << "Potkas dva bandity chteji te okrast." << endl;
    int hp_bandita1 = 8;
    int hp_bandita2 = 8;
    int utok_bandit = 2;

    while ((hp_bandita1 > 0 || hp_bandita2 > 0) && currentHealth > 0) {
        cout << "Tvoje HP: " << currentHealth << " | Bandita1: " << hp_bandita1 << " | Bandita2: " << hp_bandita2 << " | Mana: " << currentMana << "/" << maxMana << endl;
        cout << "1 - Utok" << endl;
        cout << "2 - Specialni utok (vyuzije 2 many)" << endl;
        cout << "3 - Utek" << endl;
        int akce4;
        cin >> akce4;
        if (akce4 == 1) {
            if (hp_bandita1 > 0) {
                hp_bandita1 = hp_bandita1 - (attack + classBonusDamage);
                cout << "Uderil jsi banditu cislo jednicku za " << (attack + classBonusDamage) << " poskozeni." << endl;
            } else {
                hp_bandita2 = hp_bandita2 - (attack + classBonusDamage);
                cout << "Uderil jsi banditu cislo dvojku za " << (attack + classBonusDamage) << " poskozeni." << endl;
            }
        } else if (akce4 == 2) {
            if (currentMana >= 2) {
                currentMana = currentMana - 2;
                if (hp_bandita1 > 0) {
                    hp_bandita1 = hp_bandita1 - (attack + classBonusDamage + 2);
                }
                if (hp_bandita2 > 0) {
                    hp_bandita2 = hp_bandita2 - (attack + classBonusDamage + 2);
                }
                cout << "Pouzil jsi specialni utok na oba bandity." << endl;
            } else {
                cout << "Nemas dost many!" << endl;
            }
        } else {
            cout << "Utekas pry? Pokracujes ve boji." << endl;
        }
        if (hp_bandita1 > 0) {
            currentHealth = currentHealth - utok_bandit;
            cout << "Bandita cislo jedna te uderil za " << utok_bandit << " poskozeni." << endl;
        }
        if (hp_bandita2 > 0) {
            currentHealth = currentHealth - utok_bandit;
            cout << "Bandita cislo dva te uderil za " << utok_bandit << " poskozeni." << endl;
        }
    }
    if (currentHealth <= 0) {
        cout << "Banditi te porazili. Hra konci." << endl;
        return 0;
    } else {
        cout << "Vyhral jsi proti banditum!" << endl;
        gold = gold + 8;
        experience = experience + 8;
        cout << "Ziskal jsi 8 zlata a 8 zkusenosti." << endl;
        if (experience >= level * 10) {
            level = level + 1;
            maxHealth = maxHealth + 1;
            attack = attack + 1;
            currentHealth = maxHealth;
            cout << "Novy level! Mas level " << level << "." << endl;
            cout << "Max zivot +1, utok +1." << endl;
        }
    }

    cout << "Prichazis do maleho taboru a doplnujes naboj." << endl;
    cout << "1 - Doplni zivoty o 2 za 5 zlata" << endl;
    cout << "2 - Doplni manu o 2 za 5 zlata" << endl;
    cout << "3 - Pokracovat" << endl;
    int volbaTabor;
    cin >> volbaTabor;
    if (volbaTabor == 1) {
        if (gold >= 5) {
            gold = gold - 5;
            currentHealth = currentHealth + 2;
            if (currentHealth > maxHealth) currentHealth = maxHealth;
            cout << "Doprovan zivoty Aktualni HP: " << currentHealth << "/" << maxHealth << endl;
        } else {
            cout << "Nemas dost zlata." << endl;
        }
    } else if (volbaTabor == 2) {
        if (gold >= 5) {
            gold = gold - 5;
            currentMana = currentMana + 2;
            if (currentMana > maxMana) currentMana = maxMana;
            cout << "Doprovan mana Aktualni mana: " << currentMana << "/" << maxMana << endl;
        } else {
            cout << "Nemas dost zlata." << endl;
        }
    } else {
        cout << "Pokracujes dal." << endl;
    }

    cout << "Prichazis k potoku kde te napadnou tri goblini." << endl;
    int hp_goblin1 = 7;
    int hp_goblin2 = 7;
    int hp_goblin3 = 7;
    int utok_goblin = 2;

    while ((hp_goblin1 > 0 || hp_goblin2 > 0 || hp_goblin3 > 0) && currentHealth > 0) {
        cout << "Tvoje HP: " << currentHealth << " | Goblin1: " << hp_goblin1 << " | Goblin2: " << hp_goblin2 << " | Goblin3: " << hp_goblin3 << " | Mana: " << currentMana << "/" << maxMana << endl;
        cout << "1 - Utok" << endl;
        cout << "2 - Specialni utok (vyuzije 2 many)" << endl;
        cin >> volbaTabor;
        if (volbaTabor == 1) {
            if (hp_goblin1 > 0) {
                hp_goblin1 -= (attack + classBonusDamage);
                cout << "Uderil jsi goblina cislo jedna za " << (attack + classBonusDamage) << " poskozeni." << endl;
            } else if (hp_goblin2 > 0) {
                hp_goblin2 -= (attack + classBonusDamage);
                cout << "Uderil jsi goblina cislo dva za " << (attack + classBonusDamage) << " poskozeni." << endl;
            } else {
                hp_goblin3 -= (attack + classBonusDamage);
                cout << "Uderil jsi goblina cislo tri za " << (attack + classBonusDamage) << " poskozeni." << endl;
            }
        } else if (volbaTabor == 2) {
            if (currentMana >= 2) {
                currentMana -= 2;
                if (hp_goblin1 > 0) hp_goblin1 -= (attack + classBonusDamage + 2);
                if (hp_goblin2 > 0) hp_goblin2 -= (attack + classBonusDamage + 2);
                if (hp_goblin3 > 0) hp_goblin3 -= (attack + classBonusDamage + 2);
                cout << "Pouzil jsi specialni utok na vsechny gobliny." << endl;
            } else {
                cout << "Nemas dost many!" << endl;
            }
        } else {
            cout << "Nic jsi neudelal." << endl;
        }
        if (hp_goblin1 > 0) {
            currentHealth -= utok_goblin;
            cout << "Goblin cislo jedna te uderil za " << utok_goblin << " poskozeni." << endl;
        }
        if (hp_goblin2 > 0) {
            currentHealth -= utok_goblin;
            cout << "Goblin cislo dva te uderil za " << utok_goblin << " poskozeni." << endl;
        }
        if (hp_goblin3 > 0) {
            currentHealth -= utok_goblin;
            cout << "Goblin cislo tri te uderil za " << utok_goblin << " poskozeni." << endl;
        }
    }
    if (currentHealth <= 0) {
        cout << "Goblini te porazili Hra konci." << endl;
        return 0;
    } else {
        cout << "Vyhral jsi proti goblinum!" << endl;
            gold = gold + 12;
            experience = experience + 12;
            cout << "Ziskal jsi 12 zlata a 12 zkusenosti." << endl;
            if (experience >= level * 10) {
                level = level + 1;
                maxHealth = maxHealth + 1;
                attack = attack + 1;
            cout << "Max zivot +1, utok +1." << endl;
        }
    }

    cout << "Pokracujes do jeskyne kde se skryva mini boss - divoky troll." << endl;
    int hp_troll = 15;
    int utok_troll = 4;

    while (hp_troll > 0 && currentHealth > 0) {
        currentHealth = currentHealth - utok_troll;
        cout << "Troll te uderil za " << utok_troll << "." << endl;

        if (currentHealth <= 0) {
            break;
        }

        int akce3;
        cout << "Tvoje HP: " << currentHealth << " | HP trolla: " << hp_troll << " | Mana: " << currentMana << "/" << maxMana << endl;
        cout << "1 - Utok, 2 - Specialni utok (vyuzije 2 many), 3 - Obnovit trochu many" << endl;
        cin >> akce3;

        if (akce3 == 1) {
            hp_troll = hp_troll - (attack + classBonusDamage);
            cout << "Uderil jsi trolla za " << (attack + classBonusDamage) << " poskozeni." << endl;
        } else if (akce3 == 2) {
            if (currentMana >= 2) {
                hp_troll = hp_troll - (attack + classBonusDamage + 3);
                currentMana = currentMana - 2;
                cout << "Pouzil jsi specialni utok za " << (attack + classBonusDamage + 3) << " poskozeni." << endl;
            } else {
                cout << "Nemas dost many!" << endl;
            }
        } else if (akce3 == 3) {
            currentMana = currentMana + 2;
            if (currentMana > maxMana) currentMana = maxMana;
            cout << "Obnovil jsi 2 many. Mana: " << currentMana << "/" << maxMana << endl;
        } else {
            cout << "Nic jsi neudelal." << endl;
        }
    }

    if (currentHealth <= 0) {
        cout << "Troll te porazil. Hra konci." << endl;
        return 0;
    } else {
        cout << "Vyhral jsi proti trollovi!" << endl;
        gold = gold + 15;
        experience = experience + 15;
        cout << "Ziskal jsi 15 zlata a 15 zkusenosti." << endl;
        if (experience >= level * 10) {
            level = level + 1;
            maxHealth = maxHealth + 1;
            attack = attack + 1;
            currentHealth = maxHealth;
            cout << "Novy level! Mas level " << level << "." << endl;
            cout << "Max zivot +1, utok +1." << endl;
        }
    }

    cout << "Prichazis do druhe vesnice pred finalnim bojem." << endl;
    cout << "Mas " << gold << " zlata." << endl;
    cout << "1 - Doplnit zivoty na maximum za 5 zlata" << endl;
    cout << "2 - Doplnit manu na maximum za 5 zlata" << endl;
    cout << "3 - Pokracovat bez nakupu" << endl;
    int vesnice2;
    cin >> vesnice2;
    if (vesnice2 == 1) {
        if (gold >= 5) {
            gold -= 5;
            currentHealth = maxHealth;
            cout << "Tvoje zivoty jsou plne." << endl;
        } else {
            cout << "Nemas dost zlata." << endl;
        }
    } else if (vesnice2 == 2) {
        if (gold >= 5) {
            gold -= 5;
            currentMana = maxMana;
            cout << "Tvoje mana je plna." << endl;
        } else {
            cout << "Nemas dost zlata." << endl;
        }
    } else {
        cout << "Pokracujes bez doplneni." << endl;
    }

    cout << "Na ceste k bossovi potkas skupinu skretu." << endl;
    int hp_skret = 12;
    int utok_skret = 3;
    while (hp_skret > 0 && currentHealth > 0) {
        cout << "Tvoje HP: " << currentHealth << " | HP skretu: " << hp_skret << " | Mana: " << currentMana << "/" << maxMana << endl;
        cout << "1 - Utok" << endl;
        cout << "2 - Specialni utok (vyuzije 2 many)" << endl;
        int akce5;
        cin >> akce5;
        if (akce5 == 1) {
            hp_skret = hp_skret - (attack + classBonusDamage);
            cout << "Uderil jsi skretu za " << (attack + classBonusDamage) << " poskozeni." << endl;
        } else if (akce5 == 2) {
            if (currentMana >= 2) {
                hp_skret = hp_skret - (attack + classBonusDamage + 2);
                currentMana = currentMana - 2;
                cout << "Pouzil jsi specialni utok za " << (attack + classBonusDamage + 2) << " poskozeni." << endl;
            } else {
                cout << "Nemas dost many!" << endl;
            }
        } else {
            cout << "Nic jsi neudelal." << endl;
        }
        if (hp_skret > 0) {
            currentHealth = currentHealth - utok_skret;
            cout << "Skret te uderil za " << utok_skret << " poskozeni." << endl;
        }
    }
    if (currentHealth <= 0) {
        cout << "Skřet te porazil Hra konci." << endl;
        return 0;
    } else {
        cout << "Vyhral jsi proti skretovi!" << endl;
        gold = gold + 10;
        experience = experience + 10;
        cout << "Ziskal jsi 10 zlata a 10 zkusenosti." << endl;
        if (experience >= level * 10) {
            level = level + 1;
            maxHealth = maxHealth + 1;
            attack = attack + 1;
            currentHealth = maxHealth;
            cout << "Novy level! Mas level " << level << "." << endl;
            cout << "Max zivot +1, utok +1." << endl;
        }
    }

    cout << "Dostavas se na konec cesty Ceka na tebe Tetraflux." << endl;
    int hp_tetraflux = 30;
    int tetrafluxAttack = 1;
    int tetrafluxArmor = 0;
    int bonusPosileni = 0;
    int bonusOziveni = 0;
    int bonusUtoku = 0;
    int bonusBrneni = 0;

    while (hp_tetraflux > 0 && currentHealth > 0) {
        cout << "Tvoje HP: " << currentHealth << " | Mana: " << currentMana << "/" << maxMana << " | HP Tetraflux: " << hp_tetraflux << " | Armor: " << tetrafluxArmor << endl;
        cout << "Tetraflux se chysta vykonat akce: 1-Posileni, 2-Oziveni, 3-Utok, 4-Brneni." << endl;
        cout << "Zvol akci, kterou mu zablokujes: ";
        int blok;
        cin >> blok;
        if (blok < 1 || blok > 4) {
            cout << "Neplatna volba, blokujes Posileni." << endl;
            blok = 1;
        }

        int volbaTetra = rand() % 4 + 1;
        while (volbaTetra == blok) {
            volbaTetra = rand() % 4 + 1;
        }

        if (volbaTetra == 1) {
            int pridani = 1 + bonusPosileni;
            tetrafluxAttack = tetrafluxAttack + pridani;
            bonusPosileni = bonusPosileni + 1;
            cout << "Tetraflux pouzil Posileni. Jeho sila narostla o " << pridani << "." << endl;
        } else if (volbaTetra == 2) {
            int pridani = 1 + bonusOziveni;
            hp_tetraflux = hp_tetraflux + pridani;
            bonusOziveni = bonusOziveni + 1;
            cout << "Tetraflux pouzil Oziveni. Ziskal " << pridani << " HP." << endl;
        } else if (volbaTetra == 3) {
            int poskozeni = tetrafluxAttack + bonusUtoku;
            currentHealth = currentHealth - poskozeni;
            bonusUtoku = bonusUtoku + 1;
            cout << "Tetraflux te utocil za " << poskozeni << " poskozeni." << endl;
        } else if (volbaTetra == 4) {
            int pridani = 1 + bonusBrneni;
            tetrafluxArmor = tetrafluxArmor + pridani;
            bonusBrneni = bonusBrneni + 1;
            cout << "Tetraflux se ochranil. Ziskal " << pridani << " brneni." << endl;
        }

        if (currentHealth <= 0) {
            break;
        }

        cout << "Tvoje tah. Vyber, co udelas:" << endl;
        cout << "1 - Utok" << endl;
        cout << "2 - Specialni utok (vyuzije 3 many)" << endl;
        cout << "3 - Opravdove leceni o 2 (vyuzije 2 many)" << endl;
        int akce4;
        cin >> akce4;

        if (akce4 == 1) {
            int poskozeni = attack + classBonusDamage - tetrafluxArmor;
            if (poskozeni < 0) poskozeni = 0;
            hp_tetraflux = hp_tetraflux - poskozeni;
            cout << "Uderil jsi tetraflux za " << poskozeni << " poskozeni." << endl;
        } else if (akce4 == 2) {
            if (currentMana >= 3) {
                currentMana = currentMana - 3;
                int poskozeni = attack + classBonusDamage + 4 - tetrafluxArmor;
                if (poskozeni < 0) poskozeni = 0;
                hp_tetraflux = hp_tetraflux - poskozeni;
                cout << "Pouzil jsi specialni utok za " << poskozeni << " poskozeni." << endl;
            } else {
                cout << "Nemas dost many!" << endl;
            }
        } else if (akce4 == 3) {
            if (currentMana >= 2) {
                currentMana = currentMana - 2;
                currentHealth = currentHealth + 2;
                if (currentHealth > maxHealth) currentHealth = maxHealth;
                cout << "Obnovil jsi 2 zivota. HP: " << currentHealth << "/" << maxHealth << endl;
            } else {
                cout << "Nemas dost many!" << endl;
            }
        } else {
            cout << "Nic jsi neudelal." << endl;
        }

        if (hp_tetraflux <= 0) {
            break;
        }
    }

    if (currentHealth <= 0) {
        cout << "Tetraflux te porazil. Hra konci." << endl;
        return 0;
    } else {
        cout << "Vyhral jsi! Porazil jsi Tetrafluxe." << endl;
        gold = gold + 30;
        experience = experience + 30;
        cout << "Mas " << gold << " zlata a " << experience << " zkusenosti." << endl;
    }

    return 0;
}
