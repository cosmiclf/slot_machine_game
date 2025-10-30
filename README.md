# 🎰 Slot Machine Game — IHM Project (C++ / .NET Framework)

## 📘 Overview
This project was developed as part of the **Human–Machine Interface (IHM)** module at **Télécom Physique Strasbourg**.

The goal is to create a **Windows Forms** application in **C++/CLI (.NET Framework)** that simulates the behavior of a **slot machine**.  
The graphical interface allows the user to:
- Configure the machine (symbols and winning combinations)
- Place bets and play
- Display total wins and losses

---

## 🗂️ Project Structure

The project is organized as follows:

| Folder/File | Description |
|--------------|-------------|
| `ClassesTP/` | C++ classes handling the core game logic (`BanditIHM`, `Combinaison`, etc.) |
| `FichiersInit/` | Initialization files (`.smb`, `.cmb`) |
| `FichiersOutput/` | Files generated after configuration |
| `Images/` | Graphic resources (slot symbols) |
| `MyForm.h / .cpp` | Main game form (user interface) |
| `ParametrageForm.h / .cpp` | Configuration form |
| `SlotMachineGame.sln` | Visual Studio solution file |

---

## 🕹️ Main Features

### 🎮 Game Form (`MyForm`)
- **Betting**: via a `NumericUpDown` (modifiable with mouse or keyboard)
- **Play**: press the **Go** button to start a round
- **Results Display**:
  - Drawn combination shown in `PictureBox`
  - Winnings displayed through a `MessageBox`
  - Total balance shown in a `Label`
- **Reset total gains**: through a `MenuStrip`
- **Load configuration files**: opens the configuration form

**Technical details:**
- The `BanditIHM` object is instantiated in the `MyForm` constructor
- Automatically destroyed when the form closes
- An `ImageList` is used to efficiently store and reuse all symbol images

---

### ⚙️ Configuration Form (`ParametrageForm`)
- Load `.smb` and `.cmb` files (symbols and winning combinations)
- Display file contents in `ListBox` controls
- Allow user to select winning combinations
- Save chosen configuration to `FichiersOutput/`
- Controlled closing via a dedicated button (not the “X”)

**Behavior and access logic:**
- This form appears **before** the main game form
- The game cannot start until initialization is complete
- The configuration form can be reopened from the game window
- Communication between forms is handled via a **custom event**  
  triggering the `Modifier_fichiers_jeu()` method in `MyForm`

---

## Technical Notes

### 🔄 String ↔ char* Conversion
A small helper function is used to convert between .NET `String^` and native `char*`:
```cpp
char* string2char(System::String^ chaineVS) {
    char* chaine = new char[chaineVS->ToCharArray()->Length + 1];
    for (int i = 0; i < chaineVS->ToCharArray()->Length; i++)
        chaine[i] = chaineVS->ToCharArray()[i];
    chaine[chaineVS->ToCharArray()->Length] = '\0';
    return chaine;
}
