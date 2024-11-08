<!--
- SPDX-FileCopyrightText: None
- SPDX-License-Identifier: CC0-1.0
-->

# Glide UI 

This repository contains shell components for Glide UI base on Plasma Mobile.




<img src="/screenshots/homescreen-folio.png" width=300px/>
<img src="/screenshots/homescreen-halcyon.png" width=300px/>

### Test on a development machine

See the [documentation page](https://invent.kde.org/plasma/plasma-mobile/-/wikis/Building-and-Testing-Locally) for more details.

It is recommended to use `kdesrc-build` to build this from source. See [this page](https://community.kde.org/Get_Involved/development) in order to set it up.

Dependencies:
* KDE Frameworks 6 setup (plasma-framework and its dependencies)
* plasma-nano
* plasma-workspace
* plasma-nm
* plasma-pa
* bluez-qt
* Milou (for search)
* Kirigami
* Kirigami Addons
* hfd-service (optional: for vibrations)

To start the shell in a window, run:

```
QT_QPA_PLATFORM=wayland dbus-run-session kwin_wayland --xwayland "plasmashell -p org.kde.plasma.mobileshell"
```

Useful options:
- Specify the `--output-count` flag for the number of displays
- Specify `--width` and `--height` for the window size

```
QT_QPA_PLATFORM=wayland dbus-run-session kwin_wayland --xwayland "plasmashell -p org.kde.plasma.mobileshell" --output-count 2 --width 360 --height 720
```

---

<img src="https://invent.kde.org/plasma/plasma-mobile/-/wikis/uploads/19a607bb68faa76bbc9f888e33a3aa9a/konqi-calling.png" width=200px>

<br/>

<img src="https://invent.kde.org/plasma/plasma-mobile/-/wikis/uploads/9238173a7cae1d8832d83350eda74f85/developers.png" width=300px>
