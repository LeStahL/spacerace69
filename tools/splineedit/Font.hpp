#ifndef FONT_HPP
#define FONT_HPP

#include <QString>
#include <QList>
#include <QPainterPath>

class Font
{
public:
    Font(QString name);
    
    bool addGlyph(QChar ordinal);
    bool removeGlyph(QChar ordinal);
    
    QList<QChar> m_glyphs;
    QList<QPainterPath> m_painter_paths;
};

#endif
