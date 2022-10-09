/*
    SPDX-FileCopyrightText: KDE Developers

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KATEVI_HISTORY_H
#define KATEVI_HISTORY_H

#include <QStringList>
#include <ktexteditor_export.h>

namespace KateVi
{
class KTEXTEDITOR_EXPORT History
{
public:
    explicit History() = default;
    ~History() = default;

    void append(const QString &historyItem);
    inline const QStringList &items() const
    {
        return m_items;
    }
    void clear();
    inline bool isEmpty()
    {
        return m_items.isEmpty();
    }

private:
    QStringList m_items;
};
}

#endif // KATEVI_HISTORY_H
