#ifndef OUTPUT_H
#define OUTPUT_H

class Output
{
    Q_OBJECT
public:
    Output();
public slots:
    onFileChanged();    // Потом лучше заменить с Changed на Updated
    onFileCreated();
    onFileDeleted();

};

#endif // OUTPUT_H
