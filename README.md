<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->
<!-- B1 (SE-1)
-->
# D: Projekt *"cpp-fun"*

<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

In dieser Übung soll ein neues Projekt: *"cpp-fun"* angelegt werden mit:

- einer verbesserten Struktur (*"scaffold"*), die Quellcode und übersetzten
    Code trennt in Verzeichnisse:

    - `src` - Verzeichnis mit *C++* Quellcode (`.cpp` files),

    - `src/include` - Verzeichnis mit *Header* Quellcode (`.h`, `.tpp` files),

    - `out` - Verzeichnis mit übersetzen Files (`.o` files),

- [*Source-code Management*](https://en.wikipedia.org/wiki/Version_control)
    mit [*Git*](https://en.wikipedia.org/wiki/Git) in einem lokalen
    repository-Verzeichnis `.git` mit:

    - [*Git Submodules*](https://git-scm.com/book/en/v2/Git-Tools-Submodules)
        (siehe [*article*](https://www.freecodecamp.org/news/how-to-use-git-submodules/))
        für die Verzeichnisse:

        - `dev-container` - für das Management des `.dev-container` Verzeichnisses
            (nicht Teile des Quellcodes) sowie

        - `vscode` - für das Management des `.vscode` Verzeichnisses
            (ebenfalls nicht Teile des Quellcodes);

    - sowie einem *main*-Branch mit dem Quellcode.


- *Build-Management* mit
    [*make*](https://gertjanvandenburg.com/files/talk/make.html).


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

---

Project "*cpp-fun*" is created in steps:

1. [Einrichten der Project Struktur ("*Scaffold*")](#1-einrichten-der-project-struktur-scaffold)

1. [Lokales *Git* Repository einrichten](#2-lokales-git-repository-einrichten)

1. [*Git* Module einrichten](#3-git-module-einrichten)

1. [*Devcontainer* Start und Hinzufügen von Quellcode](#4-devcontainer-start-und-hinzufügen-von-quellcode)

1. [*Build*-Prozess ausführen](#5-build-prozess-ausführen)

1. [Eigenes *Remote* Repository einrichten](#6-eigenes-remote-repository-einrichten)

1. [Zusammenfassung](#7-zusammenfassung)


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 1. Einrichten der Project Struktur ("*Scaffold*")

Das Projekt befindet sich im Verzeichnis: `cpp-fun` im Verzeichnis `workspaces`
(parallel zum vorherigen Projekt `c-fun`).

Das Projekt hat eine Struktur (*"scaffold"*), die aus Unterverzeichnissen besteht:

```sh
<workspaces>    # workspace folder with project directories
 |
 +-<cpp-fun>        # folder of the 'cpp-fun' project
   +--README.md         # project markup file (this file)
   |
   +-<.git>             # folder with the local git repository
   +--.gitignore        # file with patterns for git to ignore
   +--.gitmodules       # file that describes imported git-modules
   |
   +-<.vscode>          # folder with VSCode project settings for the project (git-module)
   |   +--.bashrc           # script to source run() command
   |   +--settings.json     # project settings
   |   +--launch.json       # VSCode launch targets
   |   +--tasks.json        # program launch settings
   |
   +-<.devcontainer>    # folder with devcontainer information (git-module)
   |   +--devcontainer.json # devcontainer settings
   |   +--Dockerfile        # file to build devcontainer image
   |
   +-<src>              # <src> contains the project source code
   |  |
   |  +--main.cpp           # source file with 'main()' function
   |  +-<include>           # C++ header files (*.h, *.tpp files)
   |  +-<tests>             # src/tests: Unit tests (if present)
   |
   +-<out>              # folder with files created by the project build process
   |  |
   |  +--main               # executable file produced by the build-process
   |  |
   |  +-<compiled>          # folder with compiled '.o'-files
   |
   +--Makefile          # project 'Makefile' to control the project build process
   +--Makefile.dep      # dependency file for 'make', if present
   |
```

Führen Sie die folgenden Schritte aus, um das neue Projekt einzurichten.
Es wir angenommen, dass parallel das vorherige Projekt: `c-fun` im Verzeichnis
`workspaces` existiert.

```sh
cd workspaces                   # change into the 'workspaces' folder

ls -la                          # show content of 'workspaces' folder
```
```
total 352
drwxr-xr-x 1 svgr2 Kein      0 May 20 22:13 .
drwxr-xr-x 1 svgr2 Kein      0 May 17 20:23 ..
drwxr-xr-x 1 svgr2 Kein      0 May 20 22:07 c-fun       <-- prior project
```

```sh
mkdir cpp-fun                   # create folder for the new project 'cpp-fun'

cd cpp-fun                      # change into the new 'cpp-fun' project folder

ls -la                          # show content of the project folder
```
```
$ l
total 97
drwxr-xr-x 1     0 May 20 22:15 ./
drwxr-xr-x 1     0 May 20 22:13 ../     <-- empty project folder
```

Im nächsten Schritt wird ein lokales *git* - Repository für *Code-Management*
eingerichtet.


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 2. Lokales *Git* Repository einrichten

Als Voraussetzung sind einige *git-settings* einzurichten:

```sh
# add entries 'user.name' and 'user.email' to file '.gitconfig'
# change "your name" and "your-email@bht-berlin.de" with your data
git config --global user.name "your name"
git config --global user.email "your-email@bht-berlin.de"

# add more entries:
git config --global core.ignorecase true        # ignore upper/lower case in file names
git config --global core.autocrlf false         # disable crlf conversion on checkout
git config --global core.filemode false         # ignore filemode (rwx) changes
git config --global core.eol lf                 # always use newline '\n' as end-of-line

git config --global init.defaultBranch main     # 'main' is default branch, not 'master'

# show settings in file '.gitconfig' in the HOME directory
cat ~/.gitconfig
```
```
[user]
        name = Sven Graupner                <-- make sure your name and email appear
        emmail = sgraupner@bht-berlin.de      

[core]
        ignorecase = true
        autocrlf = false
        filemode = false
        eol = lf
[init]
        defaultBranch = main
```


&nbsp;

Ein lokales *git* repository wird mit zwei Schritten eingerichtet:

1. Zunächst wird das *git* Repository angelegt (*git init*) mit dem Namen des
    Haupt-Branches *main* (nicht *master*).

1. Anschliessend wird ein initiales (leeres) Commit erstellt und mit *"root"*
    getagged.

```sh
# create new local git repository
git init --initial-branch=main

# create first (empty) commit and tag as 'root'
git commit --allow-empty -m "initial root commit (empty)"
git tag root
```

Man kann das erste Commit mit *git*-Log anzeigen:

```sh
git log                     # show commit log (commit history, full text)

git log --oneline           # show single-line commits
```

Der vollständige Log zeigt alle Informationen zu dem aufgezeichneten Commit:

```
commit b72a8afd05ef9ecd994cba8df77661ed644546c3 (tag: root)
Author: Sven Graupner <sgraupner@bht-berlin.de>
Date:   Wed May 27 12:41:02 2026 +0200

    initial root commit (empty)
```

Die single-line Form zeigt jedes Commit mit nur einer Zeile:

```
b72a8af (tag: root) initial root commit (empty)
```

Im Projektverzeichnis ist ein neues Unterverzeichnis `.git` angelegt worden,
welches das lokale *git* Repository enthält:

```sh
ls -la
```
```
total 116
drwxr-xr-x 1 svgr2 Kein     0 May 27 11:36 .
drwxr-xr-x 1 svgr2 Kein     0 May 20 22:13 ..
drwxr-xr-x 1 svgr2 Kein     0 May 27 11:29 .git         <-- lokales git repository
```


&nbsp;

Als nächstes wird eine Datei
[*.gitignore*](https://github.com/sgra64/mdse/blob/main/.gitignore)
hinzugefügt, in der Muster für Dateien oder Verzeichnisse stehen, welche *git*
fortan ignorieren soll.

```sh
# download file '.gitignore'
curl -o .gitignore https://raw.githubusercontent.com/sgra64/mdse/refs/heads/main/.gitignore

ls -la                      # show the new '.gitignore' file
```
```
total 116
drwxr-xr-x 1 svgr2 Kein     0 May 27 11:36 .
drwxr-xr-x 1 svgr2 Kein     0 May 20 22:13 ..
drwxr-xr-x 1 svgr2 Kein     0 May 27 11:29 .git
-rw-r--r-- 1 svgr2 Kein   793 May 27 11:36 .gitignore   <-- new '.gitignore' file
```

```sh
cat .gitignore              # show the content of '.gitignore' file
```

Die neue Datei *.gitignore* wird jetzt auf den *main* Branch aufgezeichnet (committed).
Neue Commits werden bei *git* in zwei Schritten erstellt:

1. sammeln aller aufzuzeichnenden Dateien als Vorbereitung des Commits (*"stagen"* -
    vergleichbar mit einem *"shopping cart"*) mit:

    - `git add <files>` -- stage files, Hinzufügen zum *"shopping cart"*.

    - Gegenoperation:

        - `git reset <files>` -- Entfernen der Dateien aus dem *"shopping cart"*.

1. Aufzeichnnug aller staged Files als *"Commit"*:

    - `git commit -m "commit-message"` -- Aufzeichnung aller staged files als Commit.

    - Gegenoperationen:

        - `git reset HEAD~1` -- Entfernen des letzten Commits (das Zeichen
            Tilde `"~"` beachten, welches als *"Minus"* gelesen wird). Alle
            aufgezeichneten Dateien werden in das Projektverzeichnis
            zurückgeschrieben und bleiben somit erhalten.

        - `git reset --hard HEAD~1` -- Gegenoperation: Entfernen des letzten
            Commits. Die aufgezeichneten Stände der Dateien gehen verloren.

Im konkreten Fall der Aufzeichnug der Datei *.gitignore* heisst das:


```sh
# show git-status of the project, file '.gitignore' appears in red as "untracked"
git status

# stage file 'gitignore' in preparation of commit ("staging")
git add .gitignore

# file '.gitignore' is now staged and appears in green
git status

# "commit" staged files with message: "add .gitignore"
git commit -m "add .gitignore"

# show the commit log, which now has two commits
git log --oneline
```
```
2487442 (main) add .gitignore
b72a8af (tag: root) initial root commit (empty)
```


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 3. *Git* Module einrichten

[*Git Submodule*](https://git-scm.com/book/en/v2/Git-Tools-Submodules)
(siehe: [*article*](https://www.freecodecamp.org/news/how-to-use-git-submodules/))
werden für Inhalte in Projekten verwendet, die kein Source-Code im eigentlichen
Sinn sind und *"ausserhalb des Projekts"* in separaten *git*-Repositories
gepflegt und an Team-Mitglieder in deren Projekte ausgespielt werden (auch
Updates).

Hier sind das die Verzeichnisse:

- [*.devcontainer*](https://github.com/sgra64/mdse-devcontainer) -- für die
    Einbindung des Projekts in eine gleiche *dev-container / Docker* Umgebung
    und

- [*.vscode*](https://github.com/sgra64/mdse-vscode) -- für die Verteilung
    gleicher Einstellungen an das Team für die *VSCode IDE*.

Beide Teile werden als *git*-Module in das Projekt importiert.

*Git*-Module werden in einem separaten *git Branch* verwaltet, der vom
*main* Branch am aktuellen Commit *"add .gitignore"* abgezweigt wird.

Das Anlegen neuer Branches erfolgt mit `-c` bei dem Kommando `git switch`
gefolgt vom Namen des neuen Branches. Zusätzlich kann man ein Commit als
Abzweigpunkt des neuen Branches angeben. Fehlt dieser, wird der aktuelle
Commit als Abzweigpunkt verwendet:

- `git switch -c <branch-name> <abzweigpunkt>` -- Anlegen eines neuen lokalen
    Branches am aktuellen Commit bzw. an einem als Abzweigpunkt angegebenen
    Commit.

- Gegenoperation:

    - `git branch -d <branch-name>` -- Entfernen eines lokalen Branches mit
        allen aufgezeichneten Commit (diese gehen verloren).

Graphisch werden branches wie folgt gezeichnet:

<img src="https://raw.githubusercontent.com/sgra64/mdse/refs/heads/markup/img/main/git-branches-1-main.png" width="600"/>


```sh
git switch -c git-modules           # create (-c) new branch: 'git-modules' at
                                    # the current commit "add .gitignore"

git branch          # show branches that currently exist in the git repository
```
```
* git-modules       <-- new banch 'git-modules' is the current branch (green, plus: '*')
  main
```

Der mit `"*"` markierte Branch ist der *"aktuelle Branch"*, d.h. der Branch,
auf dem alle fortan ausgeführten Commits aufgezeichnet werden.

Als nächstes wird Git-Modul
[*.devcontainer*](https://github.com/sgra64/mdse-devcontainer) importiert:

```sh
# import git submodule '.devcontainer' from the remote 'mdse-devcontainer' repository
git submodule add -f -- https://github.com/sgra64/mdse-devcontainer .devcontainer
# 
# remove file '.gitmodules' from tracking index to avoid removal when switching branches
git rm --cached .gitmodules
```
```Cloning into 'C:/Sven1/svgr2/workspaces/mdse/cpp-fun/.devcontainer'...
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 5 (delta 0), reused 5 (delta 0), pack-reused 0 (from 0)
Receiving objects: 100% (5/5), done.

rm '.gitmodules'
```

Neue Inhalte wurden in das Projekt importiert:

```sh
ls -la                  # show project content
```
```
total 121
drwxr-xr-x 1     0 May 27 12:18 ./
drwxr-xr-x 1     0 May 20 22:13 ../
drwxr-xr-x 1     0 May 27 12:18 .devcontainer/      <-- new 'devcontainer' folder
drwxr-xr-x 1     0 May 27 12:19 .git/
-rw-r--r-- 1   793 May 27 12:01 .gitignore
-rw-r--r-- 1   101 May 27 12:18 .gitmodules         <-- new file
```

Der neue Inhalt kann angezeigt werden:

```sh
ls -la .devcontainer    # show content of new folder '.devcontainer'

cat .gitmodules         # show content of new file '.gitmodules'
```
```
total 14
drwxr-xr-x 1   0 May 27 12:26 ./
drwxr-xr-x 1   0 May 27 12:18 ../
-rw-r--r-- 1  38 May 27 12:18 .git
-rw-r--r-- 1 628 May 27 12:26 devcontainer.json     <-- new file 'devcontainer.json'
-rw-r--r-- 1 155 May 27 12:26 Dockerfile            <-- new file 'Dockerfile'


[submodule ".devcontainer"]     <-- content of file `.gitmodules` shows modules URL
        path = .devcontainer
        url = https://github.com/sgra64/mdse-devcontainer
```

Nach dem Import des *git-Moduls* ist dieser im Zustand *"staged"* und muss noch
committed werden:

```sh
git status              # shows new git-module as staged

# commit new git-module '.devcontainer'
git commit -m "add gitmodule .devcontainer"

git log --oneline       # show commit log
```
```
44b2638 (HEAD -> git-modules) add gitmodule .devcontainer
2487442 (main) add .gitignore
b72a8af (tag: root) initial root commit (empty)
```


&nbsp;

Als nächstes wird Git-Modul
[*.vscode*](https://github.com/sgra64/mdse-vscode) importiert:

```sh
# import git submodule '.devcontainer' from the remote 'mdse-devcontainer' repository
git submodule add -f -- https://github.com/sgra64/mdse-vscode .vscode
# 
# remove file '.gitmodules' from tracking index to avoid removal when switching branches
git rm --cached .gitmodules
```
```Cloning into 'C:/Sven1/svgr2/workspaces/mdse/cpp-fun/.devcontainer'...
Cloning into 'C:/Sven1/svgr2/workspaces/mdse/cpp-fun/.vscode'...
remote: Enumerating objects: 8, done.
remote: Counting objects: 100% (8/8), done.
remote: Compressing objects: 100% (7/7), done.
remote: Total 8 (delta 0), reused 8 (delta 0), pack-reused 0 (from 0)
Receiving objects: 100% (8/8), done.

rm '.gitmodules'
```

Auch dieser Import muss noch committed werden:

```sh
git status              # shows new git-module as staged

# commit new git-module '.vscode'
git commit -m "add gitmodule .vscode"

git log --oneline       # show commit log
```

Branch *git-modules* now has four commits:

```
f68e4b1 (HEAD -> git-modules) add gitmodule .vscode
44b2638 add gitmodule .devcontainer
2487442 (main) add .gitignore
b72a8af (tag: root) initial root commit (empty)
```

File *.gitmodules* enthält die URLs der als *git-Module* importierten
Repositories:

```sh
cat .gitmodules
```
```
[submodule ".devcontainer"]
        path = .devcontainer
        url = https://github.com/sgra64/mdse-devcontainer
[submodule ".vscode"]
        path = .vscode
        url = https://github.com/sgra64/mdse-vscode
```


&nbsp;

Testen Sie, dass *git-modules* korrekt importiert wurde:

```sh
git submodule               # list registered sub-modules
```
```
57e1c3a182a596b243a54a56557135e64b6406d1 .devcontainer (heads/main)
e6b048436338f296dd28378db37fb9732c547fe9 .vscode (heads/main)
```

Testen Sie, ob Sie die aktuellen Stände der *git-Module* haben oder
zwischenzeitlich Updates ausgespielt wurden. Das Kommands `git pull`
holt jeweils den aktuellen Stand aus dem Ursprungs-Repository und
spielt ihn in das lokale *git*-Repository ein:

```sh
git submodule foreach git pull
```
```
Entering '.devcontainer'
Already up to date.
Entering '.vscode'
Already up to date.
```

Damit ist die Arbeit auf dem Branch *git-modules* beendet und es kann wieder
auf den *main*-Branch zurückgeschaltet werden:

```sh
git switch main             # switch back to the main branch
```

Die Warnungen beim Umschalten des Branches können ignoriert werden:

```
warning: unable to rmdir '.devcontainer': Directory not empty
warning: unable to rmdir '.vscode': Directory not empty
Switched to branch 'main'
```

The current branch is now *main*:

```sh
git branch                  # show current branch
```
```
  git-modules
* main                      <-- main is the active branch (*)
```

Die importierten Module sowie die Datei *.gitmodules* sind auch auf dem
*main*-Branch vorhanden:

```sh
ls -la
```
```
total 129
drwxr-xr-x 1      0 May 27 12:43 ./
drwxr-xr-x 1      0 May 20 22:13 ../
drwxr-xr-x 1      0 May 27 12:41 .devcontainer/     <-- git-module '.devcontainer'
drwxr-xr-x 1      0 May 27 12:53 .git/
-rw-r--r-- 1    793 May 27 12:41 .gitignore
-rw-r--r-- 1    184 May 27 12:43 .gitmodules        <-- file '.gitmodules'
drwxr-xr-x 1      0 May 27 12:43 .vscode/           <-- git-module '.vscode'
```


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 4. *Devcontainer* Start und Hinzufügen von Quellcode

Nachdem das *git-Module* *.devcontainer* installiert ist, kann der zugehörige
Devcontainer gestartet werden. Dazu muss Docker vorher gestartet werden.
Anschliessend kann man *VSCode* neu starten oder über das Symbol unten links
*"Reopen in Devcontainer"* ausführen.

In einem nächsten Schritt wird aus einem remote Repository Quellcode in das
Projekt geladen.

Dazu muss die URL dieses remote Repositories im lokalen *git*-Projekt registriert
werden:

```sh
# register URL of remote repository to load source code
git remote add mdse-repo https://github.com/sgra64/mdse.git

# show registered remote repositories
git remote -v
```
```
mdse-repo       https://github.com/sgra64/mdse.git (fetch)
mdse-repo       https://github.com/sgra64/mdse.git (push)
```

Als nächstes wird der Inhalt des *main*-Branches aus dem remote Repository
*mdse-repo* geladen:

```sh
# fetch main branch of remote repository 'mdse-repo'
git fetch mdse-repo main
```
```
remote: Enumerating objects: 24, done.
remote: Counting objects: 100% (24/24), done.
remote: Compressing objects: 100% (16/16), done.
remote: Total 24 (delta 5), reused 21 (delta 5), pack-reused 0 (from 0)
Unpacking objects: 100% (24/24), 28.36 KiB | 135.00 KiB/s, done.
From https://github.com/sgra64/mdse
 * branch            main       -> FETCH_HEAD
 * [new branch]      main       -> mdse-repo/main
```

Der neue Branch *"mdse-repo/main"* aus dem remote Repository wird angezeigt:

```sh
# show new remote branch 'mdse-repo/main'
git branch -avv
```

```
  git-modules            f68e4b1 add gitmodule .vscode
* main                   2487442 add .gitignore
  remotes/mdse-repo/main 3a1c857 add README.md      <-- new remote branch 'mdse-repo/main'
```

Aus dem remote Branch kann der Inhalt des darin enthaltenen Verzeichnisses
*"src"* ([`mdse-repo/main -- src`](https://github.com/sgra64/mdse))
in das Projekt *"ausgecheckt"* werden:

```sh
# check-out of folder 'src' into the local project
git checkout mdse-repo/main -- src

# show new folder 'src' in the local project
ls -la
```
```
total 129
drwxr-xr-x 1 svgr2 Kein      0 May 27 12:43 .
drwxr-xr-x 1 svgr2 Kein      0 May 20 22:13 ..
drwxr-xr-x 1 svgr2 Kein      0 May 27 12:41 .devcontainer
drwxr-xr-x 1 svgr2 Kein      0 May 27 13:53 .git
-rw-r--r-- 1 svgr2 Kein    793 May 27 12:41 .gitignore
-rw-r--r-- 1 svgr2 Kein    184 May 27 12:43 .gitmodules
drwxr-xr-x 1 svgr2 Kein      0 May 27 12:43 .vscode
drwxr-xr-x 1 svgr2 Kein      0 May 27 13:53 src             <-- new folder 'src'
```

Man kann den Inhalt des *"src"* Folders anzeigen mit:

```sh
find src                    # show content of folder 'src'
```
```
src
src/demo-b1
src/demo-b1/shape.cpp               <-- demo 'shape' from prior assignment B1
src/include
src/include/collections.h           <-- header files
src/include/collections.tpp
src/main.cpp                        <-- file with main() function
```

Der *git*-Status zeigt die neuen Files bereits als *"staged"* (grün):

```sh
git status                  # show git status
```
```
On branch main
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   src/demo-b1/shape.cpp
        new file:   src/include/collections.h
        new file:   src/include/collections.tpp
        new file:   src/main.cpp
```

Die neuen Dateien können damit direkt committed werden:

```sh
# commit new files with message: "add src"
git commit -m "add src"

# show git-log on the 'main'-branch
git log --oneline
```

Der *git*-Log auf dem  *main*-Branch zeigt das neue Commit:

```
e17f789 (HEAD -> main) add src      <-- new commit for 'src'
2487442 add .gitignore
b72a8af (tag: root) initial root commit (empty)
```


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 5. *Build*-Prozess ausführen

Der *Build*-Prozess führt alle Operationen aus, die *"zum Bau"* eines Projekts
erforderlich sind. Dazu gehört das Übersetzen aller Quell-Files (*".cpp"*) aus
*"src"* in entsprechende *".o"* Files im Verzeichnis *"out"* (noch nicht
vorhanden). Anschliessend wird das ausführbare Programm aus den *".o"* Files
zusammengefügt (*"link"*-Stufe)

Der *Build*-Prozess für C/C++ basiert auf dem *Build-Tool "make"*, welches ein
[*"Makefile"*](Makefile) erfordert. Dieses kann man ebenfalls aus dem remote
Branch *"mdse-repo/main"* auschecken:

```sh
# check-out of folder 'src' into the local project
git checkout mdse-repo/main -- Makefile

# show new 'Makefile' in the local project
ls -la
```
```
total 129
drwxr-xr-x 1 svgr2 Kein      0 May 27 12:43 .
drwxr-xr-x 1 svgr2 Kein      0 May 20 22:13 ..
drwxr-xr-x 1 svgr2 Kein      0 May 27 12:41 .devcontainer
drwxr-xr-x 1 svgr2 Kein      0 May 27 13:53 .git
-rw-r--r-- 1 svgr2 Kein    793 May 27 12:41 .gitignore
-rw-r--r-- 1 svgr2 Kein    184 May 27 12:43 .gitmodules
drwxr-xr-x 1 svgr2 Kein      0 May 27 12:43 .vscode
-rw-r--r-- 1 svgr2 Kein   1797 May 27 14:11 Makefile        <-- new 'Makefile'
drwxr-xr-x 1 svgr2 Kein      0 May 27 13:53 src
```

*"Makefile"* ist nach dem Check-out ebenfalls staged und kann direkt committed
werden:

```sh
# commit new files with message: "add Makefile"
git commit -m "add Makefile"

# show git-log on the 'main'-branch
git log --oneline
```

Der *git*-Log auf dem  *main*-Branch zeigt das neue Commit:

```
76856b1 (HEAD -> main) add Makefile     <-- new commit for 'Makefile'
e17f789 add src
2487442 add .gitignore
b72a8af (tag: root) initial root commit (empty)
```


&nbsp;

Nachdem alle Voraussetzungen für das Projekt gegeben sind, kann das Projekt
im *devcontainer* gebaut werden. Dazu öffnet man ein Terminal im *devcontainer*,
entweder über *VSCode* im Menu: `Terminal -> New Terminal` oder in einem
externen Terminal über Docker:

```sh
container="sad_goodall"         # variable with container name (adjust)

# start shell-process in container and connect to the current terminal
docker exec -it $container /bin/bash
```

Das Projekt kann nun im *devcontainer* Terminal gebaut werden:

```sh
# cd into project, if not already there
cd /workspaces/svgr2/workspaces/mdse/cpp-fun

# show commands (but don't execute)
make -n
```

Die auszuführenden Kommandos zeigen zuerst das Anlegen der Verzeichnisse für
die übersetzten *.o*-Files. Anschliessend übersetzt der Compiler *g++* mit
`-c` (compile) die Files *"src/demo-b1/shape.cpp"* und *"src/main.cpp"* in
entsprechende *.o*-Files im Folder *"out"*.

Im letzten Schritt fügt *g++* mit `-o` (link) die übersetzten *.o*-Files zu
dem ausführbaren Programm `out/main` zusammen (Datei `main` im Folder `out`):

```
mkdir -p out/compiled/ out/compiled/demo-b1/
g++ -I./src/include -c src/demo-b1/shape.cpp -o out/compiled/demo-b1/shape.o
g++ -I./src/include -c src/main.cpp -o out/compiled/main.o
g++ -I./src/include -o out/main out/compiled/demo-b1/shape.o out/compiled/main.o
```

Ausführlicher beschreibt der *Build*-Prozess die folgenden Schritte:

```sh
# create output directories
mkdir -p out/compiled/ out/compiled/demo-b1/

# compile steps
g++ -I./src/include -c src/demo-b1/shape.cpp -o out/compiled/demo-b1/shape.o
g++ -I./src/include -c src/main.cpp -o out/compiled/main.o

# link step
g++ -I./src/include -o out/main out/compiled/demo-b1/shape.o out/compiled/main.o
```

Führen Sie den *Build*-Prozess aus und zeigen Sie die Ergebnisse an:

```sh
# execute build process (no '-n')
make
```

Das Ergebnis befindet sich im Output-Folder `out`. Die Struktur des `src`
Folders bleibt erhalten. Header- oder Template-Files (*.h*, *.tpp* aus
*"src/include"*) werden zum Compilieren benötigt, erzeugen selbst aber keine
*.o*-Files:

```sh
find src out            # show content of the output-folder 'out'
```
```
src
src/demo-b1
src/demo-b1/shape.cpp
src/include
src/include/collections.h
src/include/collections.tpp
src/main.cpp

out
out/compiled                    <-- folder with compiled '.o-files
out/compiled/demo-b1
out/compiled/demo-b1/shape.o
out/compiled/main.o
out/main                        <-- executable programm
```

Das Ergebnis des *Build*-Prozesses, das Programm *"out/main"* kann ausgeführt
werden:

```sh
# launch executable program
out/main
```

Die Ausgaben des ausführbaren Programms:

```
Hello main.cpp
Draw shape example:
Hello, C++ World!
    /|
   / |
  /  |
 /   |
/____|
argv[0] = out/main

Collections example:
nlist:  [4, 3, 2, 2, 2, 1]
nset:   {1, 2, 3}
[4, 3, 2, 2, 2, 1]      --> sum: 14
{1, 2, 3}       --> sum: 6
```

Das [*"Makefile"*](Makefile) diese *Build*-Prozesses enthält neben den klassischen
*compile* und *link* - Regeln fortgeschrittene Fähigkeiten, wie z.B. dynamisch,
d.h. durch Ausführung von Programmen erzeugte Inhalte von Variablen:

```makefile
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Makefile that builds the project.
# - make -n             ; show commands to build the main goal
# - make                ; build the main goal 'out/main'
# - make clean          ; clean-up the project
# - make show_vars      ; show internal variables
# 
# Tutorials and further information:
# - https://gertjanvandenburg.com/files/talk/make.html
# - https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# - https://makefiletutorial.com/
# 
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# 
# make variables:

     OUT := out
    OUTC := $(OUT)/compiled
     SRC := src
 INCLUDE := $(SRC)/include
     CPP := g++ -I./$(INCLUDE)

    SRCS := $(shell find $(SRC) -name '*.cpp')
    OBJS := $(patsubst $(SRC)/%.cpp,$(OUTC)/%.o,$(SRCS))
SRC_DIRS := $(shell find $(SRC) -type d)
OBJ_DIRS := $(sort $(dir $(OBJS)))

# main goal that builds the link goal and the $(OBJ_DIRS) folders
goal: $(OUTC) $(OUT)/main 

# link goal
$(OUT)/main: $(OBJS)
	$(CPP) -o $@ $^

# compile rule
$(OUTC)/%.o: $(SRC)/%.cpp
	$(CPP) -c $< -o $@

clean:
	rm -rf $(OUT)

.PHONY: clean

show_vars:
	@echo "     OUT: $(OUT)"
	@echo "    OUTC: $(OUTC)"
	@echo "     SRC: $(SRC)"
	@echo " INCLUDE: $(INCLUDE)"
	@echo "     CPP: $(CPP)"
	@echo "SRC_DIRS: $(SRC_DIRS)"
	@echo "OBJ_DIRS: $(OBJ_DIRS)"
	@echo "    SRCS: $(SRCS)"
	@echo "    OBJS: $(OBJS)"

$(OUTC):
	mkdir -p $(OBJ_DIRS)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# dependencies (manually maintained):
$(OUTC)/main.o: $(SRC)/main.cpp $(INCLUDE)/collections.h $(INCLUDE)/collections.tpp
$(OUTC)/demo-b1/shape.o: $(SRC)/demo-b1/shape.cpp
```

Die Werte der Variablen können mit dem Goal *show_vars* ausgegebene werden:

```sh
make show_vars              # print values of dynamic variables
```
```
     OUT: out
    OUTC: out/compiled
     SRC: src
 INCLUDE: src/include
     CPP: g++ -I./src/include
SRC_DIRS: src src/demo-b1 src/include
OBJ_DIRS: out/compiled/ out/compiled/demo-b1/
    SRCS: src/demo-b1/shape.cpp src/main.cpp
    OBJS: out/compiled/demo-b1/shape.o out/compiled/main.o
```


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 6. Eigenes *Remote* Repository einrichten

Die aktuelle Situation im lokalen *git*-Repository hat zwei Branches: *main*
und *git-modules*:

```sh
# show commit history of git branches 'main' and 'git-modules'
git log --oneline --graph main git-modules
```
```
* 76856b1 (HEAD -> main) add Makefile
* e17f789 add src
|
| * f68e4b1 (git-modules) add gitmodule .vscode
| * 44b2638 add gitmodule .devcontainer
|/
* 2487442 add .gitignore
* b72a8af (tag: root) initial root commit (empty)
```

Um den *main*-Branch in ein eigenes remote Repository zu übertragen, um ihn
beispielsweise mit anderen Entwicklern zu teilen, können Sie sich in Ihren
Account bei
[*https://gitlab.bht-berlin.de*](https://gitlab.bht-berlin.de)
einloggen und ein neues Projekt mit dem Namem: `cpp-fun` anlegen.

Achten Sie darauf, dass das Projekt **leer** ist und z.B. keine Projektdatei
*"README.md"* mit angelegt wird.

Anschliessend können Sie die URL des neuen Repositories in Ihrem lokalen
Projektverzeichnis unter dem Namen *"origin"* registrieren (der übliche Name
für ein zugeordnetes Remote Repository).

```sh
# register URL of own remote repository under the name 'origin'
git remote add origin <repo-URL>
```

Im nächsten Schritt können Sie den *main*-Branch in das remote Repository
*"pushen"*. Bei einem Push werden alle commits eines Branches in das Ziel-Repository
übertragen.

Das kann zu Konflikten führen - sogenannte
[*"Push-Konflikte"*](https://www.google.com/search?q=Git+was+ist+ein+Push+Konflikt&sca_esv=06b08052a026fa68&sxsrf=ANbL-n6TgGSboboqIFc951fdLr6caEHe0A%3A1779888210365&source=hp&ei=UvAWav3mE8H06AOs8LqpCg&iflsig=AFdpzrgAAAAAahb-YsNxQh2VyoFDFKhS-sTVFreN3wcA&ved=0ahUKEwj915CkyNmUAxVBOnoKHSy4LqUQ4dUDCCM&uact=5&oq=Git+was+ist+ein+Push+Konflikt&gs_lp=Egdnd3Mtd2l6Ih1HaXQgd2FzIGlzdCBlaW4gUHVzaCBLb25mbGlrdDIFECEYoAFI8yVQAFiDJHAAeACQAQCYAZ8BoAHyEqoBBDI2LjO4AQPIAQD4AQGYAh2gAoQUwgIKECMYgAQYigUYJ8ICBBAjGCfCAhAQLhiABBiKBRhDGMcBGNEDwgIKEAAYgAQYigUYQ8ICCBAAGIAEGLEDwgIWEC4YgAQYigUYQxixAxiDARjHARjRA8ICERAuGIAEGLEDGIMBGMcBGNEDwgIQEAAYgAQYigUYQxixAxiDAcICBxAAGIAEGArCAg4QABiABBiKBRixAxiDAcICCxAuGIMBGLEDGIAEwgIMECMYgAQYigUYExgnwgINEAAYgAQYigUYQxixA8ICChAAGIAEGBQYhwLCAgUQABiABMICCBAAGIAEGMsBwgIGEAAYFhgewgIIEAAYFhgeGArCAgUQABjvBcICCBAAGIkFGKIEwgIHECEYChigAZgDAJIHBDI1LjSgB4SHAbIHBDI1LjS4B4QUwgcKMy4xOC43LjAuMcgHXoAIAQ&sclient=gws-wiz) -
wenn z.B. andere vorher Commits auf den Branch gepusht haben, welchen Sie noch
nicht haben. *Git* wird dann einen Fehler melden und auffordern, die fehlenden
Commit *"zu pullen"* mit dem Kommando: `git pull <remote> <branch>`, z.B. `git pull origin main`.

Das kann zu
[*"Merge-Konflikten"*](https://www.google.com/search?q=Git+was+ist+ein+Merge+Konflikt&sca_esv=06b08052a026fa68&biw=1743&bih=1083&sxsrf=ANbL-n47vM7YOHE8_68Uq7Dd_-nWKfGQLQ%3A1779888314455&ei=uvAWaq_DG7CTxc8Pq4eYwAo&ved=0ahUKEwiviOTVyNmUAxWwSfEDHasDBqgQ4dUDCBA&uact=5&oq=Git+was+ist+ein+Merge+Konflikt&gs_lp=Egxnd3Mtd2l6LXNlcnAiHkdpdCB3YXMgaXN0IGVpbiBNZXJnZSBLb25mbGlrdDIIECEYoAEYwwQyCBAhGKABGMMEMggQIRigARjDBDIIECEYoAEYwwRIsCtQggZYwilwBHgBkAEAmAFpoAG3BaoBAzcuMbgBA8gBAPgBAZgCCqACuQTCAgoQABhHGNYEGLADwgIEECMYJ8ICBRAAGO8FwgIIEAAYiQUYogTCAgoQIRgKGKABGMMEmAMAiAYBkAYCkgcDOC4yoAexILIHAzQuMrgHpwTCBwUwLjYuNMgHHYAIAQ&sclient=gws-wiz-serp)
führen, die aufzulösen sind.

Pushen Sie den Branch *main* in Ihr remote Repository.


<!-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

&nbsp;

## 7. Zusammenfassung

Alle Schritte dieser Übung zum Aufbau des Projekts *"cpp-fun"* können in einem
Script zusammengefasst werden:

```sh
git init --initial-branch=main
git commit --allow-empty -m "initial root commit (empty)"
git tag root

curl -o .gitignore https://raw.githubusercontent.com/sgra64/mdse/refs/heads/main/.gitignore
git add .gitignore && git commit -m "add .gitignore"

git switch -c git-modules
git submodule add -f -- https://github.com/sgra64/mdse-devcontainer .devcontainer
git rm --cached .gitmodules
git commit -m "add gitmodule .devcontainer"
# 
git submodule add -f -- https://github.com/sgra64/mdse-vscode .vscode
git rm --cached .gitmodules
git commit -m "add gitmodule .vscode"
#
git switch main

git remote add mdse-repo https://github.com/sgra64/mdse.git
git fetch mdse-repo main
git checkout mdse-repo/main -- src
git commit -m "add src"
# 
git checkout mdse-repo/main -- Makefile
git commit -m "add Makefile"

make -n
```



<!-- 
The expected result is shown in the right figure.

<table>
<td valign="top">
<img src="https://raw.githubusercontent.com/sgra64/se1-play/refs/heads/markup/img/final-test-build.png" width="360"/>
</td>
<td valign="top">
<img src="https://raw.githubusercontent.com/sgra64/se1-play/refs/heads/markup/img/final-test-struct.png" width="360"/>
</td>
</table>


Open *VSCode* and show the program and tests also run properly in the IDE:

<img src="https://raw.githubusercontent.com/sgra64/se1-play/refs/heads/markup/img/final-test-vscode.png" width="720"/>
 -->
