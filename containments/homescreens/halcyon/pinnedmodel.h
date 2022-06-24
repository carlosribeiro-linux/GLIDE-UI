// SPDX-FileCopyrightText: 2022 Devin Lin <devin@kde.org>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "application.h"
#include "applicationfolder.h"

#include <QAbstractListModel>
#include <QList>
#include <QObject>
#include <QQuickItem>
#include <QSet>

#include <Plasma/Applet>

#include <KWayland/Client/connection_thread.h>
#include <KWayland/Client/plasmawindowmanagement.h>
#include <KWayland/Client/registry.h>
#include <KWayland/Client/surface.h>

/**
 * @short The applications and folders model on the main page.
 */
class PinnedModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles { IsFolderRole = Qt::UserRole + 1, ApplicationRole, FolderRole };

    PinnedModel(QObject *parent = nullptr, Plasma::Applet *applet = nullptr);
    ~PinnedModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addApp(const QString &storageId, int row);
    Q_INVOKABLE void removeApp(int row);
    Q_INVOKABLE void addFolder(QString name, int row);
    Q_INVOKABLE void removeFolder(int row);

    Q_INVOKABLE void load();
    void save();

private:
    QList<Application *> m_applications;
    QList<ApplicationFolder *> m_folders;

    Plasma::Applet *m_applet;
};