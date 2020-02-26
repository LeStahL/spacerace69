#ifndef FONT_HPP
#define FONT_HPP

#include <QChar>
#include <QString>
#include <QList>

#include "Glyph.hpp"

class Font
{
public:
    Font();
    virtual ~Font() = default;
    
    QList<Glyph *> m_glyphs;
};

#endif
