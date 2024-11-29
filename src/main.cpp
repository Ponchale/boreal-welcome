/*
 * Copyright (C) 2022 Chupligin Sergey <neochapay@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <QScreen>
#include <QtGui/QGuiApplication>
#include <QtQml>
#include <QtQuick/QQuickView>
#include <borealapp.h>

#include "welcome.h"

Q_DECL_EXPORT int main(int argc, char* argv[])
{
    QGuiApplication* app = BorealApp::app(argc, argv);
    app->setOrganizationName("Astian_OS");

    Welcome* welcome = new Welcome(app);
    QTranslator* welcomeTranslator = welcome->getTranslator();

    QScreen* sc = app->primaryScreen();
    if (sc) {
        sc->setOrientationUpdateMask(Qt::LandscapeOrientation
            | Qt::PortraitOrientation
            | Qt::InvertedLandscapeOrientation
            | Qt::InvertedPortraitOrientation);
    }

    QQmlApplicationEngine engine = BorealApp::engine();
    engine.rootContext()->setContextProperty("welcome", welcome);

    QQuickWindow* window = BorealApp::showWindow();
    window->setTitle(QObject::tr("Welcome"));
    return app->exec();
}
