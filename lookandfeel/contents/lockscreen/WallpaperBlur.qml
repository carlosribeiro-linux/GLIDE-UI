/*
 * SPDX-FileCopyrightText: 2021-2022 Devin Lin <devin@kde.org>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

import QtQuick
import QtQuick.Effects

MultiEffect {
    autoPaddingEnabled: false
    blurEnabled: true
    blurMax: 50
    blur: 1.0
    
    property bool shouldBlur
    opacity: shouldBlur ? 1 : 0
    
    Behavior on opacity {
        NumberAnimation {
            duration: 1000
            easing.type: Easing.InOutQuad
        }
    }
}
