// SPDX-FileCopyrightText: 2023 Devin Lin <devin@kde.org>
// SPDX-License-Identifier: LGPL-2.0-or-later

#include <QApplication>
#include <QCommandLineParser>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QString>

#include <KAboutData>
#include <KLocalizedString>

#include "settings.h"
#include "version.h"
#include "wizard.h"

QCommandLineParser *createParser()
{
    QCommandLineParser *parser = new QCommandLineParser;
    parser->addOption(QCommandLineOption(QStringLiteral("test-wizard"), i18n("Opens the initial start wizard without modifying configuration")));
    parser->addVersionOption();
    parser->addHelpOption();
    return parser;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // parse command
    QScopedPointer<QCommandLineParser> parser{createParser()};
    parser->process(app);

    bool testWizard = parser->isSet(QStringLiteral("test-wizard"));

    if (!testWizard) {
        // if the wizard has already been run, or we aren't in plasma mobile
        if (!Settings::self()->shouldStartWizard()) {
            qDebug() << "Wizard will not be started since either it has already been run, or the current session is not Plasma Mobile.";
            return 0;
        }
    }

    // start wizard
    KLocalizedString::setApplicationDomain("plasma-mobile-initial-start");
    KAboutData aboutData(QStringLiteral("plasma-mobile-initial-start"),
                         QStringLiteral("Initial Start"),
                         QStringLiteral(PLASMA_MOBILE_VERSION_STRING),
                         QStringLiteral(""),
                         KAboutLicense::GPL,
                         i18n("© 2023 KDE Community"));
    aboutData.addAuthor(i18n("Devin Lin"), QString(), QStringLiteral("devin@kde.org"));
    KAboutData::setApplicationData(aboutData);

    QQmlApplicationEngine *engine = new QQmlApplicationEngine;
    engine->rootContext()->setContextObject(new KLocalizedContext{engine});

    Wizard *wizard = new Wizard{nullptr, engine};
    wizard->setTestingMode(testWizard);
    wizard->load();

    qmlRegisterSingletonType<Wizard>("initialstart", 1, 0, "Wizard", [wizard](QQmlEngine *, QJSEngine *) -> QObject * {
        return wizard;
    });

    engine->load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    app.setWindowIcon(QIcon::fromTheme(QStringLiteral("start-here-symbolic")));

    return app.exec();
}