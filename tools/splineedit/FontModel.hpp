#ifndef FONTMODEL_HPP
#define FONTMODEL_HPP

#include <QAbstractItemModel>

class FontModel : public QAbstractItemModel
{
public:
    FontModel(QObject *parent = nullptr);
    virtual ~FontModel();
    
    
};

#endif
