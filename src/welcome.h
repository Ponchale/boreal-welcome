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

#ifndef WELCOME_H
#define WELCOME_H

#include <QDBusInterface>
#include <QGuiApplication>
#include <QObject>
#include <QTranslator>

class Welcome : public QObject {
    Q_OBJECT
public:
    Welcome(QGuiApplication* app);
    Q_INVOKABLE void startWelcome();
    Q_INVOKABLE void endWelcome();
    Q_INVOKABLE bool isFirstRun();

    QTranslator* getTranslator() { return mTranslator; }
    Q_INVOKABLE void setLanguage(QString language);

private:
    bool m_needToStart;
    QDBusInterface* m_mceDbus;
    QTranslator* mTranslator;
};

#endif // WELCOME_H
