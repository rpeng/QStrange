#ifndef STRANGESPINNER_H
#define STRANGESPINNER_H

#include <QDoubleSpinBox>

class StrangeSpinner : public QDoubleSpinBox
{
    Q_OBJECT

signals:
    void updateGenerator(); // tells generator to update its values

public slots:
    void syncValue(int value);

public:
    StrangeSpinner(QWidget *);
    ~StrangeSpinner();
};

#endif // STRANGESPINNER_H
