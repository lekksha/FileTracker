#ifndef OUTPUT_H
#define OUTPUT_H

#include <QObject>

class Output : public QObject
{
    Q_OBJECT
public:
    explicit Output(QObject *parent = nullptr);

signals:

};

#endif // OUTPUT_H
