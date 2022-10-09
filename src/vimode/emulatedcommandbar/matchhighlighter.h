/*
    SPDX-FileCopyrightText: 2013-2016 Simon St James <kdedevel@etotheipiplusone.com>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KATEVI_EMULATED_COMMAND_BAR_MATCHHIGHLIGHTER_H
#define KATEVI_EMULATED_COMMAND_BAR_MATCHHIGHLIGHTER_H

#include <ktexteditor/attribute.h>

#include <QObject>

namespace KTextEditor
{
class ViewPrivate;
class Range;
class MovingRange;
}

namespace KateVi
{
class MatchHighlighter : public QObject
{
    Q_OBJECT
public:
    explicit MatchHighlighter(KTextEditor::ViewPrivate *view);
    ~MatchHighlighter();
    void updateMatchHighlight(const KTextEditor::Range &matchRange);
private Q_SLOTS:
    void updateMatchHighlightAttrib();

private:
    KTextEditor::ViewPrivate *m_view = nullptr;
    KTextEditor::Attribute::Ptr m_highlightMatchAttribute;
    KTextEditor::MovingRange *m_highlightedMatch;
};
}
#endif
