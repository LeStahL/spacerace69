#include "FontModel.hpp"

FontModel::FontModel(Font *font, QObject* parent)
    : QAbstractTableModel(parent)
    , m_font(font)
{
    if(font == nullptr) m_font = new Font;
}

int FontModel::rowCount(const QModelIndex& parent) const
{
    return m_font->m_glyphs.size();
}

int FontModel::columnCount(const QModelIndex& parent) const
{
    return 3;
}

QVariant FontModel::data(const QModelIndex& index, int role) const
{
    if(role == Qt::DisplayRole)
    {
        Glyph *glyph = m_font->m_glyphs.at(index.row());
        if(index.column() == 0) return QVariant(glyph->m_ordinal);
        else if(index.column() == 1) return glyph->numberOfQuadraticControls();
        else if(index.column() == 2) return glyph->numberOfCubicControls();
    }
    return QVariant();
}

QVariant FontModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            if(section == 0) return QVariant("Ordinal");
            else if(section == 1) return QVariant("#Quads");
            else if(section == 2) return QVariant("#Cubics");
        }
    }
    return QVariant();
}
