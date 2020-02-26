#include "Glyph.hpp"

Glyph::Glyph(QChar ordinal)
    : m_ordinal(ordinal)
{
}

QVariant Glyph::numberOfCubicControls()
{
    return QVariant(m_cubic_controls.size());
}

int Glyph::numberOfQuadraticControls()
{
    return QVariant(m_cubic_controls.size());
}
