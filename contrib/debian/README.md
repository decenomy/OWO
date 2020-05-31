
Debian
====================
This directory contains files used to package OneWorldd/OneWorld-qt
for Debian-based Linux systems. If you compile OneWorldd/OneWorld-qt yourself, there are some useful files here.

## OneWorld: URI support ##


OneWorld-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install OneWorld-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your OneWorld-qt binary to `/usr/bin`
and the `../../share/pixmaps/OneWorld128.png` to `/usr/share/pixmaps`

OneWorld-qt.protocol (KDE)

