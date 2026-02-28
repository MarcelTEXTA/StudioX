# TEXTA studioX

TEXTA studioX est un DAW (Digital Audio Workstation) conçu pour les créateurs de musique. Il offre une interface intuitive et des fonctionnalités puissantes pour la production musicale, l'enregistrement, le mixage et le mastering. Avec TEXTA studioX, les utilisateurs peuvent créer, éditer et partager leur musique facilement, que ce soit pour des projets personnels ou professionnels.

## Compilation

Pour compiler TEXTA studioX, suivez les étapes ci-dessous :

Dans `build`, avec Developer Command Prompt for Visual Studio, exécutez la commande suivante pour générer les fichiers de projet Visual Studio :

```bash
cd C:\Users\<TonNom>\Chemin\vers\dev\StudioX
rmdir /S /Q build
mkdir build
cd build
```
```bash
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Release ..
```

> Note : Assurez-vous d'avoir Visual Studio Build Tools ainsi que CMake et Ninja installés sur votre système.

Pour compiler le projet, ouvrez le fichier de solution généré dans Visual Studio et construisez le projet en sélectionnant "Build Solution" (Ctrl + Shift + B) ou en utilisant la ligne de commande suivante :

```bash
ninja
```

## Structure stricte du projet

Vous devez absolument avoir cette structure de projet pour que le projet puisse être compilé et fonctionner correctement :

```
dev
 ├── StudioX                        Dossier principal du projet
      ├── src                       Dossier contenant les fichiers source du projet
          ├── main.cpp              Point d'entrée de l'application
      ├── build                     Dossier de construction (généré par CMake)
 ├── imgui                          Dossier ImGui (à cloner depuis le dépôt officiel)
 ├── glfw                           Dossier GLFW (à cloner depuis le dépôt officiel)
```

## Fonctionnalités (à venir)

- Enregistrement audio
- Édition MIDI
- Mixage et mastering
- Support des plugins VST
- Outils de composition avancés
- Mode Beatmaker pour la création de rythmes