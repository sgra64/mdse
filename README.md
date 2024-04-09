## Aufgaben A1, A2, A3, A4

Ziel der Aufgaben A1, A2, A3, A4 ist, eine moderne Software-Entwicklungsumgebung
auf Ihrem Laptop auszubauen, die besteht aus:

1. [Aufgabe A1](#a1-terminal-bash-windows-linux-or-zsh-mac) - Terminal *bash* (Windows, Linux) or *zsh* (Mac)

1. [Aufgabe A2](#a2-docker) - Docker

1. [Aufgabe A3](#a3-vscode-ide-mit-dev-containers) - *VSCode* IDE mit *Dev Containers*

1. [Aufgabe A4](#a4-hello-world) - *Hello World*

4 Pts


&nbsp;

## A1: Terminal *bash* (Windows, Linux) or *zsh* (Mac)

Ein "Terminal" is heute eine Software zur klassischen Eingabe von Kommandos und der
Ausgabe von Antworten.

In einem Terminal (Prozess) läuft ein weitere Prozess eines Kommando-Interpreters
(*"Shell"*), welcher die Eingaben interpretiert und ausführt.
Auf Mac wird gern
[*zsh*](https://en.wikipedia.org/wiki/Z_shell)
als Shell-Prozess verwendet. Bei Unix/Linux ist es
[*bash*](https://en.wikipedia.org/wiki/Bash_(Unix_shell))
(Bourne-Again-Shell als Reimplementierung der "alten" Shell *sh* durch Brian Fox).

Ziel der Übung A1 ist, dass Sie eine professionelle Terminal-Software auf Ihrem
Laptop haben.

1. **Für Windows**, installieren Sie bitte `cygwin` (Unix-Emulator), folgen Sie den Schritten in
    [setup_cygwin](https://github.com/sgra64/markup/blob/main/setup_cygwin/README.md)

1. **Alle** (Mac, Linux, Windows), falls im nächsten Schritt Fehler auftreten,
    schauen Sie bitte, dass Sie
    [.bashrc und .zshrc Files im $HOME Directory](https://github.com/sgra64/markup/tree/main/setup_rcfiles)
    richtig gesetzt haben.

1. Öffnen Sie ein Terminal und prüfen Sie, ob alle Werkzeuge korrekt installiert sind
    und aufgerufen werden können.

    ```
    ls -la
    ```
    Ausgabe aller Files im aktuellen Verzeichnis:
    ```
    total 393
    drwxr-xr-x 1 svgr2 Kein      0 Apr  9 17:28 .
    drwxr-xr-x 1 svgr2 Kein      0 Feb 25 13:29 ..
    drwxr-xr-x 1 svgr2 Kein      0 Apr 14  2019 .aws
    -rw-r--r-- 1 svgr2 Kein  19736 Apr  1 19:24 .bash_history
    lrwxrwxrwx 1 svgr2 Kein     15 Apr  7 12:58 .bashrc -> .dot/startup.rc
    drwxr-xr-x 1 svgr2 Kein      0 Apr  5 21:10 .config
    drwxr-xr-x 1 svgr2 Kein      0 Jan  7 20:23 .docker
    drwxr-xr-x 1 svgr2 Kein      0 Apr  7 10:23 .dot
    -rw-r--r-- 1 svgr2 Kein   1089 Apr  7 12:58 .gitconfig
    drwxr-xr-x 1 svgr2 Kein      0 Apr  9 17:14 .ssh
    lrwxrwxrwx 1 svgr2 Kein     11 Apr  7 12:58 .vimrc -> .dot/vim.rc
    lrwxrwxrwx 1 svgr2 Kein     15 Apr  7 12:58 .zprofile -> .dot/profile.rc
    lrwxrwxrwx 1 svgr2 Kein     15 Apr  7 12:58 .zshrc -> .dot/startup.rc
    drwxr-xr-x 1 svgr2 Kein      0 Apr  9 17:18 tmp
    drwxr-xr-x 1 svgr2 Kein      0 Apr  9 17:30 workspaces
    ```


&nbsp;

## A2: Docker

[Docker](https://github.com/sgra64/markup/tree/docker) ist eine moderne
Container-Technologie, die es erlaubt, *Prozesse* in einem Container in
Isolation zu *Prozessen* in anderen Containern auf einer Maschine ablaufen
zu lassen. `Docker` ist eine leichtgewichtige Alternative zu
*Virtuellen Maschinen (VM)* und *Hypervisor*-Technologien.

Installieren Sie
[Docker-Desktop](https://www.docker.com/products/docker-desktop) und starten
Sie das GUI.

<img src="https://www.docker.com/wp-content/uploads/2023/08/docker-desktop-hero-v2.svg" alt="drawing" width="600"/>


Öffnen Sie das Terminal und geben Sie `docker`-Kommands ein:

```sh
docker --version
```

Ausgabe:

```
Docker version 24.0.6, build ed223bc
```

Dazu muss der Docker *daemon*-Prozesss laufen, d.h. `Docker-Desktop` gestartet
sein.

Weitere `docker`-Kommands:

```sh
docker ps -a                # Anzeige aller Docker container
docker image ls             # Anzeige aller Docker images
```


&nbsp;

## A3: *VSCode* IDE mit *Dev Containers*

[VSCode](https://code.visualstudio.com) ist eine moderne IDE (Integrated Development
Environment), die heute Standards setzt und andere (ältere) IDE ablöst.

`VSCode` zeichnet sich aus, dass sie alle gängigen Programmiersprachen unterstützt
("polyglott"). Zudem hat VSCode Integrationen an alle gängigen Software-Werkzeuge,
wie

- git,

- build tools (make, maven, gradle, ...),

- entfernte Ausführungsumgebungen (WSL, Docker Container, Cloud).

[Dev Container](https://code.visualstudio.com/docs/devcontainers/containers)
ist eine Technologie aus `VSCode`, bei der Entwicklungswerkzeuge (Programmiesprachen,
aber auch Datenbanken u.a.) nicht mehr auf dem System (native) installiert werden
müssen, sondern über vorgefertigte `Docker`-Images bezogen werden können.

Installieren Sie bitte `VSCode` und starten Sie die IDE.

Installieren Sie in `VSCode` bitte die Extensions für `Docker` und `Dev Containers`.

<img src="https://code.visualstudio.com/assets/docs/devcontainers/create-dev-container/connected-to-dev-container.png" alt="drawing" width="600"/>



&nbsp;

## A4: *Hello World*

Als abschliessendes Beispiel der Übung soll ein einfaches C++ - Programm
*"Hello World"* in einem `Dev Container` für `C++` ausgefürt werden.

```c++
#include <iostream>
using namespace std;

int main() {
    std::cout << "Hello World!" << endl << endl;
    return 0;
}
```

Augabe:

```
Hello World!
```

Ausführung im C++ Dev-Container in VS Code:

<img src="https://github.com/sgra64/markup/blob/docker/img/dev_container_c++.jpg?raw=true" alt="drawing" width="600"/>


