#ifndef GLYPH_H
#define GLYPH_H

#include <QChar>
#include <QList>
#include <QPointF>

class Glyph
{
public:
    Glyph(QChar ordinal);
    virtual ~Glyph() = default;
    
    QVariant numberOfQuadraticControls();
    QVariant numberOfCubicControls();
    
    QChar m_ordinal;
    QList<QPointF> m_quadratic_controls, m_cubic_controls;
};

#endif
