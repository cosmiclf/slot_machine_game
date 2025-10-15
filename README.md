# Slot Machine Game — Projet IHM C++/.NET

## Présentation
Ce projet a été réalisé dans le cadre du module **Mise en œuvre d'Interfaces Homme-Machine (IHM)** à **Télécom Physique Strasbourg**.

L’objectif est de développer une application Windows Forms en **C++/CLI (.NET Framework)** simulant le fonctionnement d’une **machine à sous**.  
L’interface graphique permet de :
- Paramétrer la machine (symboles et combinaisons gagnantes)
- Jouer et miser
- Afficher les gains et pertes cumulés

---

## 🗂️ Structure du projet

Le projet se compose de plusieurs répertoires :

| Dossier/Fichier | Description |
|------------------|-------------|
| `ClassesTP/` | Classes C++ pour la logique métier (`BanditIHM`, `Combinaison`, etc.) |
| `FichiersInit/` | Fichiers d’initialisation (.smb, .cmb) |
| `FichiersOutput/` | Fichiers de sortie créés après paramétrage |
| `Images/` | Ressources graphiques du jeu |
| `MyForm.h / .cpp` | Formulaire principal (interface du jeu) |
| `ParametrageForm.h / .cpp` | Formulaire de paramétrage |
| `SlotMachineGame.sln` | Fichier de solution Visual Studio |


---

## 🕹️ Fonctionnalités principales

### Formulaire de Jeu (`MyForm`)
- **Mise** : via un `NumericUpDown` (valeur modifiable par clic ou clavier)
- **Jouer** : bouton **Go** pour lancer une partie
- **Affichage des résultats** :
  - Combinaison tirée (`PictureBox`)
  - Gain affiché dans une `MessageBox`
  - Total des gains/pertes affiché (`Label`)
- **Réinitialisation des gains** : via le `MenuStrip`
- **Chargement des fichiers de configuration** : ouvre le formulaire de paramétrage

**Implémentation technique :**
- Instanciation du `BanditIHM` dans le constructeur de `MyForm`
- Destruction automatique lors de la fermeture du formulaire
- Utilisation d’une `ImageList` pour stocker et réutiliser efficacement les images des symboles

---

### ⚙️ Formulaire de Paramétrage (`ParametrageForm`)
- Chargement des fichiers `.smb` et `.cmb` (symboles et combinaisons)
- Visualisation des contenus dans des `ListBox`
- Sélection des combinaisons gagnantes
- Enregistrement des paramètres dans `FichiersOutput/`
- Fermeture contrôlée du formulaire via un bouton dédié (et non le “X”)

**Contraintes et logiques d’accès :**
- Ce formulaire s’affiche **avant** le jeu
- Impossible de jouer sans avoir initialisé la machine
- Le formulaire peut être rouvert depuis le jeu
- Communication entre formulaires via **événement personnalisé**
  déclenchant `Modifier_fichiers_jeu()` dans `MyForm`

---

## Aspects techniques notables

### 🔄 Conversion String ↔ char*
Utilisation d’une fonction utilitaire :
```cpp
char* string2char(System::String^ chaineVS) {
    char* chaine = new char[chaineVS->ToCharArray()->Length + 1];
    for (int i = 0; i < chaineVS->ToCharArray()->Length; i++)
        chaine[i] = chaineVS->ToCharArray()[i];
    chaine[chaineVS->ToCharArray()->Length] = '\0';
    return chaine;
}

